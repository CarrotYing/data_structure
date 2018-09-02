#include "queue.h"
#include "list.h"
#include "stack.h"
#define __HEADER__ printf("____________%s_____________\n",__FUNCTION__);
void TestList()
{
    __HEADER__
    LinkList* head;
    LinkListInit(&head);
    LinkListPushBack(head,1);
    LinkListPushBack(head,2);
    LinkListPushBack(head,3);
    LinkListPushBack(head,4);
    LinkListPushBack(head,5);
    int ret = 0;
    int val = 0;
    ret = LinkListGetTop(head,&val);
    printf("GetTop:\n");
    printf("expected ret=1,actual ret=%d\n",ret);
    printf("expected val=5,actual val=%d\n",val);
    LinkListPopBack(head);
    ret = LinkListGetTop(head,&val);
    printf("GetTop:\n");
    printf("expected ret=1,actual ret=%d\n",ret);
    printf("expected val=4,actual val=%d\n",val);
    LinkListPushFront(head,5);
    LinkListPushFront(head,6);
    LinkListPushFront(head,7);
    ret = LinkListGetFront(head,&val);
    printf("GetFront:\n");
    printf("expected ret=1,actual ret=%d\n",ret);
    printf("expected val=7,actual val=%d\n",val);
    LinkListPopFront(head);
    ret = LinkListGetFront(head,&val);
    printf("GetFront:\n");
    printf("expected ret=1,actual ret=%d\n",ret);
    printf("expected val=6,actual val=%d\n",val);
}
void TestQueue()
{
    __HEADER__
    Queue q;
    QueueInit(&q);
    printf("PushBack: 1 2 3 4 5\n");
    QueuePushBack(&q,1);
    QueuePushBack(&q,2);
    QueuePushBack(&q,3);
    QueuePushBack(&q,4);
    QueuePushBack(&q,5);
    int ret = 0;
    int val = 0;
    ret = QueueGetFront(&q,&val);
    printf("GetFront:\n");
    printf("expected ret=1,actual ret=%d\n",ret);
    printf("expected val=1,actual val=%d\n",val);
    QueuePopFront(&q);
    QueuePopFront(&q);
    QueuePopFront(&q);
    ret = QueueGetFront(&q,&val);
    printf("GetFront:\n");
    printf("expected ret=1,actual ret=%d\n",ret);
    printf("expected val=4,actual val=%d\n",val);
    QueuePopFront(&q);
    QueuePopFront(&q);
    ret = QueueGetFront(&q,&val);
    printf("GetFront:\n");
    printf("expected ret=0,actual ret=%d\n",ret);
}
void TestStack()
{
    __HEADER__
    Stack st;
    StackInit(&st);
    printf("PushBack:5 4 3 2 1\n");
    StackPushBack(&st,5);
    StackPushBack(&st,4);
    StackPushBack(&st,3);
    StackPushBack(&st,2);
    StackPushBack(&st,1);
    int ret = 0;
    int val = 0;
    ret = StackGetTop(&st,&val);
    printf("GetTopElement:\n");
    printf("expected ret=1,actual ret=%d\n",ret);
    printf("expected top=1,actual top=%d\n",val);
    StackPopBack(&st);
    StackPopBack(&st);
    StackPopBack(&st);
    StackPopBack(&st);
    ret = StackGetTop(&st,&val);
    printf("GetTopElement :\n");
    printf("expected ret=1,actual ret=%d\n",ret);
    printf("expected top=5,actual top=%d\n",val);
    StackPopBack(&st);
    ret = StackGetTop(&st,&val);
    printf("GetTopElement :\n");
    printf("expected ret=0,actual ret=%d\n",ret);
}
int main()
{
    TestList();
    TestQueue();
    TestStack();
    return 0;
}
