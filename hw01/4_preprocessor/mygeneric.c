#include <stdio.h>

#define foo(X) \
    _Generic((X), \
            const int: foo_ci, \
            int: foo_i, \
            float: foo_f,  \
            const float: foo_cf \
            )(X)

void foo_i(int x)
{
    printf("int: %d\n", x);
}

void foo_ci(const int x)
{
    printf("const int: %d\n", x);
}

void foo_f(float x)
{
    printf("float: %f\n", x);
}

void foo_cf(const float x)
{
    printf("const float: %f\n", x);
}

int main(void) {
    int a = 1;
    foo(a);
    const int b = 2;
    foo(b);
    float c = 3.0;
    foo(c);
    const float d = 4.0;
    foo(d);
}
