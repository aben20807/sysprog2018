#include <stdio.h>

int main(int argc, char *argv[]){

    int a[3] = {5, 6, 7};
    printf("%d %d\n", a[1], *(a + 1));
    return 0;
}
