#pragma once
#include "list.h"
typedef ListDataType QueueDataType;
typedef struct Queue
{
    LinkList* head;
}Queue;
void QueueInit(Queue* q);
void QueueDestory(Queue* q);
void QueuePushBack(Queue* q,QueueDataType val);
void QueuePopFront(Queue* q);
int QueueGetFront(Queue* q,QueueDataType* val);
int QueueEmpty(const Queue* q);
