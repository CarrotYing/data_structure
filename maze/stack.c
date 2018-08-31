#include <stdlib.h>
#include "stack.h"
void SeqStackInit(SeqStack* stack){
    stack->data=(SeqStackType*)malloc(sizeof(SeqStackType)*MAX);
    stack->cap=MAX;
    stack->size=0;
}

void SeqStackPush(SeqStack* stack,SeqStackType value){
    if(stack==NULL)
        return ;
    if(stack->size==stack->cap)
        return;
    stack->data[stack->size]=value;
    stack->size++;
}

void SeqStackPop(SeqStack* stack){
    if(stack==NULL||stack->size==0)
        return;
    stack->size--;
}

void SeqStackGet(SeqStack* stack,SeqStackType* value){
    if(stack==NULL||stack->size==0)
        return;
    *value=stack->data[stack->size-1];
}
void SeqStackPrint(SeqStack stack){
    SeqStackType value={0,0};
    if(stack.size==0){
        return;
    }else{
        stack.size--;
        SeqStackPrint(stack);
        stack.size++;
        SeqStackGet(&stack,&value);        
        printf("[%d,%d]\n",value.row,value.col); 
    }
}
void SeqStackDestroy(SeqStack* stack){
    free(stack->data);
    stack->data=NULL;
    stack->size=0;
    stack->cap=0;
}
void SeqStackAssign(SeqStack* to,SeqStack* from){
   if(to==NULL||from==NULL)
       return ;
   SeqStackDestroy(to);
   to->cap=from->cap;
   to->size=from->size;
   to->data=(SeqStackType*)malloc(sizeof(SeqStackType)*from->cap);
   size_t i=0;
   for(;i<from->size;++i){
       to->data[i]=from->data[i];
   }
}
