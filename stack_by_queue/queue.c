#include <stdlib.h>
#include "queue.h"
void QueueInit(Queue* q)
{
    if(q == NULL)
        return;
    LinkListInit(&q->head);
}
void QueueDestory(Queue* q)
{
    if(q == NULL)
        return;
    LinkListDestory(&q->head);
}
void QueuePushBack(Queue* q,QueueDataType val)
{
    if(q == NULL)
        return;
    LinkListPushBack(q->head,val);
}
void QueuePopFront(Queue* q)
{
    if(q == NULL)
        return;
    LinkListPopFront(q->head);
}
int QueueGetFront(Queue* q,QueueDataType* val)
{
    if(q == NULL || val == NULL)
        return 0;
    if(LinkListEmpty(q->head))
        return 0;
    LinkListGetFront(q->head,val);
    return 1;
}
int QueueEmpty(const Queue* q)
{
    if(q == NULL)
        return 0;
    if(LinkListEmpty(q->head))
        return 1;
    else 
        return 0;
}
