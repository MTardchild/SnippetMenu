#include "ArraySort.h"
#include "Utility.h"
#include "ArrayUtility.h"

// Constants
// Bucket Sort
int32_t CONST_MIN_INT = -2147483647; // Marker for already checked spots
int32_t CONST_MAX_INT = 2147483647; // Marker for already checked spots
int32_t CONST_BUCKETS; // Number of buckets, declared by user input
int32_t CONST_MAX_VALUE; // Highest value in given array
int32_t CONST_MIN_VALUE; // Lowest value in given array
int32_t CONST_BUCKET_INTERVAL; // Range of each bucket

/// <summary>Sorts given array using selection sort (Ascending)</summary>
/// <parameter name="array">Array to get sorted</parameter>
/// <returns>Sorted Array</returns>
intptr_t* SelectionSortMin (intptr_t *array) {
    if (*array < 2) return array;

    int32_t i, j, minNum;

    for (i = 1; i < *array; i++) {
        minNum = i;
        for (j = i+1; j < *(array)+1; j++) {
            if (*(array+minNum) > *(array+j)) minNum = j;
        }
        ChangeValues((array+minNum), (array+i));
    }
    return array;
}

/// <summary>Sorts given array using selection sort (Descending)</summary>
/// <parameter name="array">Array to get sorted</parameter>
/// <returns>Sorted Array</returns>
intptr_t* SelectionSortMax (intptr_t *array) {
    if (*array < 2) return array;

    int32_t i, j, maxNum;

    for (i = 1; i < *array; i++) {
        maxNum = i;
        for (j = i+1; j < *array+1; j++) {
            if (*(array+maxNum) < *(array+j)) maxNum = j;
        }
        ChangeValues((array+maxNum), (array+i));
    }
    return array;
}

/// <summary>Sorts given array using merge sort (Ascending)</summary>
/// <parameter name="array">Array to get sorted</parameter>
/// <returns>Sorted Array</returns>
intptr_t* MergeSortMin (int32_t *array) {
    if (*array < 2) return array;

    int32_t halfArray = (int32_t)(*(array) / 2);
    intptr_t *arrayLeft = ArrayCreateByLength(halfArray, false);
    intptr_t *arrayRight = ArrayCreateByLength(*(array) - halfArray, false);

    arrayLeft = ArrayCopyByIndex(array, 1, halfArray);
    arrayRight = ArrayCopyByIndex(array, halfArray+1, *array);

    ArrayPrint(arrayLeft);
    ArrayPrint(arrayRight);

    arrayLeft = MergeSortMin(arrayLeft);
    arrayRight = MergeSortMin(arrayRight);
    return MergeSortMerge(arrayLeft, arrayRight);
}

/// <summary>Merges the left and right array</summary>
/// <summary>Always merges the lower number first</summary>
/// <parameter name="array">Array to get merged</parameter>
/// <returns>Merged Array</returns>
intptr_t* MergeSortMerge (int32_t *arrayLeft, int32_t *arrayRight) {
    intptr_t *arrayMerged = ArrayCreateByLength(*arrayLeft + *arrayRight, false);
    *arrayMerged = *arrayLeft + *arrayRight;
    int32_t i, j, k;

    for (i = 1, j = 1, k = 1; k < *(arrayLeft) + *(arrayRight)+1;) {
        printf("i: %d, j: %d, k: %d\n", i, j, k);
        printf("%d < %d\n\n", *(arrayLeft + i), *(arrayRight + j));
        if (*(arrayLeft + i) <= *(arrayRight + j)) {
            *(arrayMerged + k) = *(arrayLeft + i);
            *(arrayLeft + i) = 2147483647;

            if (i + 1 < *(arrayLeft) + 1) i++;
            k++;
        } else {
            *(arrayMerged + k) = *(arrayRight + j);
            *(arrayRight + j) = 2147483647;

            if (j + 1 < *(arrayRight) + 1) j++;
            k++;
        }
    }

    return arrayMerged;
}

/// <summary>Gives the user the opportunity to decide number of buckets</summary>
/// <parameter name="array">Array to get sorted</parameter>
/// <returns>Sorted Array</returns>
intptr_t* BucketSortIO (intptr_t* array) {
    printf("Number of Buckets: ");
    scanf("%d", &CONST_BUCKETS);
    BucketSort(array);
    return array;
}

/// <summary>Sorts given array using bucket sort and selection sort (Descending)</summary>
/// <parameter name="array">Array to get sorted</parameter>
/// <returns>Sorted Array</returns>
int32_t* BucketSort (intptr_t *array) {
    int32_t i;
    intptr_t **bucketArray = malloc(sizeof(intptr_t*)*CONST_BUCKETS);
    SetMaxValue(array);
    SetMinValue(array);
    SetBucketSizes(array);
    InitializeBuckets(bucketArray, array);

    for (i = 1; i < *array+1; i++) {
        AddItemToBucket(bucketArray, GetBucketIndex(*(array+i)), *(array+i));
    }

    for (i = 0; i < CONST_BUCKETS; i++) {
        *(bucketArray+i) = SelectionSortMax(*(bucketArray+i));
    }

    return BucketConcatenate(bucketArray, array);
}

