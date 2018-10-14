#include <stdio.h>

/* Generate look-up table while pre-processing */
#define P2(n) n, n ^ 1, n ^ 1, n
#define P4(n) P2(n), P2(n ^ 1), P2(n ^ 1), P2(n)
#define P6(n) P4(n), P4(n ^ 1), P4(n ^ 1), P4(n)
#define LOOK_UP P6(0), P6(1), P6(1), P6(0)

/* LOOK_UP is the macro expansion to generate table */
unsigned int table[256] = { LOOK_UP };

int parity(int num) {
    /* Number is considered to be of 32 bits */
    int max = 16;

    // Dividing the number into 8-bit
    // chunks while performing XOR
    while (max >= 8) {
        num = num ^ (num >> max);
        max /= 2;
    }
    // Masking the number with 0xff (11111111)
    // to produce valid 8-bit result
    return table[num & 0xff];
}

void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    for (int i = size - 1; i >= 0; i--){
        for (int j = 7; j >= 0; j--){
            printf("%u", (b[i] >> j) & 1);
        }
    }
    puts("");
}

int main() {
    unsigned int num = 1742346774;
    /* Result is 1 for odd parity, 0 for even parity */
    int result = parity(num);
    printf("%s parity\n", result ? "odd" : "even");

    unsigned int v = num;
    int parity = 0;
    while (v)
    {
        printBits(sizeof(v), &v);
        parity = !parity;
        v = v & (v - 1);
    }
    printf("%s parity\n", parity ? "odd" : "even");
    return 0;
}
