#include <stdio.h>
#include <stdlib.h>
#include "dblink_list.h"

void Print(DLinkNode* head){
    if(head==NULL)
        return;
    DLinkNode* cur=head;
    while(cur->next!=head){
        printf("%c ",cur->next->data);
        cur=cur->next;
    }
    printf("\n");
}
#define __HEADER__  printf("\n_________%s__________\n",__FUNCTION__);
void TestErase(){
    __HEADER__
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushFront(head,'A');
    DLinkListPushFront(head,'B');
    DLinkListPushFront(head,'A');
    DLinkListPushFront(head,'B');
    DLinkListPushFront(head,'C');
    DLinkListPushFront(head,'D');
    DLinkListPushFront(head,'C');
    DLinkListPushFront(head,'A');
    DLinkListPushFront(head,'B');
    DLinkListPushFront(head,'C');
    DLinkListPushFront(head,'D');
    DLinkListPushFront(head,'D');
    Print(head);
    printf("size=%lu\n",DLinkListSize(head));
    //DLinkNode* to_erase=DLinkListFind(head,'D');
    DLinkListRemoveAll(head,'D');
    Print(head);
    printf("size=%lu\n",DLinkListSize(head));
    DLinkListRemoveAll(head,'C');
    Print(head);
    printf("size=%lu\n",DLinkListSize(head));
    DLinkListRemoveAll(head,'B');
    if(DLinkListEmpty(head))
        printf("Empty\n");
    else printf("Not Empty\n"); 
    Print(head);
    printf("size=%lu\n",DLinkListSize(head));
    DLinkListRemoveAll(head,'A');
    Print(head);
    printf("size=%lu\n",DLinkListSize(head));
    DLinkListRemoveAll(head,'A');
    if(DLinkListEmpty(head))
        printf("Empty\n");
}
void TestFind(){
    __HEADER__
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushFront(head,'A');
    DLinkListPushFront(head,'B');
    DLinkNode* find=DLinkListFind(head,'A');
    DLinkListInsert(find,'T');
    DLinkListPushFront(head,'C');
    DLinkListPushFront(head,'D');
    find=DLinkListFind(head,'D');
    DLinkListInsertAfter(find,'K');
    Print(head);
}
void Test(){
    __HEADER__
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushFront(head,'A');
    DLinkListPushFront(head,'B');
    DLinkListPushFront(head,'C');
    DLinkListPushFront(head,'D');
    Print(head);
    DLinkListPopFront(head);
    DLinkListPopFront(head);
    DLinkListPopFront(head);
    Print(head);
    DLinkListPopFront(head);
    Print(head);
    DLinkListDestroy(&head);
}

int main(){
    Test();
    TestFind();
    TestErase();
    return 0;
}
