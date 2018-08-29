#pragma once
#include <stdlib.h>

typedef char DLinkType;
typedef struct DLinkNode{
    DLinkType data;
    struct DLinkNode* prev;
    struct DLinkNode* next;
}DLinkNode;

//DLinkNode* DLinkListInit(void);
DLinkNode* CreateNode(DLinkType value);
void DestroyNode(DLinkNode* phead);
void DLinkListInit(DLinkNode** phead);
void DLinkListDestroy(DLinkNode** phead);

void DLinkListPushBack(DLinkNode* head,DLinkType value);
void DLinkListPopBack(DLinkNode* head);

void DLinkListPushFront(DLinkNode* head,DLinkType value);
void DLinkListPopFront(DLinkNode* head);
DLinkNode* DLinkListFind(DLinkNode* head, DLinkType to_find);

/**
* @brief 往指定位置之前插入一个元素
*/
void DLinkListInsert(DLinkNode* pos, DLinkType value);

/**
* @brief 往指定位置之后插入一个元素
*/
void DLinkListInsertAfter(DLinkNode* pos, DLinkType value);
// 删除指定位置的元素
void DLinkListErase(DLinkNode* pos);

// 删除指定值的元素 
void DLinkListRemove(DLinkNode* head,DLinkType value);

//指定值的所有元素都删掉
void DLinkListRemoveAll(DLinkNode* head,DLinkType value);

size_t DLinkListSize(DLinkNode* head);
//链表为空, 返回1, 否则返回0 
int DLinkListEmpty(DLinkNode* head);
