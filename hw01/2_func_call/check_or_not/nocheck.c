#include <stdio.h>

void do_print(int *ptr)
{
    printf("%d\n", *ptr);
}

void do_A_print_B(int *ptr)
{
    *ptr += 3;
    do_print(ptr);
    *ptr += 4;
}

int main(){

    int a = 3;
    int *a_ptr = &a;
    do_print(a_ptr);
    do_A_print_B(a_ptr);
    do_print(a_ptr);
    return 0;
}
