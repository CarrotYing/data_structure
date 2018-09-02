#include <stdlib.h>
#include "stack.h"

void StackInit(Stack* st)
{
    if(st == NULL)
        return;
    QueueInit(&st->q1);
    QueueInit(&st->q2);
}
void StackDestory(Stack* st)
{
    if(st == NULL)
        return;
    QueueDestory(&st->q1);
    QueueDestory(&st->q2);
}
void StackPushBack(Stack* st,StackDataType value)
{
    if(st == NULL)
        return;
    if(QueueEmpty(&st->q2))
        QueuePushBack(&st->q1,value);
    else
        QueuePushBack(&st->q2,value);
}
void StackPopBack(Stack* st)
{
    if(st == NULL)
        return;
    StackDataType tmp = 0;
    if(QueueEmpty(&st->q1) && QueueEmpty(&st->q2))
        return;
    if(QueueEmpty(&st->q1))
    {
        while(!QueueEmpty(&st->q2))
        {
            QueueGetFront(&st->q2,&tmp);
            QueuePopFront(&st->q2);
            if(!QueueEmpty(&st->q2))
                QueuePushBack(&st->q1,tmp);
        }
    }
    else
    {
        while(!QueueEmpty(&st->q1))
        {
            QueueGetFront(&st->q1,&tmp);
            QueuePopFront(&st->q1);
            if(!QueueEmpty(&st->q1))
                QueuePushBack(&st->q2,tmp);
        }
    }
}
int StackGetTop(Stack* st,StackDataType* value)
{
    if(st == NULL)
        return 0;
    StackDataType tmp = 0;
    if(QueueEmpty(&st->q1) && QueueEmpty(&st->q2))
        return 0;
    if(QueueEmpty(&st->q1))
    {
        while(!QueueEmpty(&st->q2))
        {
            QueueGetFront(&st->q2,&tmp);
            QueuePopFront(&st->q2);
            QueuePushBack(&st->q1,tmp);
        }
        *value = tmp;
    }
    else
    {
        while(!QueueEmpty(&st->q1))
        {
            QueueGetFront(&st->q1,&tmp);
            QueuePopFront(&st->q1);
            QueuePushBack(&st->q2,tmp);
        }
        *value = tmp;
    }
    return 1;
}
int StackEmpty(const Stack* st)
{
    if(st == NULL)
        return 0;
    if(QueueEmpty(&st->q1) && QueueEmpty(&st->q2))
        return 1;
    else 
        return 0;
}
