#pragma once
#include <stdlib.h>

typedef char LinkQueueType;
typedef struct LinkNode{
    LinkQueueType data;
    struct LinkNode* next;
}LinkNode;

typedef struct LinkQueue{
    LinkNode* head;
    size_t size;
}LinkQueue;

void LinkQueueInit(LinkQueue* q);
void LinkQueueDestroy(LinkQueue* q);

void LinkQueuePush(LinkQueue* q,LinkQueueType value);
void LinkQueuePop(LinkQueue* q);
int LinkQueueTop(LinkQueue* q,LinkQueueType* value);
