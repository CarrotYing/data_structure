#pragma once
#include <stdlib.h>

#define SEQQUEUEMAXSIZE 100

typedef char SeqQueueType;
typedef struct SeqQueue{
    SeqQueueType* data;
    size_t head;
    size_t tail;
    size_t size;
    size_t capacity;
}SeqQueue;

void SeqQueueInit(SeqQueue* q);
void SeqQueueDestroy(SeqQueue* q);

void SeqQueuePush(SeqQueue* q, SeqQueueType value);
void SeqQueuePop(SeqQueue* q);
int SeqQueueTop(SeqQueue* q,SeqQueueType* value);
