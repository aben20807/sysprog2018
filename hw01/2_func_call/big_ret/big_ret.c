#include <stdio.h>

typedef struct {
    int a[8]; // change the array size
} Big;

Big get_big()
{
    Big ret = {};
    return ret;
}

int main(){

    Big b = get_big();
    printf("%ld\n", sizeof(b));
    return 0;
}
