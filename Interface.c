#include <stdio.h>
#include <stdint.h>

#include "Utility.h"
#include "Interface.h"

void ChangeValuesInterface() {
    int32_t valueA, valueB;
    intptr_t *inputValue;

    printf("Enter first value: ");
    inputValue = GetInput();
    if (inputValue == NULL) {
        printf("Error");
        return;
    }
    valueA = *inputValue;

    printf("Enter second value: ");
    inputValue = GetInput();
    if (inputValue == NULL) {
        printf("Error");
        return;
    }
    valueB = *inputValue;

    printf("\n--- Change Values ---\n");
    printf("Values before: valueA: %d / valueB: %d\n", valueA, valueB);
    ChangeValues(&valueA, &valueB);
    printf("Values after: valueA: %d / valueB: %d\n", valueA, valueB);
}

