#include "LinkedList.h"

void ListPrint (SimpleList *head) {
    SimpleList *Current = head;
    int32_t i = 0;

    while (Current != NULL) {
        printf("List[%d]: %d \n", i, Current->value);
        Current = Current->next;
        i++;
    }
}

int32_t ListGetValue() {
    int32_t value;
    printf("Enter value to Push: ");
    scanf("%d", &value);
    return value;
}

void ListPushEnd (SimpleList *head) {
    int32_t value = ListGetValue();
    SimpleList *Current = head;

    while (Current->next != NULL) {
        Current = Current->next;
    }
    if ((Current->next = malloc(sizeof(SimpleList))) == NULL) {
        printf("Memory Allocation failed.");
        return;
    }
    Current->next->value = value;
    Current->next->next = NULL;
}

void ListPushStart (SimpleList **head) {
    int32_t value = ListGetValue();
    SimpleList *NewItem;
    if ((NewItem = malloc(sizeof(SimpleList))) == NULL) {
        printf("Memory Allocation failed.");
        return;
    }
    NewItem->value = value;
    NewItem->next = *head;

    *head = NewItem;
}

void ListPopStart (SimpleList **head) {
    if (*head == NULL) {
        return;
    }
    SimpleList *NextItemStore = (*head)->next;
    free(*head);
    *head = NextItemStore;
}

void ListPopEnd (SimpleList *head) {
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    SimpleList *Current = head;
    SimpleList *NextItem = head->next;

    while (NextItem->next != NULL) {
        Current = Current->next;
        NextItem = NextItem->next;
    }
    free(NextItem);
    Current->next = NULL;

}

void ListPopAtIndex (SimpleList **head) {
    int32_t index = ListGetIndex();
    if (index == 0) {
        ListPopStart(head);
        return;
    }

    SimpleList *Current = *head;
    SimpleList *NextItem = (*head)->next;
    int32_t i;

    for (i = 0; i < index-1; i++) {
        Current = Current->next;
        NextItem = NextItem->next;
    }
    Current->next = NextItem->next;

    free(NextItem);
}

int32_t ListGetIndex() {
    int32_t index;
    printf("Enter index, where to push:");
    scanf("%d", &index);
    return index;
}

void ListPushAtIndex (SimpleList **head) {
    int32_t index = ListGetIndex();
    int32_t value = ListGetValue();
    if (index == 0) {
        ListPushStart(head);
        return;
    }
    SimpleList *NewItem;
    if ((NewItem = malloc(sizeof(SimpleList))) == NULL) {
        printf("Memory Allocation failed.");
        return;
    }
    NewItem->value = value;

    SimpleList *Current = *head;
    SimpleList *NextItem = (*head)->next;

    int32_t i;

    for (i = 0; i < index-1; i++) {
        if (Current->next == NULL) {
            printf("Tried to push, but index is out of bounds.\n");
            return;
        }
        Current = Current->next;
        NextItem = NextItem->next;
    }
    NewItem->next = NextItem;
    Current->next = NewItem;
}

void ListPopAtIndexHardCode (SimpleList **head, int32_t index, int32_t value) {
    if (index == 0) {
        ListPopStart(head);
        return;
    }

    SimpleList *Current = *head;
    SimpleList *NextItem = (*head)->next;
    int32_t i;

    for (i = 0; i < index-1; i++) {
        Current = Current->next;
        NextItem = NextItem->next;
    }
    Current->next = NextItem->next;

    free(NextItem);
}

void ListPopFirstItemWithValue (SimpleList **headPoint, SimpleList *head) {
    int32_t value = ListGetValue();
    SimpleList *Current = head;
    int32_t i = 0;

    while (Current != NULL) {
        if (Current->value == value) {
            ListPopAtIndexHardCode(headPoint, i, value);
            return;
        }
        Current = Current->next;
        i++;
    }
}

int32_t ListenToInputList(SimpleList *rootNode) {
    int32_t input;
    bool exit;
    scanf("%d", &input);

    switch(input) {
        case 1: ListPrint(rootNode); break;
        case 2: ListPushStart(&rootNode); break;
        case 3: ListPushEnd(rootNode); break;
        case 4: ListPushAtIndex(&rootNode); break;
        case 5: ListPopStart(&rootNode); break;
        case 6: ListPopEnd(rootNode); break;
        case 7: ListPopAtIndex(&rootNode); break;
        case 8: ListPopFirstItemWithValue(&rootNode, rootNode); break;
        case 0: exit = true; break;
        default: printf("Unknown.");
    }
    return exit == true ? 1 : 0;
}

SimpleList* ListInitialize() {
    printf("--- Initializing Standard List ---\n");
    SimpleList *rootNode = NULL;
    if ((rootNode = malloc(sizeof(SimpleList))) == NULL) {
        printf("Memory Allocation failed.");
        return NULL;
    }
    rootNode->value = 1337;
    if ((rootNode->next = malloc(sizeof(SimpleList))) == NULL) {
        printf("Memory Allocation failed.");
        return NULL;
    }
    rootNode->next->value = 7;
    rootNode->next->next = NULL;
    ListPrint(rootNode);
    return rootNode;
}

void SimpleLinkedList() {
    printf("--- Simple Linked List ---\n");
    SimpleList *rootNode = ListInitialize();

    while (true) {
        printf("\nMenu\n");
        printf("01: Print List\n02: Push List (Root)\n03: Push List (End)\n04: Push List (Index)\n05: Pop List (Root)\n06: Pop List (End)\n07: Pop List (Index)\n08: Pop List (First given value found)\n00: Exit\n\n");
        if (ListenToInputList(rootNode) == 1) return;
    }
}
