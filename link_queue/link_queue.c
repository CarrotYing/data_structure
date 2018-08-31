#include <stdio.h>
#include <stdlib.h>
#include "link_queue.h"

void LinkQueueInit(LinkQueue* q){
    if(q==NULL)
        return;
    q->head=NULL;
    q->size=0;
}
void LinkQueueDestroy(LinkQueue* q){
    if(q==NULL)
        return;
    LinkNode* cur=q->head;
    while(cur!=NULL){
        LinkNode* p=cur;
        cur=cur->next;
        free(p);
    }
    q->size=0;
    q->head=NULL;
}

void LinkQueuePush(LinkQueue* q,LinkQueueType value){
    if(q==NULL)
        return;
    LinkNode* new_node=(LinkNode* )malloc(sizeof(LinkNode));
    new_node->data=value;
    new_node->next=q->head;
    q->head=new_node;
    ++q->size;
}
void LinkQueuePop(LinkQueue* q){
    if(q==NULL)
        return;
    if(q->size==0)
        return;
    if(q->head->next==NULL){
        free(q->head);
        q->head=NULL;
    }
    else {
        LinkNode* cur=q->head->next;
        LinkNode* pre=q->head;
        while(cur->next!=NULL){
            cur=cur->next;
            pre=pre->next;
        }
        free(cur);
        pre->next=NULL;
    }
    --q->size;
}
int LinkQueueTop(LinkQueue* q,LinkQueueType* value){
    if(q==NULL||value==NULL)
        return 0;
    if(q->size==0)
        return 0;
    if(q->head->next==NULL)
        *value=q->head->data;
    else {
        LinkNode* cur=q->head->next;
        while(cur->next!=NULL){
            cur=cur->next;
        }
        *value=cur->data;
    }
    return 1;
}
