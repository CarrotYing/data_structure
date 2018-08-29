#include <stdio.h>
#include <stdlib.h>
#include "seq_queue.h"

void SeqQueueInit(SeqQueue* q){
    if(q==NULL)
        return;
    q->data=(SeqQueueType* )malloc(sizeof(SeqQueueType)*SEQQUEUEMAXSIZE);
    q->head=0;
    q->tail=0;
    q->size=0;
    q->capacity=SEQQUEUEMAXSIZE;
}
void SeqQueueDestroy(SeqQueue* q){
    if(q==NULL)
        return ;
    if(q->data!=NULL)
        free(q->data);
    q->head=0;
    q->tail=0;
    q->size=0;
    q->capacity=0;
}

void SeqQueuePush(SeqQueue* q, SeqQueueType value){
    if(q==NULL)
        return;
    q->data[q->tail++]=value;
    if(q->tail>=q->capacity)
        q->tail=0;
    ++q->size;
    if(q->size>=q->capacity){
        //扩容要分类
        q->capacity+=50;
        SeqQueueType* nptr=(SeqQueueType* )malloc(sizeof(SeqQueue)*q->capacity);
        if(q->tail>q->head){
            //[head,tail)
            size_t i=0;
            size_t j=q->head;
            for(;i<q->tail;++i,++j){
                nptr[i]=q->data[j];
            }
        }
        else {
            //tail<=head 有效范围[head,size) [0,tail)
            size_t i=0;
            size_t j=q->head;
            for(;i<q->size;++i,++j){
                if(j>=q->size)
                    j=0;
                nptr[i]=q->data[j];
            }
            for(i=0;i<q->tail;++i,++j){
                nptr[i]=q->data[j];
            }
        }
        free(q->data);
        q->data=nptr;
        q->head=0;
        q->tail=q->size;
    }
}
void SeqQueuePop(SeqQueue* q){
    if(q==NULL)
        return;
    if(q->size==0)
        return;
    ++q->head;
    if(q->head>=q->capacity)
        q->head=0;
    --q->size;
}
int SeqQueueTop(SeqQueue* q,SeqQueueType* value){
    if(q==NULL|| value==NULL)
        return 0;
    if(q->size==0)
        return 0;
    *value=q->data[q->head];
    return 1;
}
