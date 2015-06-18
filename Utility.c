#include <stdint.h>

int32_t GetRandomNumber(int32_t range) {
    static long a = 3;
    a = (((a * 214013L + 2531011L) >> 16) & 32767);

    return ((a % range) + 1);
}

void ChangeValues(int32_t *valueA, int32_t *valueB) {
    int32_t valueTemp = *valueA;
    *valueA = *valueB;
    *valueB = valueTemp;
}
