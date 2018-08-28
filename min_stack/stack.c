#include <stdlib.h>
#include "stack.h"
void StackInit(Stack* st)
{
    if(st == NULL)
        return;
    st->data = NULL;
    st->size = 0;
    st->capacity = 0;
}
void StackExpand(Stack* st,size_t size)
{
    if(st == NULL)
        return;
    if(size > st->capacity)
    {
        StackDataType* tmp = (StackDataType*)malloc(size*sizeof(StackDataType));
        size_t i = 0;
        for(;i<st->size;++i)
        {
            tmp[i] = st->data[i];
        }
        free(st->data);
        st->data = tmp;
        st->capacity = size;
    }
}
void StackPushBack(Stack* st,StackDataType value)
{
    if(st == NULL)
        return;
    if(st->size == st->capacity)
    {
        StackExpand(st,st->capacity*2+1);
    }
    st->data[st->size++] = value;
}
void StackPopBack(Stack* st)
{
    if(st == NULL)
        return;
    if(st->size > 0)
    {
       st->size--; 
    }
}
int StackGetTop(const Stack* st,StackDataType* value)
{
    if(st == NULL || value == NULL )
        return 0;
    if(st->size == 0)
        return 0;
    *value = st->data[st->size-1];
    return 1;
}
void StackDestory(Stack* st)
{
    if(st == NULL)
        return;
    if(st->data)
    {
        free(st->data);
    }
    st->data = NULL;
    st->size = 0;
    st->capacity = 0;
}

int StackEmpty(const Stack* st)
{
    if(st == NULL)
        return 0;
    if(st->size == 0)
        return 1;  
    else 
        return 0;
}
