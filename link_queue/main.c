#include <stdio.h>
#include <stdlib.h>
#include "link_queue.h"
void print(LinkQueue* q){
    LinkNode* cur=q->head;
    while(cur!=NULL){
        printf("%c ",cur->data);
        cur=cur->next;
    }
    printf("\n");
}
#define __HEADER__ printf("\n___________%s____________\n",__FUNCTION__)
void TestInit(){
    __HEADER__;
    LinkQueue q;
    LinkQueueInit(&q);
    printf("size=%lu \n",q.size);
    LinkQueueDestroy(&q);
}

void TestPush(){
    __HEADER__;
    LinkQueue q;
    LinkQueueInit(&q);
    LinkQueuePush(&q,'A');
    printf("size=%lu \n",q.size);
    print(&q);
    LinkQueuePush(&q,'B');
    printf("size=%lu \n",q.size);
    print(&q);
    LinkQueuePush(&q,'C');
    printf("size=%lu \n",q.size);
    print(&q);
    LinkQueuePush(&q,'D');
    printf("size=%lu \n",q.size);
    print(&q);
    LinkQueueType top;
    if(LinkQueueTop(&q,&top))
        printf("%c\n",top);
    LinkQueuePop(&q);
    if(LinkQueueTop(&q,&top))
        printf("%c\n",top);
    LinkQueuePop(&q);
    if(LinkQueueTop(&q,&top))
        printf("%c\n",top);
    LinkQueuePop(&q);
    if(LinkQueueTop(&q,&top))
        printf("%c\n",top);
    LinkQueuePop(&q);
    if(LinkQueueTop(&q,&top))
        printf("%c\n",top);
    LinkQueuePop(&q);
    if(LinkQueueTop(&q,&top))
        printf("%c\n",top);
    printf("size=%lu \n",q.size);
    LinkQueueDestroy(&q);
}
void TestPop(){
    __HEADER__;
    LinkQueue q;
    LinkQueueInit(&q);
    LinkQueuePush(&q,'A');
    LinkQueuePush(&q,'B');
    LinkQueuePush(&q,'C');
    LinkQueuePush(&q,'D');
    LinkQueueType top;
    LinkQueuePop(&q);
    LinkQueuePop(&q);
    LinkQueuePop(&q);
    LinkQueuePush(&q,'C');
    LinkQueuePush(&q,'B');
    LinkQueuePush(&q,'A');
    printf("size=%lu \n",q.size);
    if(LinkQueueTop(&q,&top))
        printf("%c\n",top);
    LinkQueuePop(&q);

    printf("size=%lu \n",q.size);
    if(LinkQueueTop(&q,&top))
        printf("%c\n",top);
    LinkQueuePop(&q);

    printf("size=%lu \n",q.size);
    if(LinkQueueTop(&q,&top))
        printf("%c\n",top);
    LinkQueuePop(&q);
    printf("size=%lu \n",q.size);
    if(LinkQueueTop(&q,&top))
        printf("%c\n",top);
    LinkQueueDestroy(&q);
}
int main(){
    TestInit();
    TestPush();
    TestPop();
    return 0;
}

