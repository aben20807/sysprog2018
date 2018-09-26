#include <stdio.h>
typedef struct { int i; } A;
typedef struct { double j; } B;
typedef int (*BarFunc)(int param);
#define foo(X) \
    _Generic((X), \
        A: foo_a, \
        B: foo_b, \
        int (*)[3]: foo_ia ,\
        BarFunc: foo_bar \
    )(X)

void foo_a(A a)
{
    printf("A: %d\n", a.i);
}

void foo_b(B b)
{
    printf("B: %lf\n", b.j);
}

void foo_ia(int (*a)[3])
{
    printf("array: %d, %d, %d\n", (*a)[0], (*a)[1], (*a)[2]);
}

void foo_bar(BarFunc cb)
{
    cb(999);
}

int bar(int a)
{
    printf("bar: %d\n", a);
    return a;
}

int main(){
    A a = {.i = 3};
    foo(a);
    B b = {.j = 3.14};
    foo(b);
    int ia[3] = {4, 5, 6};
    foo(&ia);
    foo(bar);
    return 0;
}