/// <summary>Concatenates sorted buckets together, so we can return one sorted array</summary>
/// <parameter name="bucketArray">Array that stores the buckets</parameter>
/// <parameter name="array">Original unsorted array, now gets overridden by sorted array</parameter>
/// <returns>Sorted Array</returns>
intptr_t* BucketConcatenate(intptr_t **bucketArray, intptr_t *array) {
    int32_t i, j, k = 1;
    for (i = CONST_BUCKETS-1; i >= 0; i--) {
        for (j = 1; j < **(bucketArray+i)+1; j++) {
            *(array+k) = bucketArray[i][j];
            if ((k + 1) < *array+1) k++;
        }
    }

    return array;
}

/// <summary>Calculates bucket size</summary>
void SetBucketSizes () {
    int32_t range = CONST_MAX_VALUE-CONST_MIN_VALUE;
    int32_t bucketRange = (double)(range/CONST_BUCKETS)+2;
    CONST_BUCKET_INTERVAL = (int)ceil(bucketRange);
    printf("Bucket Interval: %d\n", CONST_BUCKET_INTERVAL);
}

/// <summary>Adds given item to given bucket</summary>
/// <parameter name="bucketArray">Array that stores the buckets</parameter>
/// <parameter name="bucketId">Determines in which bucket to insert the value</parameter>
/// <parameter name="value">Value of item</parameter>
void AddItemToBucket (intptr_t **bucketArray, int32_t bucketId, int32_t value) {
    int32_t i;
    for (i = 1; i < bucketArray[bucketId][0]+1; i++) {
        if (bucketArray[bucketId][i] == CONST_MIN_INT) {
            bucketArray[bucketId][i] = value;
            return;
        }
    }
}

/// <summary>Prints buckets and their items</summary>
/// <parameter name="bucketArray">Array that stores the buckets</parameter>
void PrintBuckets (intptr_t **bucketArray) {
    int32_t i, j;
    for (i = 0; i < CONST_BUCKETS; i++) {
        printf("\nBucket %d:\n", i);
        printf("Bucket Size %d: %d\n", i, bucketArray[i][0]);
        for (j = 1; j < **(bucketArray+i)+1; j++) {
            if (bucketArray[i][j+1] != CONST_MIN_INT) {
                if (j % 5 == 0) printf("\n");
                printf("[%d]: %d | ", j-1, bucketArray[i][j]);
            }
        }

        printf("\n");
    }

    printf("\n");
}

/// <summary>Dynamically allocates memory for needed buckets</summary>
/// <parameter name="bucketArray">Array that stores the buckets</parameter>
/// <parameter name="array">Array to sort, using the values to determine bucket size</parameter>
void InitializeBuckets (intptr_t **bucketArray, intptr_t *array) {
    int32_t i, j, k = 0;

    for (i = 0; i < CONST_BUCKETS; i++) {
        for (j = 1; j < *array+1; j++) {
            if (GetBucketIndex(*(array+j)) == i) {
                //printf("Adding %d to Bucket %d; k = %d; j = %d;\n", *(array+j), i, k, j);
                k++;
            }
        }

        //printf("Bucket %d should contain %d elements\n\n", i, k);
        *(bucketArray+i) = ArrayCreateByLength(k, false);
        InitializeBucketToNull(*(bucketArray+i));
        k = 0;
    }
}

/// <summary>Sets all values in a given bucket to MIN_INT</summary>
/// <parameter name="array">Array to initialize</parameter>
void InitializeBucketToNull (intptr_t *array) {
    int32_t i;
    for (i = 1; i < *array+1; i++) {
        *(array+i) = CONST_MIN_INT;
    }
}

/// <summary>Sets Constant CONST_MAX_VALUE to the maximum value of given array</summary>
/// <parameter name="array">Array to iterate over</parameter>
void SetMaxValue (intptr_t *array) {
    int32_t maxVal, i;
    for (i = 1; i < *array+1; i++) {
        if (*(array+i) > maxVal) maxVal = *(array+i);
    }

    CONST_MAX_VALUE = maxVal;
}

/// <summary>Sets Constant CONST_MIN_VALUE to the minimum value of given array</summary>
/// <parameter name="array">Array to iterate over</parameter>
void SetMinValue (intptr_t *array) {
    int32_t minVal, i;
    for (i = 1; i < *array+1; i++) {
        if (*(array+i) < minVal) minVal = *(array+i);
    }

    CONST_MIN_VALUE = minVal;
}

/// <summary>Calculates in what bucket given value belongs</summary>
/// <parameter name="value">Value of item</parameter>
/// <returns>Index of bucket value belongs to</returns>
int32_t GetBucketIndex (int32_t value) {
    return (int)floor((value-CONST_MIN_VALUE)/CONST_BUCKET_INTERVAL);
}
