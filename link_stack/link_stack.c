#include <stdio.h>
#include <stdlib.h>
#include "link_stack.h"

void LinkStackInit(LinkStack* stack){
    if(stack==NULL)
        return;
    stack->head=NULL;
    stack->size=0;
}
void LinkNodeDestroy(LinkNode* to_erase){
    if(to_erase!=NULL)
        free(to_erase);
}
void LinkStackDestroy(LinkStack* stack){
    if(stack==NULL)
        return;
    while(stack->head!=NULL){
        LinkNode* to_erase=stack->head;
        stack->head=to_erase->next;
        LinkNodeDestroy(to_erase);       
    }
    stack->size=0;
}

void LinkStackPush(LinkStack* stack,LinkStackType value){
    if(stack==NULL)
        return;
    LinkNode* new_node=(LinkNode* )malloc(sizeof(LinkNode));
    new_node->data=value;
    new_node->next=stack->head;
    stack->head=new_node;
    ++stack->size;
}
void LinkStackPop(LinkStack* stack){
    if(stack==NULL)
        return;
    if(stack->size==0)
        return;
    LinkNode* to_erase=stack->head;
    stack->head=to_erase->next;
    LinkNodeDestroy(to_erase);
    --stack->size;
}
int LinkStackTop(LinkStack* stack,LinkStackType* value){
    if(stack==NULL||value==NULL)
        return 0;
    if(stack->size==0)
        return 0;
    *value=stack->head->data;
    return 1;
}
