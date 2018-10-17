#include <stdio.h>
#include <stdint.h>

void print_bits(size_t const size, void const *const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    for (int i = size - 1; i >= 0; i--){
        for (int j = 7; j >= 0; j--){
            printf("%u", (b[i] >> j) & 1);
        }
    }
    puts("");
}

int parity(uint32_t x)
{
    x ^= x >> 1;
    x ^= x >> 2;
    x = (x & 0x11111111U) * 0x11111111U;
    return (x >> 28) & 1;
}

int parity_steps(uint32_t x)
{
    printf("x\t\t");            print_bits(sizeof(x), &x);
    uint32_t y = x >> 1;
    printf("x >> 1\t\t");       print_bits(sizeof(y), &y);
    x ^= y;
    printf("x ^= x >> 1\t");    print_bits(sizeof(x), &x);

    y = x >> 2;
    printf("x >> 2\t\t");       print_bits(sizeof(y), &y);
    x ^= y;
    printf("x ^= x >> 2\t");    print_bits(sizeof(x), &x);

    y = x & 0x11111111U;
    printf("x & @\t\t");        print_bits(sizeof(y), &y);
    y *= 0x11111111U;
    printf("(x & @) * @\t");    print_bits(sizeof(y), &y);
    y >>= 28;
    printf("x >>= 28\t");       print_bits(sizeof(y), &y);
    x = y & 1;
    printf("x & 1\t\t");        print_bits(sizeof(x), &x);
    return x;
}

int main()
{
    unsigned int num = 1742346774;
    // int result = parity(num);
    int result = parity_steps(num);
    printf("%s parity\n", result ? "odd" : "even");
    return 0;
}
