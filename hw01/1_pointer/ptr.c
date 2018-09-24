#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[]){

    int a = 9;
    int *ptr = &a;
    printf("%d", a);
    *ptr = 2;
    printf("%d", a);
    return 0;
}
