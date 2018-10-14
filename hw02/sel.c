#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);
    int ret;
    char buf[256] = {0};
    struct timeval tv = {5, 0};
    struct timeval tv0 = {0, 0};
    // ret = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &tv0);
    ret = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &tv);
    // ret = select(STDIN_FILENO + 1, &readfds, NULL, NULL, NULL);
    // while (1) {
    printf("ret = %d\n", ret);
    if (ret == -1) {
        perror("select error");
        exit(EXIT_FAILURE);
    } else if (ret) {
        if (FD_ISSET(STDIN_FILENO, &readfds)) {
            read(STDIN_FILENO, buf, 256);
            printf("readfrom stdin msg : %s\n", buf);
        }
    } else {
        printf("timeout\n");
    }
    printf("OuO\n");
    // }
    return 0;
}
