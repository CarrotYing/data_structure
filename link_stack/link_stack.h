#include <stdlib.h>
typedef char LinkStackType;
typedef struct LinkNode{
    LinkStackType data;
    struct LinkNode* next;
}LinkNode;
typedef struct LinkStack{
    LinkNode* head;
    size_t size;
}LinkStack;

void LinkStackInit(LinkStack* stack);
void LinkStackDestroy(LinkStack* stack);

void LinkStackPush(LinkStack* stacki,LinkStackType value);
void LinkStackPop(LinkStack* stack);
int LinkStackTop(LinkStack* stack,LinkStackType* value);
