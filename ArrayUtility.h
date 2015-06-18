#ifndef HEADER_ARRAY_UTILITY
    #define HEADER_ARRAY_UTILITY

    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <stdint.h>
    #include <stdbool.h>

    void ArraySwapValues();
    int32_t GetRandomNumber(int32_t);
    void ArraySortIO();
    intptr_t* ArrayCreateByInput(bool);
    intptr_t* ArrayCreateByLength(int32_t, bool);
    void ArrayPrint (intptr_t*);
    intptr_t* ArrayCopy (intptr_t*);
    intptr_t* ArrayCopyByIndex (intptr_t*, int32_t, int32_t);
#endif
