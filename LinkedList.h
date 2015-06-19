#ifndef HEADER_LIST
#define HEADER_LIST

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "Utility.h"

// List Structure
typedef struct SimpleList {
    int value;
    struct SimpleList *next;
} SimpleList;

int32_t ListGetIndex();
int32_t ListGetValue();
void ListPrint (SimpleList *);
void ListPushEnd (SimpleList *);
void ListPushStart (SimpleList **);
void ListPopStart (SimpleList **);
void ListPopEnd (SimpleList *);
void ListPopAtIndex (SimpleList **);
void ListPushAtIndex (SimpleList **);
void ListPopFirstItemWithValue (SimpleList **, SimpleList *);
void ListPopAtIndexHardCode (SimpleList **, int32_t, int32_t);
int32_t ListenToInputList(SimpleList *);
void SimpleLinkedList();

#endif
