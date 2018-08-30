#include <stdio.h>
#include "seq_stack.h"
#define __HEADER__ printf("\n___________%s_____________\n",__FUNCTION__);
void TestInit(){
    __HEADER__
    SeqStack stack;
    SeqStackInit(&stack);
    printf("%lu %lu\n",stack.capacity,stack.size);
    SeqStackDestroy(&stack);
    printf("%lu %lu\n",stack.capacity,stack.size);
}
void TestPush(){
    __HEADER__
    SeqStack stack;
    SeqStackInit(&stack);
    SeqStackPush(&stack,'A');
    SeqStackPush(&stack,'B');
    SeqStackPush(&stack,'C');
    SeqStackPush(&stack,'D');
    SeqStackType top;
    if(SeqStackTop(&stack,&top))
        printf("top=%c\n",top);
    SeqStackPop(&stack);        
    if(SeqStackTop(&stack,&top))
        printf("top=%c\n",top);
            
    SeqStackPop(&stack);        
    if(SeqStackTop(&stack,&top))
        printf("top=%c\n",top);
    SeqStackPop(&stack);        
    if(SeqStackTop(&stack,&top))
        printf("top=%c\n",top);
    SeqStackPop(&stack);        
    if(SeqStackTop(&stack,&top))
        printf("top=%c\n",top);
    SeqStackPop(&stack);        
    if(SeqStackTop(&stack,&top))
        printf("top=%c\n",top);
    else printf("Empty\n");
    SeqStackDestroy(&stack);
}
int main(){
    TestInit();
    TestPush();
    return 0;
}
