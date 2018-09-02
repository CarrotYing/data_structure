#include <stdlib.h>
#include "list.h"
void LinkListInit(LinkList** head)
{
    if(head == NULL)
        return;
    *head = (LinkList*)malloc(sizeof(LinkList));
    LinkList* head_node = *head;
    head_node->data = 0;
    head_node->next = head_node;
    head_node->prev = head_node;
}
void LinkListDestory(LinkList** head)
{
    LinkList* cur = *head;
    while(cur != *head)
    {
        LinkList* to_delete = cur;
        cur = cur->next;
        free(to_delete);
    }
    free(*head);
    (*head)->data = 0;
    (*head)->next = NULL;
    (*head)->prev = NULL;
}

void LinkListInsert(LinkList* pos,ListDataType value)
{
    if(pos == NULL)
        return;
    LinkList* _prev = pos->prev;
    LinkList* new_node = (LinkList*)malloc(sizeof(LinkList));
    new_node->data = value;

    _prev->next = new_node;
    new_node->prev = _prev;

    pos->prev = new_node;
    new_node->next = pos;
}
void LinkListErase(LinkList* pos)
{
    LinkList* _prev = pos->prev;
    LinkList* _next = pos->next;
    _prev->next = _next;
    _next->prev = _prev;

    free(pos);
}

void LinkListPushBack(LinkList* head,ListDataType value)
{
    LinkListInsert(head,value);   
}
void LinkListPopBack(LinkList* head)
{
    LinkListErase(head->prev);
}

void LinkListPushFront(LinkList* head,ListDataType value)
{
    LinkListInsert(head->next,value);
}
void LinkListPopFront(LinkList* head)
{
    LinkListErase(head->next);
}

int LinkListEmpty(const LinkList* head)
{
    if(head->prev == head && head->next == head)
        return 1;
    else 
        return 0;
}

int LinkListGetTop(const LinkList* head,ListDataType* value)
{
    if(head == NULL || value == NULL)
        return 0;
    if(LinkListEmpty(head))
        return 0;
    *value = head->prev->data;
    return 1;
}
int LinkListGetFront(const LinkList* head,ListDataType* value)
{
    if(head == NULL || value == NULL)
        return 0;
    if(LinkListEmpty(head))
        return 0;
    *value = head->next->data;
    return 1;
}
