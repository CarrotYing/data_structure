#pragma once
#include <stdlib.h>

#define SEQSTACKMAXSIZE 100
typedef char SeqStackType;
typedef struct SeqStack{
    SeqStackType* data;
    size_t size;
    size_t capacity;
}SeqStack;


void SeqStackInit(SeqStack* stack);
void SeqStackDestroy(SeqStack* stack);

void SeqStackPush(SeqStack* stack,SeqStackType value);
void SeqStackPop(SeqStack* stack);
int SeqStackTop(SeqStack* stack,SeqStackType* value);
