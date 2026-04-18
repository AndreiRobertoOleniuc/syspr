#include <assert.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open"); // reads errno
        return -1;
    }

    int n = 32;
    char buf[n]; // allocated on stack
    ssize_t r = read(fd, buf, n); // returns number of bytes read, or -1 on error, or 0 on end of file
    while (r > 0) {
        write(STDOUT_FILENO, buf, r); // writes to STDOUT_FILENO, which is 1 and takes in the buffer and the number of bytes to write
        r = read(fd, buf, n); // read the next chunk of data
    }
    if (r == -1) {
        perror("read"); // reads errno
        return -1;
    } else {
        assert(r == 0); // end of file
    }

    close(fd);
    return 0;
}
