#ifndef HEADER_UTILITY
    #define HEADER_UTILITY

    #include <stdio.h>
    #include <stdint.h>
    #include <stdlib.h>

    int32_t GetRandomNumber(int32_t);
    void ChangeValues(int32_t*, int32_t*);
    intptr_t* ConvertStringToInt(char*, int32_t);
    intptr_t* GetInput();
#endif // HEADER_UTILITY
