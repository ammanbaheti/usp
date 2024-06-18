

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void printFlags (int flags) {
        if (flags & O_RDONLY) printf("O_RDONLY");
        if (flags & O_WRONLY) printf("O_WRONLY");
        if (flags & O_RDWR) printf("O_RDWR");
        if (flags & O_APPEND) printf("O_APPEND");
        printf("\n");
}

int main(int argc, char *argv[]) {
        int fd, flags;

        if (argc != 2) {
                fprintf(stderr, "Usage: %s <filedesc>\n", argv[0]);
                exit(EXIT_FAILURE);
        }

        fd = atoi(argv[1]);
        flags = fcntl(fd, F_GETFL);
        if (flags == -1) {
                perror("fcntl()");
                exit(EXIT_FAILURE);
        }
        printFlags(flags);

        return 0;
}
