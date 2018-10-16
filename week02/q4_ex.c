#include <stdio.h>
#include <stdlib.h>

typedef struct _A { int data; } A;
typedef struct _B { A *a; } B;


void freeb_wrong(B *b)
{
    free(b->a);
    free(b);
    b = NULL;
}

void freeb(B **p_b)
{
    B *b = *p_b;
    *p_b = NULL;
    free(b->a);
    free(b);
}

int main()
{
    B *b1 = malloc(sizeof(B));
    b1->a = malloc(sizeof(A));
    printf("%p\n", b1);
    freeb_wrong(b1);
    printf("%p\n\n", b1);

    B *b2 = malloc(sizeof(B));
    b2->a = malloc(sizeof(A));
    printf("%p\n", b2);
    freeb(&b2);
    printf("%p\n", b2);
    return 0;
}
