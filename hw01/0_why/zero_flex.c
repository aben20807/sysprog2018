#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int arr[];
} Foo;

typedef struct {
    int x;
    int arr[0];
} Bar;

int main(){
    printf("sizeof(Foo):\t%ld\n", sizeof(Foo));
    static Foo f = {1, {2, 3}};
    printf("sizeof(f):\t%ld\n", sizeof(f));
    printf("f.x:\t\t%d\n", f.x);
    printf("f.arr[0]:\t%d\n", f.arr[0]);
    printf("f.arr[1]:\t%d\n", f.arr[1]);
    printf("-------------------\n");
    Foo *ptrf = (Foo *)malloc(sizeof(Foo) + 2 * sizeof(int));
    ptrf->arr[0] = 22;
    ptrf->arr[1] = 33;
    printf("sizeof(ptrf):\t%ld\n", sizeof(*ptrf));
    printf("ptrf->arr[0]:\t%d\n", ptrf->arr[0]);
    printf("ptrf->arr[1]:\t%d\n", ptrf->arr[1]);
    printf("-------------------\n");
    printf("sizeof(Bar):\t%ld\n", sizeof(Bar));
    Bar b = {7, {8, 9}};
    printf("sizeof(b):\t%ld\n", sizeof(b));
    printf("b.x:\t\t%d\n", b.x);
    printf("b.arr[0]:\t%d\n", b.arr[0]);
    printf("b.arr[1]:\t%d\n", b.arr[1]);
    printf("-------------------\n");
    Bar *ptrb = (Bar *)malloc(sizeof(Bar) + 2 * sizeof(int));
    ptrb->arr[0] = 8;
    ptrb->arr[1] = 9;
    printf("sizeof(*ptrb):\t%ld\n", sizeof(*ptrb));
    printf("ptrb->arr[0]:\t%d\n", ptrb->arr[0]);
    printf("ptrb->arr[1]:\t%d\n", ptrb->arr[1]);

    // printf("-------------------\n");
    // Bar ano_b = {77};
    // ano_b.arr[0] = 88;
    // ano_b.arr[1] = 99;
    // printf("ano_b.arr[0]:\t%d\n", ano_b.arr[0]);
    // printf("ano_b.arr[1]:\t%d\n", ano_b.arr[1]);
    return 0;
}
