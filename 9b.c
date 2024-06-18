#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int fd;
    char buffer[21]; // Extra byte for null terminator
    ssize_t bytes_read;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("Failed to open file");
        return 1;
    }

    if (lseek(fd, 10, SEEK_SET) < 0) {
        perror("Lseek failed");
        close(fd);
        return 1;
    }

    bytes_read = read(fd, buffer, 20);
    if (bytes_read < 0) {
        perror("Read failed");
        close(fd);
        return 1;
    } else {
        buffer[bytes_read] = '\0'; // Null-terminate the buffer
        puts(buffer);
    }

    printf("\n");

    if (lseek(fd, 10, SEEK_CUR) < 0) {
        perror("Lseek failed");
        close(fd);
        return 1;
    }

    bytes_read = read(fd, buffer, 20);
    if (bytes_read < 0) {
        perror("Read failed");
        close(fd);
        return 1;
    } else {
        buffer[bytes_read] = '\0'; // Null-terminate the buffer
        puts(buffer);
    }

    off_t file_size = lseek(fd, 0, SEEK_END);
    if (file_size < 0) {
        perror("Failed to get file size");
        close(fd);
        return 1;
    }

    printf("SIZE: %ld\n", (long)file_size);
    close(fd);
    return 0;
}

