#include <stdio.h>

void PrintPointer() {
    printf("\n--- Print Pointer ---\n");
    char characterSeven = '7';
    char *sevenPointer = &characterSeven;

    printf("%d, %d \n\n", (int)&characterSeven, (int)sevenPointer);
}
