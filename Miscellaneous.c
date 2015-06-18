#include "Miscellaneous.h"

/// <summary>BS exercise</summary>
void PrintPointer() {
    printf("\n--- Print Pointer ---\n");
    char characterSeven = '7';
    char *sevenPointer = &characterSeven;

    printf("%d, %d \n\n", (int)&characterSeven, (int)sevenPointer);
}

/// <summary>Computes number at given row and column in pascals triangle</summary>
/// <parameter name="row">Row in which to look (0 index)</parameter>
/// <parameter name="column">Column at which to look (0 index)</parameter>
/// <returns>Computed Number if input was correct, else -1</returns>
int32_t ComputePascal(int32_t row, int32_t column) {
    if (column == 0 || column == row) return 1;
    if (column > row) return -1;

    return ComputePascal(row-1, column-1) + ComputePascal(row-1, column);
}

/// <summary>Handles user input for pascal</summary>
void ComputePascalIO() {
    char *input = malloc(sizeof(char)*10);
    int32_t row, column;

    fflush(stdin);
    printf("\nPascal Triangle\n");
    printf("Indices starting at 0\n");

    printf("Enter the row: ");
    if (fgets(input, 5, stdin) == NULL) {
        printf("Error: Invalid Input.");
        return;
    }

    if (ConvertStringToInt(input, 3) != NULL) {
        row = *ConvertStringToInt(input, 3);
    } else {
        printf("Error row");
        return;
    }

    printf("\nEnter the column: ");
    if (fgets(input, 3, stdin) == NULL) {
        printf("Error: Invalid Input.");
        return;
    }

    if (ConvertStringToInt(input, 3) != NULL) {
        column = *ConvertStringToInt(input, 3);
    } else {
        printf("Error column");
        return;
    }

    printf("\nValue at [%d/%d] = %d", row, column, ComputePascal(row, column));
}
