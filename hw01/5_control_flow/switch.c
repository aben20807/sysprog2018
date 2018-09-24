#include <stdio.h>
#define DEBUG 0
#define DBG( ... ) \
    if (DEBUG) {  __VA_ARGS__; }
int main(int argc, char *argv[]) {
    char *num;
    switch (argc - 1) {
             case  0: num =  "zero";
        DBG( case  1: num =   "one"; )
        DBG( case  2: num =   "two"; )
        DBG( case  3: num = "three"; )
        DBG( default: num =  "many"; )
        while (--argc)
            printf("%s ", argv[argc]);
        printf("\nArgument count: %s\n", num);
        break;
    }
    return 0;
}
