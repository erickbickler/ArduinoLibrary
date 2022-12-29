#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char* fcnvt(float num, int sigFigs) {
    if (num < 0) {
        num *= -1;
        sigFigs--;
    }
    int decimalPlace = findDecimalPoint(num);

    int strLen = sigFigs + 1;
    char* out = malloc(strLen);
    if (out == NULL) return NULL;
    char* outStr = out;
    
    int i = 0, n = sigFigs - 1, p = pow(10, n);
    while(i < strLen) {
        if (num >= p) {
            out[i] = (char) (((int) num) / p + 48); // add 48 to get ascii value for char
            num = fmod(num, p);
            i++;
        } else if (i == decimalPlace) {
            out[i] = '.';
            i++;
        } else {
            num *= 10;
        }
    }
    return out;
}

int findDecimalPoint(float num) {
    int digits;
    for (int i = 0; num > 0; i++, digits = i) {
        num /= 10;
    }
    return digits;
}

int main(int argc, const char* argv[]) {
    printf("%s\n", fcnvt(12.375f, 4));
}