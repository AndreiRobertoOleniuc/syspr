#define _XOPEN_SOURCE 500

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

//int ftruncate(int fildes, off_t length);

void error(char *fun_name) {
    printf("%s: error no %d\n", fun_name, errno);
    exit(-1);
}

int main(void) {
    int fd = open("truncate.txt", O_RDWR|O_CREAT, S_IRUSR|S_IWUSR);
    if (fd == -1) {
        error("open");
    }
    int w, i = 0;
    char buf[] = {'x'};
    while (i < 32) {
        w = write(fd, buf, 3);
        if (w == -1) {
            error("write");
        }
        i++;
    }
    int result = ftruncate(fd, 10); // -rw------- 1 debian debian    10 (Size in bytes) Apr 18 21:18 truncate.txt
    if (result == -1) {
        error("ftruncate");
    }
}
