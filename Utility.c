#include "Utility.h"

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

intptr_t* ConvertStringToInt(char *array, int32_t length) {
    int32_t i;
    intptr_t *value = malloc(sizeof(*value));

    for (i = 0; i < length; i++) {
        if(*(array+i) < 48 || *(array+i) > 57) {
            if (*(array+i) == '\0' || *(array+i) == '\n') break;
            return NULL;
        }
    }

    *value = atoi(array);
    return value;
}

intptr_t* GetInput() {
    char *input = malloc(sizeof(*input)*6);
    intptr_t *returnConvert = malloc(sizeof(*returnConvert));

    if (fgets(input, 5, stdin) == NULL) {
        printf("Invalid input.");
        return NULL;
    }

    returnConvert = ConvertStringToInt(input, 6);
    if (returnConvert == NULL) {
        printf("Invalid input.");
        return NULL;
    }
    return returnConvert;
}
