#ifndef HEADER_ARRAY_SORT
    #define HEADER_ARRAY_SORT

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdint.h>
    #include <math.h>

    intptr_t* SelectionSortMin (intptr_t*);
    intptr_t* SelectionSortMax (intptr_t*);

    intptr_t* MergeSortMin (intptr_t*);
    intptr_t* MergeSortMerge (intptr_t*, intptr_t*);

    intptr_t* BucketSort (intptr_t*);
    intptr_t* BucketSortIO (intptr_t*);
    intptr_t* BucketConcatenate(intptr_t**, intptr_t*);
    void BucketSortAlgorithm (intptr_t**);
    void AddItemToBucket (intptr_t**, int32_t, int32_t);
    void PrintBuckets (intptr_t**);
    void InitializeBuckets (intptr_t**, intptr_t*);
    void InitializeBucketToNull (intptr_t*);
    void SetBucketSizes ();
    void SetMaxValue (intptr_t*);
    void SetMinValue (intptr_t*);
    int32_t GetBucketIndex (int32_t);
#endif // HEADER_ARRAY_SORT
