#include <stdio.h>

void foo_i(int x)
{
    printf("int: %d\n", x);
}

void foo_f(float x)
{
    printf("float: %f\n", x);
}

int main(void) {
    int a = 1;
    foo_i(a);
    float c = 3.0;
    foo_f(c);
}
