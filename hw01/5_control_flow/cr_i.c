#include <stdio.h>
#include <unistd.h>

#define THREAD_INTERVAL 500
#define cr_start()      \
    static int __s = 0; \
    switch (__s) {      \
    case 0:

#define cr_yield                 \
    {                            \
        __s = __LINE__;          \
        usleep(THREAD_INTERVAL); \
        return;                  \
    case __LINE__:;              \
    }
#define cr_end() \
    }            \
    __s = 0;

static int condition = 1;

static void user_thread_1(int arg) {
    static int i = 0;
    cr_start();
    for (; i < 5; i++) {
        printf("%d:%d: Run %s\n", arg, i, __FUNCTION__);
        cr_yield;
    }
    cr_end();
}

static void user_thread_2(int arg) {
    static int i = 0;
    cr_start();
    for (; i < 5; i++) {
        if (condition) {
            printf("%d:%d: Run %s - (1)\n", arg, i, __FUNCTION__);
            cr_yield;
        }
        printf("%d:%d: Run %s - (2)\n", arg, i, __FUNCTION__);
        condition = !condition;
        cr_yield;
    }
    cr_end();
}

int main() {
    for (int j = 0; j < 20; j++) {
        user_thread_1(j);
        user_thread_2(j);
    }
    return 0;
}
