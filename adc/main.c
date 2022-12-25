#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

int powers_of_two[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536};

int lookup_table[] = {0, 1, 1, 2, 3, 3, 4, 4, 5, 6, 6, 7, 8, 8, 9, 9};

int convert(bool * arr){
    int factor = 1;
    int sum = 0;
    for(int i = 3; i >= 0; --i){
        sum += arr[i] * factor;
        factor *= 2;
    }
    return sum;
}

int main() {
    int resolution = 16;
    srand(time(NULL));
    unsigned int bits = rand() % powers_of_two[resolution]; //adc resolution is 16 bits
    int range[] = {10, 30}; //range of temperatures that sensor work with
    int difference = range[1] - range[0];
    printf("%d\n", bits);
    bits *= difference;
    printf("%d\n", bits);
    bits = bits >> 12;
    bool shifted_bits[4] = {};
    for(int i = 3; i >= 0; --i){
        shifted_bits[i] = bits & 1;
        bits = bits >> 1;
    }
    printf("%d,%d",bits + 10, lookup_table[convert(shifted_bits)]);
    return 0;
}
