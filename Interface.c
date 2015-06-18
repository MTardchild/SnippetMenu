#include <stdio.h>
#include <stdint.h>

#include "Utility.h"
#include "Interface.h"

void ChangeValuesInterface() {
    int32_t valueA, valueB;

    printf("Enter first value: ");
    scanf("%d", &valueA);
    printf("Enter second value: ");
    scanf("%d", &valueB);

    printf("\n--- Change Values ---\n");
    printf("Values before: valueA: %d / valueB: %d\n", valueA, valueB);
    ChangeValues(&valueA, &valueB);
    printf("Values after: valueA: %d / valueB: %d\n", valueA, valueB);
}

