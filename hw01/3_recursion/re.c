#include <stdio.h>
int p(int i, int N) {
    return (i < N && printf("%d\n", i) && !p(i + 1, N))
           || printf("%d\n", i);
}
int main () {
    return p(1, 5);
}
