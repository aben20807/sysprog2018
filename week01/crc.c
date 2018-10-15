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

unsigned char get_crc(unsigned char c)
{
    unsigned int poly = (0b100000111 << 7);
    unsigned int crc = (c << 8);
    for (int i = 0; i < 8; i++) {
        if ((crc >> (16 - i - 1)) & 1) {
            crc ^= poly;
        }
        poly >>= 1;
    }
    return crc;
}

#define CRC8_TABLE_SIZE 256
typedef uint8_t u8;
typedef uint16_t u16;
void crc8_populate_msb(u8 table[CRC8_TABLE_SIZE], u16 polynomial)
{
    printf("%d\n", polynomial);
    int i, j;
    const u8 msbit = 0x80;
    u8 t = msbit;

    table[0] = 0;

    for (i = 1; i < CRC8_TABLE_SIZE; i *= 2) {
        t = (t << 1) ^ (t & msbit ? polynomial : 0);
        for (j = 0; j < i; j++)
            table[i+j] = table[j] ^ t;
    }
}

u8 crc8(const u8 table[CRC8_TABLE_SIZE], u8 pdata, u8 crc)
{
    crc = table[(crc ^ pdata) & 0xff];
    // printf("%d, %d\n", 0 ^ pdata, table[87]);
    return crc;
}

int main(){
    unsigned char c = 'W';
    print_bits(sizeof(c), &c);
    unsigned char crc = get_crc(c);
    print_bits(sizeof(crc), &crc);

    unsigned char table[CRC8_TABLE_SIZE];
    crc8_populate_msb(table, 0b100000111);
    for (int i = 0; i < CRC8_TABLE_SIZE; i++) {
        printf("%4d", table[i]);
        if ((i + 1) % 16 == 0)
            puts("");
    }
    puts("");
    u8 crc2 = crc8(table, c, 0);
    print_bits(sizeof(crc2), &crc2);
    return 0;
}
