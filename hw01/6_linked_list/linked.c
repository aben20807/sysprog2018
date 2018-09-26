#include <stdio.h>
#include <stdlib.h>

typedef struct _Node Node;
struct _Node{
    int x;
    // double d[100];
    Node *nxt;
};

Node *create_node(int x) {
    Node *ret = (Node *)malloc(sizeof(Node));
    ret->x = x;
    ret->nxt = NULL;
    return ret;
}

int main(int argc, char *argv[]){

    Node *n0 = create_node(0);
    Node *n1 = create_node(1);
    Node *n2 = create_node(2);
    Node *n3 = create_node(3);
    n0->nxt = n1;
    n1->nxt = n2;
    n2->nxt = n3;
    printf("%d\n", n0->x);
    printf("%d\n", n0->nxt->x);
    printf("%d\n", n0->nxt->nxt->nxt->x);
    return 0;
}
