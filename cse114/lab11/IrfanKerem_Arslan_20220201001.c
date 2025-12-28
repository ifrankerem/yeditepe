// 20220201001-072 LAB11

#include <stdio.h>

unsigned int getBit5thFromRight(unsigned int x) {
    return (x >> 4) & 1;
}

unsigned int setBit3rdFromRight(unsigned int x) {
    return x | (1 << 2);
}

unsigned int clearBit6thFromRight(unsigned int x) {
    return x & ~(1 << 5);
}

unsigned int toggleBit1stFromRight(unsigned int x) {
    return x ^ (1 << 0);
}

unsigned int replaceBit4thFromRight(unsigned int x, unsigned int b) {
    return (x & ~(1 << 3)) | (b << 3);
}

unsigned int getBit3rdFromLeft(unsigned int x) {
    return (x >> 29) & 1;
}

unsigned int clearBit5thFromLeft(unsigned int x) {
    return x & ~(1 << 27);
}

unsigned int setBit2ndFromLeft(unsigned int x) {
    return x | (1 << 30);
}

unsigned int getBit2ndFromRight(unsigned int x) {
    return (x >> 1) & 1;
}

int main() {
    printf("Q1: %u\n", getBit5thFromRight(16));
    printf("Q2: %u\n", setBit3rdFromRight(0));
    printf("Q3: %u\n", clearBit6thFromRight(32)); 
    printf("Q4: %u\n", toggleBit1stFromRight(0));
    printf("Q5: %u\n", replaceBit4thFromRight(0, 1));
    printf("Q6: %u\n", getBit3rdFromLeft(536870912)); // 00100000000000000000000000000000
    printf("Q7: %u\n", clearBit5thFromLeft(134217728)); // 00001000000000000000000000000000
    printf("Q8: %u\n", setBit2ndFromLeft(0)); // 01000000000000000000000000000000
    printf("Q9: %u\n", getBit2ndFromRight(2)); 
    return 0;
}
