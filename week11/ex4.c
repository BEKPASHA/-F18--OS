#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd1 = open("ex1.txt", O_RDWR);
    int fd2 = open("ex1.memcpy.txt", O_RDWR);

    struct stat stat1;
    struct stat stat2;

    stat("ex1.txt", &stat1);
    stat("ex1.memcpy.txt", &stat2);
    int size1 = stat1.st_size;
    int size2 = stat2.st_size;

    char *file1 = mmap(NULL, size1, PROT_READ | PROT_WRITE, MAP_SHARED, fd1, 0);
    char *file2 = mmap(NULL, size2, PROT_READ | PROT_WRITE, MAP_SHARED, fd2, 0);

    memcpy(file2, file1, size1);
    msync(file2, size1, MS_SYNC);
    munmap(file1, size1);
    munmap(file2, size2);

    close(fd1);
    close(fd2);

    return 0;
}
