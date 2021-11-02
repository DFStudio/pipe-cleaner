#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char** argv)
{
    for(int i = 1; i < argc; i++) {
        int fd = open(argv[i], O_WRONLY | O_NONBLOCK);

        if (fd == -1) {
            if(errno == ENXIO) {
                printf("%s: no reader\n", argv[i]);
            } else {
                printf("%s: open failed\n", argv[i]);
            }
        } else {
            printf("%s: successfully opened\n", argv[i]);
            close(fd);
        }

        fd = open(argv[i], O_RDONLY | O_NONBLOCK);

        if (fd == -1) {
            if(errno == ENXIO) {
                printf("%s: no writer\n", argv[i]);
            } else {
                printf("%s: open failed\n", argv[i]);
            }
        } else {
            printf("%s: successfully opened\n", argv[i]);
            close(fd);
        }
    }
}