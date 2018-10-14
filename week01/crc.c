#include <stdio.h>

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

unsigned char get_crc(unsigned char c)
{
    unsigned int mask = (1 << 15);
    unsigned int poly = (0b100000111 << 7);
    unsigned int crc = (c << 8);
    for (int j = 0; j < 8; j++) {
        if (crc & mask) {
            crc ^= poly;
        }
        mask >>= 1;
        poly >>= 1;
    }
    return crc;
}

int main(){
    unsigned char c = 'W';
    print_bits(sizeof(c), &c);
    unsigned char crc = get_crc(c);
    print_bits(sizeof(crc), &crc);
    return 0;
}
