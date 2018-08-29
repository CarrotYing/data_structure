#include <stdio.h>
#include "dblink_list.h"

DLinkNode* CreateNode(DLinkType value){
    DLinkNode* new_node=(DLinkNode* )malloc(sizeof(DLinkNode));
    new_node->data=value;
    new_node->next=new_node;
    new_node->prev=new_node;
    return new_node;
}
void DestroyNode(DLinkNode* phead){
    if(phead==NULL)
        return;
    free(phead);
}
void DLinkListInit(DLinkNode** phead){
    if(phead==NULL)
        return;
    *phead=CreateNode(0);
}
void DLinkListDestroy(DLinkNode** phead){
    if(phead==NULL||*phead==NULL)
        return;
    DLinkNode* cur=(*phead)->next;
    while(cur!=*phead){
        DLinkNode* to_erase=cur;
        cur=cur->next;
        DestroyNode(to_erase);
    }
    DestroyNode(*phead);
}

void DLinkListPushBack(DLinkNode* head,DLinkType value){
    if(head==NULL)
        return;
    DLinkNode* tail=head->prev;
    DLinkNode* new_node=CreateNode(value);
   
    tail->next=new_node;
    new_node->prev=tail;

    new_node->next=head;
    head->prev=new_node;

}
void DLinkListPopBack(DLinkNode* head){
    if(head==NULL)
        return;
    if(head->next==head&&head->prev==head){
        return;
    }
    DLinkNode* to_delete=head->prev;
    DLinkNode* pre=to_delete->prev;

    pre->next=head;
    head->prev=pre;

    DestroyNode(to_delete);
}

void DLinkListPushFront(DLinkNode* head,DLinkType value){
    if(head==NULL)
        return;
    DLinkNode* Dprev=head->next;//first node
    DLinkNode* new_node=CreateNode(value);

    new_node->next=Dprev;
    new_node->prev=head;

    head->next=new_node;
    Dprev->prev=new_node;
}
void DLinkListPopFront(DLinkNode* head){
    if(head==NULL)
        return;
    if(head->prev==head&&head->prev==head)
        return;
    DLinkNode* to_delete=head->next;
    head->next=to_delete->next;
    head->next->prev=head;

    DestroyNode(to_delete);
}
DLinkNode* DLinkListFind(DLinkNode* head, DLinkType to_find){
    if(head==NULL)
        return NULL;
    DLinkNode* cur=head->next;
    while(cur!=head){
        if(cur->data==to_find)
            return cur;
        else
            cur=cur->next;
    }
    return NULL;
}
void DLinkListInsert(DLinkNode* pos, DLinkType value){
    if(pos==NULL)
        return;
    DLinkNode* pre=pos->prev;
    DLinkNode* new_node=CreateNode(value);
    new_node->next=pos;
    pos->prev=new_node;

    pre->next=new_node;
    new_node->prev=pre;
}

void DLinkListInsertAfter(DLinkNode* pos, DLinkType value){
    if(pos==NULL)
        return;
    DLinkNode* new_node=CreateNode(value);
    DLinkNode* after=pos->next;

    pos->next=new_node;
    new_node->prev=pos;

    after->prev=new_node;
    new_node->next=after;
}

// 删除指定位置的元素
void DLinkListErase(DLinkNode* pos){
    if(pos==NULL)
        return ;
    DLinkNode* pre=pos->prev;
    DLinkNode* after=pos->next;

    pre->next=after;
    after->prev=pre;

    DestroyNode(pos);
}

// 删除指定值的元素 
void DLinkListRemove(DLinkNode* head,DLinkType value){
    if(head==NULL)
        return;
    DLinkNode* cur=head->next;
    while(cur!=head){
        if(cur->data==value)
            break;
        cur=cur->next;
    }
    if(cur==head)
        return;
    DLinkListErase(cur);
}

//指定值的所有元素都删掉
void DLinkListRemoveAll(DLinkNode* head,DLinkType value){
    if(head==NULL)
        return;
    DLinkNode* cur=head->next;
    while(cur!=head){
        if(cur->data==value){
            DLinkNode* to_erase=cur;
            cur=cur->next;
            DLinkListErase(to_erase);
        }
        else
            cur=cur->next;
    }
    if(cur==head)
        return;

}
size_t DLinkListSize(DLinkNode* head){
    if(head==NULL)
        return 0;
    size_t count=0;
    DLinkNode* cur=head->next;
    while(cur!=head){
        count++;
        cur=cur->next;
    }
    return count;
}
//链表为空, 返回1, 否则返回0 
int DLinkListEmpty(DLinkNode* head){
    if(head==NULL)
        return 0;
    if(head->next==head&&head->prev==head)
        return 1;
    return 0;
}
