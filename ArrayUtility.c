#include "main.h"
#include "ArraySort.h"
#include "Utility.h"
#include "ArrayUtility.h"

//////////////////////////////////////////////
//  Self-Reminder:                          //
//  Length is always stored at index 0      //
//  If you want to iterate over an array    //
//  start at 1 and end at *array+1          //
//////////////////////////////////////////////

/// <summary>Interface for user to sort an array</summary>
void ArraySortIO() {
    intptr_t *arrayInt = ArrayCreateByInput(true), *inputValue;
    intptr_t *arrayIntSorted = ArrayCreateByLength(*arrayInt, false);
    arrayIntSorted = ArrayCopy(arrayInt);

    printf("\nNavigation\n");
    printf("01: Quick Sort (ASAP)\n02: Selection Sort (Ascending)\n03: Selection Sort (Descending)\n04: Merge Sort (Ascending)\n05: Bucket Sort(Descending)\n00: Exit\n\n");

    inputValue = GetInput();
    if (inputValue == NULL) {
        printf("Invalid input.");
        return;
    }

    printf("\n--- Generated Array ---\n");
    ArrayPrint(arrayInt);
    printf("\n");
    clock_t start, finish;
    start = clock();

    switch(*inputValue) {
        case 2: arrayIntSorted = SelectionSortMin(arrayInt); break;
        case 3: arrayIntSorted = SelectionSortMax(arrayInt); break;
        case 4: arrayIntSorted = MergeSortMin(arrayInt); break;
        case 5: arrayIntSorted = BucketSortIO(arrayInt); break;
        case 0: return; break;
        default: printf("\nWrong Input"); break;
    }

    finish = clock();
    printf("\n--- Sorted Array ---\n");
    ArrayPrint(arrayIntSorted);
    printf("\nTime for sort (seconds): %lf", (double)(finish-start)/CLOCKS_PER_SEC);
}

/// <summary>Swaps two values chosen by user in a random array</summary>
void ArraySwapValues() {
    printf("--- Array Swap ---\n");
    intptr_t *intArray = ArrayCreateByInput(true), *inputValue;
    int32_t firstIndex, secondIndex;

    ArrayPrint(intArray);

    printf("\nIndices to swap: \n");
    printf("First Index: ");

    inputValue = GetInput();
    if (inputValue == NULL) {
        printf("Invalid input.");
        return;
    }

    firstIndex = *inputValue;
    printf("Second Index: ");
    inputValue = GetInput();
    if (inputValue == NULL) {
        printf("Invalid input.");
        return;
    }

    secondIndex = *inputValue;
    ChangeValues(intArray+firstIndex, intArray+secondIndex);
    ArrayPrint(intArray);
}

/// <summary>Prints given array</summary>
/// <parameter name="array">Array to get printed</parameter>
void ArrayPrint (intptr_t *array) {
    int32_t i;
    printf("Array Length: %d\n", *array);
    for (i = 1; i < *array+1; i++) {
        printf("Array[%d]: %d\n", i, *(array+i));
    }
}

/// <summary>Copies the given array into a new one</summary>
/// <parameter name="array">Array to get copied</parameter>
/// <returns>Copied Array</returns>
intptr_t* ArrayCopy (intptr_t *array) {
    int32_t i;

    intptr_t *arrayCopy = malloc(sizeof(int32_t)* *array);
    for (i = 0; i < *array; i++) {
        *(arrayCopy+i) = *(array+i);
    }
    return arrayCopy;
}

/// <summary>Copies the given array from indexStart to indexEnd into a new array</summary>
/// <parameter name="array">Array to get copied</parameter>
/// <parameter name="indexStart">Start index (inclusive)</parameter>
/// <parameter name="indexEnd">End index (inclusive)</parameter>
/// <returns>Copied Array</returns>
intptr_t* ArrayCopyByIndex (intptr_t *array, int32_t indexStart, int32_t indexEnd) {
    int32_t *arrayNew = ArrayCreateByLength(indexEnd-indexStart+1, false);
    int32_t i, j;

    for (i = indexStart, j = 1; i < indexEnd+1; i++) {
        *(arrayNew+j) = *(array+i);
        j++;
    }
    return arrayNew;
}

/// <summary>Creates new array by user input</summary>
/// <parameter name="randomNumbers">Determines if the array gets filled with random numbers</parameter>
/// <returns>New Array</returns>
intptr_t* ArrayCreateByInput(bool randomNumbers) {
    int32_t i, range, size;
    intptr_t *inputValue;

    printf("Enter array size: ");
    inputValue = GetInput();
    if (inputValue == NULL) {
        printf("Invalid input.");
        return NULL;
    }
    size = *inputValue;

    intptr_t *arrayInt = malloc(sizeof(int32_t)*(size+1));
    *arrayInt = size;

    if (randomNumbers) {
        printf("Range from 0 to: ");
        inputValue = GetInput();
        if (inputValue == NULL) {
            printf("Invalid input.");
            return NULL;
        }
        range = *inputValue;

        for (i = 1; i < size+1; i++) {
            *(arrayInt+i) = GetRandomNumber(range);
        }
    }
    return arrayInt;
}

/// <summary>Creates new array by given length</summary>
/// <parameter name="arrayLength">Size of the array</parameter>
/// <parameter name="randomNumbers">Determines if the array gets filled with random numbers</parameter>
/// <returns>New Array</returns>
intptr_t* ArrayCreateByLength(int32_t arrayLength, bool randomNumbers) {
    int32_t i, range;
    intptr_t *arrayInt = malloc(sizeof(int32_t)*(arrayLength+1)), *inputValue;
    *arrayInt = arrayLength;

    if (randomNumbers) {
        printf("Range from 0 to: ");
        inputValue = GetInput();
        if (inputValue == NULL) {
            printf("Invalid input.");
            return NULL;
        }
        range = *inputValue;

        for (i = 1; i < arrayLength+1; i++) {
            *(arrayInt+i) = GetRandomNumber(range);
        }
    }
    return arrayInt;
}
