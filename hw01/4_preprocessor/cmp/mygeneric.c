#include <stdio.h>

#define foo(X) \
    _Generic((X), \
            int: foo_i, \
            float: foo_f  \
            )(X)

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
    foo(a);
    float c = 3.0;
    foo(c);
}
