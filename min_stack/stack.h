#pragma once
#include<stdio.h>
#define MAX 100
typedef int StackDataType; 
typedef struct Stack
{
   StackDataType* data;
   size_t size;
   size_t capacity;
}Stack;
void StackInit(Stack* st);
void StackDestory(Stack* st);
void StackPushBack(Stack* st,StackDataType value);
void StackPopBack(Stack* st);
int StackGetTop(const Stack* st,StackDataType* value);
int StackEmpty(const Stack* st);

