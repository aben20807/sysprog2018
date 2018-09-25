#include <stdio.h>
#include <stdlib.h>

typedef struct {int a; double b;} Foo;

int main() {
    Foo *p = (Foo *) malloc(sizeof(Foo));
    p->a = 100;
    p->b = 3.14;
    printf("%p(size: %ld) -> (%d, %lf)\n", p, sizeof(*p), p->a, p->b);
    free(p);
    printf("%p(size: %ld) -> (%d, %lf)\n", p, sizeof(*p), p->a, p->b);
    free(p);
    printf("%p(size: %ld) -> (%d, %lf)\n", p, sizeof(*p), p->a, p->b);
    free(p);
    printf("%p(size: %ld) -> (%d, %lf)\n", p, sizeof(*p), p->a, p->b);
    free(p);
    p->a = 200;
    p->b = 6.28;
    printf("%p(size: %ld) -> (%d, %lf)\n", p, sizeof(*p), p->a, p->b);
    return 0;
}
