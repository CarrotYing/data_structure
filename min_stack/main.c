#include "min_stack.h"
#define __HEADER__ printf("_______________%s________________\n",__FUNCTION__);

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
void TestMinStack()
{
    __HEADER__
    MinStack st;
    MinStackInit(&st);
    printf("PushBack:5 3 4 2 1 6\n");
    MinStackPushBack(&st,5);
    MinStackPushBack(&st,3);
    MinStackPushBack(&st,4);
    MinStackPushBack(&st,2);
    MinStackPushBack(&st,1);
    MinStackPushBack(&st,6);
    int ret = 0;
    int val = 0;
    ret = MinStackGetTop(&st,&val);
    printf("GetTopElement:\n");
    printf("expected ret=1,actual ret=%d\n",ret);
    printf("expected top=6,actual top=%d\n",val);
    ret = MinStackGetMin(&st,&val);
    printf("GetMinElement:\n");
    printf("expected ret=1,actual ret=%d\n",ret);
    printf("expected min=1,actual min=%d\n",val);
    MinStackPopBack(&st);
    MinStackPopBack(&st);
    MinStackPopBack(&st);
    ret = MinStackGetTop(&st,&val);
    printf("GetTopElement:\n");
    printf("expected ret=1,actual ret=%d\n",ret);
    printf("expected top=4,actual top=%d\n",val);
    ret = MinStackGetMin(&st,&val);
    printf("GetMinElement:\n");
    printf("expected ret=1,actual ret=%d\n",ret);
    printf("expected min=3,actual min=%d\n",val);
}
int main()
{
    TestStack();
    TestMinStack();
    return 0;
}
