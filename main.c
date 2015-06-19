#include <stdio.h>
#include <stdbool.h>

#include "LinkedList.h"
#include "ArrayUtility.h"
#include "ArraySort.h"
#include "Interface.h"
#include "Miscellaneous.h"
#include "Utility.h"

int ListenToInput() {
    bool exit;
    intptr_t *inputValue;

    inputValue = GetInput();
    if (inputValue == NULL) {
        printf("Invalid input.");
        return 0;
    }

    switch(*inputValue) {
        case 1: ArraySwapValues(); break;
        case 2: PrintPointer(); break;
        case 3: ChangeValuesInterface(); break;
        case 4: SimpleLinkedList(); break;
        case 5: ArraySortIO(); break;
        case 6: ComputePascalIO(); break;
        case 0: exit = true; break;
        default: printf("Invalid input.");
    }
    return exit == true ? 1 : 0;
}

int main()
{
    while (true) {
        printf("\nNavigation\n");
        printf("01: Array Swap\n02: Print Pointer\n03: Change Values\n04: Simple Linked List\n05: Array Sorter\n06: Pascal Triangle\n00: Exit\n\n");
        if (ListenToInput() == 1) return 0;
    }
    return 0;
}
