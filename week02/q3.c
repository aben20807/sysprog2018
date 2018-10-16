#include <stdio.h>
typedef struct _A { int data; } A;

#define pdata(x) \
    printf("%d\n", (x)->data);

int main() {
    A a = { .data = 123 };
    pdata(&a);
    return 0;
}
