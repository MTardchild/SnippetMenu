#include <stdio.h>
#include <stdbool.h>

#include "LinkedList.h"
#include "ArrayUtility.h"
#include "ArraySort.h"
#include "Interface.h"
#include "Miscellaneous.h"

int ListenToInput() {
    int input;
    bool exit;
    scanf("%d", &input);

    switch(input) {
        case 1: ArraySwapValues(); break;
        case 2: PrintPointer(); break;
        case 3: ChangeValuesInterface(); break;
        case 4: SimpleLinkedList(); break;
        case 5: ArraySortIO(); break;
        case 0: exit = true; break;
        default: printf("Invalid input.");
    }
    return exit == true ? 1 : 0;
}

int main()
{
    while (true) {
        printf("\nNavigation\n");
        printf("01: Array Swap\n02: Print Pointer\n03: Change Values\n04: Simple Linked List\n05: Array Sorter\n00: Exit\n\n");
        if (ListenToInput() == 1) return 0;
    }
    return 0;
}
