#include <stdio.h>
#include <stdbool.h>

bool is_le1()
{
    union {
        int a;
        char b;
    } c = { .a = 1 };
    return c.b == 1;
}

bool is_le2()
{
    int x = 1;
    char *y = (char*)&x;
    return *y;
}

bool is_le3()
{
    char arr[2] = {0x01, 0x00};
    short x = *(short *)arr;
    return x == 1;
}

bool is_le4()
{
    return !!((union {
        int a;
        char b;
    }){ .a = 1 }.b);
}

int main()
{
    printf("%s-endian\n", is_le1() ? "little" : "big");
    printf("%s-endian\n", is_le2() ? "little" : "big");
    printf("%s-endian\n", is_le3() ? "little" : "big");
    printf("%s-endian\n", is_le4() ? "little" : "big");
    return 0;
}
