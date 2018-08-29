#include <stdio.h>
#include <stdlib.h>
#include "seq_queue.h"

#define __HEADER__ printf("\n___________%s____________\n",__FUNCTION__)
void TestInit(){
    __HEADER__;
    SeqQueue q;
    SeqQueueInit(&q);
    printf("capa=%lu  size=%lu \n",q.capacity,q.size);
    SeqQueueDestroy(&q);
}

void TestPush(){
    __HEADER__;
    SeqQueue q;
    SeqQueueInit(&q);
    printf("capa=%lu  size=%lu \n",q.capacity,q.size);
    SeqQueuePush(&q,'A');
    printf("capa=%lu  size=%lu \n",q.capacity,q.size);
    SeqQueuePush(&q,'B');
    printf("capa=%lu  size=%lu \n",q.capacity,q.size);
    SeqQueuePush(&q,'C');
    printf("capa=%lu  size=%lu \n",q.capacity,q.size);
    SeqQueuePush(&q,'D');
    printf("capa=%lu  size=%lu \n",q.capacity,q.size);
    SeqQueueType top;
    if(SeqQueueTop(&q,&top))
        printf("%c\n",top);
    SeqQueuePop(&q);
    printf("capa=%lu  size=%lu \n",q.capacity,q.size);
    if(SeqQueueTop(&q,&top))
        printf("%c\n",top);
    SeqQueuePop(&q);
    printf("capa=%lu  size=%lu \n",q.capacity,q.size);
    if(SeqQueueTop(&q,&top))
        printf("%c\n",top);
    SeqQueuePop(&q);
    printf("capa=%lu  size=%lu \n",q.capacity,q.size);
    if(SeqQueueTop(&q,&top))
        printf("%c\n",top);
    SeqQueuePop(&q);
    printf("capa=%lu  size=%lu \n",q.capacity,q.size);
    if(SeqQueueTop(&q,&top))
        printf("%c\n",top);
    SeqQueuePop(&q);
    printf("capa=%lu  size=%lu \n",q.capacity,q.size);
    if(SeqQueueTop(&q,&top))
        printf("%c\n",top);
    SeqQueueDestroy(&q);
}
void TestPop(){
    __HEADER__;
    SeqQueue q;
    SeqQueueInit(&q);
    printf("capa=%lu  size=%lu \n",q.capacity,q.size);
    SeqQueuePush(&q,'A');
    printf("capa=%lu  size=%lu \n",q.capacity,q.size);
    SeqQueuePush(&q,'B');
    printf("capa=%lu  size=%lu \n",q.capacity,q.size);
    SeqQueuePush(&q,'C');
    printf("capa=%lu  size=%lu \n",q.capacity,q.size);
    SeqQueuePush(&q,'D');
    printf("capa=%lu  size=%lu \n",q.capacity,q.size);
    SeqQueueType top;
    SeqQueuePop(&q);
    SeqQueuePop(&q);
    SeqQueuePop(&q);
    SeqQueuePush(&q,'C');
    SeqQueuePush(&q,'B');
    SeqQueuePush(&q,'A');
    printf("capa=%lu  size=%lu \n",q.capacity,q.size);
    if(SeqQueueTop(&q,&top))
        printf("%c\n",top);
    SeqQueuePop(&q);

    printf("capa=%lu  size=%lu \n",q.capacity,q.size);
    if(SeqQueueTop(&q,&top))
        printf("%c\n",top);
    SeqQueuePop(&q);

    printf("capa=%lu  size=%lu \n",q.capacity,q.size);
    if(SeqQueueTop(&q,&top))
        printf("%c\n",top);
    SeqQueuePop(&q);
    printf("capa=%lu  size=%lu \n",q.capacity,q.size);
    if(SeqQueueTop(&q,&top))
        printf("%c\n",top);
    SeqQueueDestroy(&q);
}
int main(){
    TestInit();
    TestPush();
    TestPop();
    return 0;
}

