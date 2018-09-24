#include <stdio.h>
#include <unistd.h>

static int condition = 1;

static void user_thread_1()
{
    static int __sa = 0;
    switch (__sa) {
    case 0:;
        for (;;) {
            printf("Run %s\n", __FUNCTION__);
            {
                __sa = 29;
                usleep(500);
                return;
            case 29:;
            };
        }
    }
    __sa = 0;
    ;
}

static void user_thread_2()
{
    static int __s = 0;
    switch (__s) {
    case 0:;
        for (;;) {
            if (condition) {
                printf("Run %s - (1)\n", __FUNCTION__);
                {
                    __s = 42;
                    usleep(500);
                    return;
                case 42:;
                };
            }
            printf("Run %s - (2)\n", __FUNCTION__);
            condition = !condition;
            {
                __s = 48;
                usleep(500);
                return;
            case 48:;
            };
        }
    }
    __s = 0;
    ;
}

int main()
{
    for (;;) {
        user_thread_1();
        user_thread_2();
    }
    return 0;
}
