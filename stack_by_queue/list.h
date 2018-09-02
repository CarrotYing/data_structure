#pragma once
typedef int ListDataType;
typedef struct LinkList
{
    ListDataType data;
    struct LinkList* next;
    struct LinkList* prev;
}LinkList;

void LinkListInit(LinkList** head);
void LinkListDestory(LinkList** head);

void LinkListInsert(LinkList* pos,ListDataType value);
void LinkListErase(LinkList* pos);

void LinkListPushBack(LinkList* head,ListDataType value);
void LinkListPopBack(LinkList* head);

void LinkListPushFront(LinkList* head,ListDataType value);
void LinkListPopFront(LinkList* head);

int LinkListEmpty(const LinkList* head);
int LinkListGetTop(const LinkList* head,ListDataType* value);
int LinkListGetFront(const LinkList* head,ListDataType* value);
