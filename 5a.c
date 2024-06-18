#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <utime.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *source_file = argv[1];
    const char *destination_file = argv[2];
    struct stat source_stat;

    // Get the access and modification times of the source file
stat(source_file,&source_stat);

    // Apply the access and modification times to the destination file
struct utimbuf new;
new.actime=source_stat.st_atime;
new.modtime=source_stat.st_mtime;

utime(destination_file,&new);
    printf("Access and modification times copied from %s to %s\n", source_file, destination_file);

    return 0;
}

