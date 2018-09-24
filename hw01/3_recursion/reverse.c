#include <stdio.h>
int cnt1 = 0;
int cnt2 = 0;

static inline void swap(char *a, char *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

char *reverse1(char *s) {
    cnt1++;
    if ((*s == '\0') || (*(s + 1) == '\0'))
        return NULL;

    reverse1(s + 1);
    swap(s, (s + 1));
    // printf("%c, %c\n", *s, *(s+1));

    if (*(s + 2) != '\0')
        reverse1(s + 2);

    reverse1(s + 1);
    return s;
}

int rev_core(char *head, int idx) {
    cnt2++;
    if (head[idx] != '\0') {
        int end = rev_core(head, idx + 1);
        if (idx > end / 2) {
            swap(head + idx, head + end - idx);
            // printf("%c, %c\n", *(head + idx), *(head + end - idx));
        }
        return end;
    }
    return idx - 1;
}
char *reverse2(char *s) {
    rev_core(s, 0);
    return s;
}

int main(){
    char s1[12] = "abcdefghij";
    printf("%s\n", s1);
    char *r1 = reverse1(s1);
    printf("%s\n", r1);
    printf("%d\n", cnt1);

    char s2[12] = "abcdefghij";
    printf("%s\n", s2);
    char *r2 = reverse2(s2);
    printf("%s\n", r2);
    printf("%d\n", cnt2);
    return 0;
}
