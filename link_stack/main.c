#include <stdio.h>
#include "link_stack.h"
#define __HEADER__ printf("\n___________%s_____________\n",__FUNCTION__);
void TestInit(){
    __HEADER__
    LinkStack stack;
    LinkStackInit(&stack);
    printf("%lu \n",stack.size);
    LinkStackDestroy(&stack);
    printf("%lu \n",stack.size);
}
void TestPush(){
    __HEADER__
    LinkStack stack;
    LinkStackInit(&stack);
    LinkStackPush(&stack,'A');
    LinkStackPush(&stack,'B');
    LinkStackPush(&stack,'C');
    LinkStackPush(&stack,'D');
    LinkStackType top;
    printf("%lu \n",stack.size);
    if(LinkStackTop(&stack,&top))
        printf("top=%c\n",top);
    LinkStackPop(&stack);        
    printf("%lu \n",stack.size);
    if(LinkStackTop(&stack,&top))
        printf("top=%c\n",top);
            
    LinkStackPop(&stack);        
    printf("%lu \n",stack.size);
    if(LinkStackTop(&stack,&top))
        printf("top=%c\n",top);
    LinkStackPop(&stack);        
    printf("%lu \n",stack.size);
    if(LinkStackTop(&stack,&top))
        printf("top=%c\n",top);
    LinkStackPop(&stack);        
    printf("%lu \n",stack.size);
    if(LinkStackTop(&stack,&top))
        printf("top=%c\n",top);
    LinkStackPop(&stack);        
    printf("%lu \n",stack.size);
    if(LinkStackTop(&stack,&top))
        printf("top=%c\n",top);
    else printf("Empty\n");
    LinkStackDestroy(&stack);
}
int main(){
    TestInit();
    TestPush();
    return 0;
}
