#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
    int fd = open("my.txt", O_RDWR);
    int fd2 = open("my2.txt", O_RDWR);
    if (fd == -1 || fd2 == -1) {
        perror("open"); // reads errno
        return -1;
    }
    printf("file opened, fd = %d\n", fd); // 3
    printf("file opened, fd2 = %d\n", fd2); // 4
    close(fd);
    close(fd2);
    return 0;
}
