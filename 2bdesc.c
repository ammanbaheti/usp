#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include<string.h>
int main() {
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    printf("File descriptor: %d\n", fd);
getchar();
    // Further operations with fd...

 // Close the file descriptor when done
    return 0;
}

