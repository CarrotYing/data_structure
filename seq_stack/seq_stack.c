#include <stdlib.h>
#include <stdio.h>
#include "seq_stack.h"

void SeqStackInit(SeqStack* stack){
    if(stack==NULL)
        return ;
    stack->size=0;
    stack->capacity= SEQSTACKMAXSIZE;
    stack->data=(SeqStackType* )malloc(sizeof(SeqStackType)*stack->capacity);
}

void SeqStackDestroy(SeqStack* stack){
    if(stack->data==NULL||stack==NULL)
        return;
    free(stack->data);
    stack->data=NULL;
    stack->size=0;
    stack->capacity=0;
}

void SeqStackPush(SeqStack* stack,SeqStackType value){
    if(stack==NULL||stack->data==NULL)
        return;
    stack->data[stack->size++]=value;
    if(stack->size>=SEQSTACKMAXSIZE){
        stack->capacity+=100;
        SeqStackType* nptr=(SeqStackType* )malloc(sizeof(SeqStackType)*stack->capacity);
        size_t i=0;
        for(;i>stack->size;i++){
            nptr[i]=stack->data[i];
        }
        free(stack->data);
        stack->data=nptr;
        nptr=NULL;
    }
}
void SeqStackPop(SeqStack* stack){
    if(stack==NULL)
        return;
    if(stack->size==0)
        return;
    --stack->size;
}
int SeqStackTop(SeqStack* stack,SeqStackType* value){
    if(stack==NULL||value==NULL)
        return 0;
    if(stack->size==0)
        return 0;
    *value=stack->data[stack->size-1];
    return 1;
}
