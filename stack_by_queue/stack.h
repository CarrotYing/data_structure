#pragma once
#include<stdio.h>
#include "queue.h"
#define MAX 100
typedef int StackDataType; 
typedef struct Stack
{
    Queue q1;
    Queue q2;
}Stack;
void StackInit(Stack* st);
void StackDestory(Stack* st);
void StackPushBack(Stack* st,StackDataType value);
void StackPopBack(Stack* st);
int StackGetTop(Stack* st,StackDataType* value);
int StackEmpty(const Stack* st);

