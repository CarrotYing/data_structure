#pragma once
#include "stack.h"
typedef struct MinStack{
    Stack min_st;
    Stack st;
}MinStack;

void MinStackInit(MinStack* mst);
void MinStackDestory(MinStack* mst);
void MinStackPushBack(MinStack* mst,StackDataType value);
void MinStackPopBack(MinStack* mst);
int MinStackGetTop(const MinStack* mst,StackDataType* value);
int MinStackGetMin(const MinStack* mst,StackDataType* value);
