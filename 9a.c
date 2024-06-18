#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
int main() {
    mode_t old_mask;

    // Get the current umask value
    old_mask = umask(0);  // Set mask to 0 to get the current value
    printf("Old umask: %o\n", old_mask);

    // Set a new umask to restrict write permissions for others during file creation
    mode_t new_mask = 002;  // Octal representation: rw-r-r-
    umask(new_mask);
    printf("New umask: %o\n", new_mask);

    // Create a new file with restricted write permissions for others
    int fd = open("test_file.txt", O_CREAT | O_WRONLY, 0);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Close the file
    close(fd);

    // Get file permissions using stat
    struct stat statbuf;
    if (stat("test_file.txt", &statbuf) == -1) {
        perror("stat");
        return 1;
    }

    // Print initial file permissions in octal format
    printf("Initial file permissions: %o\n", statbuf.st_mode & 0777);

    // Change file permissions to rw-rw-rw- using chmod
    if (chmod("test_file.txt", 0666) == -1) {
        perror("chmod");
        return 1;
    }

    // Get file permissions again after chmod
    if (stat("test_file.txt", &statbuf) == -1) {
        perror("stat");
        return 1;
    }
    printf("File permissions after chmod: %o\n", statbuf.st_mode & 0777);

    // Remove the test file
    if (remove("test_file.txt") == -1) {
        perror("remove");
        return 1;
    }

    return 0;
}

