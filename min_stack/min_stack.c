#include "min_stack.h"

void MinStackInit(MinStack* mst)
{
    if(mst == NULL)
        return;
    StackInit(&mst->st);
    StackInit(&mst->min_st);
}
void MinStackDestory(MinStack* mst)
{
    if(mst == NULL)
        return;
    StackDestory(&mst->st);
    StackDestory(&mst->min_st);
}
void MinStackPushBack(MinStack* mst,StackDataType value)
{
    if(mst == NULL)
        return;
    StackPushBack(&mst->st,value);
    if(StackEmpty(&mst->min_st))
    {
        StackPushBack(&mst->min_st,value);
    }
    else 
    {
        StackDataType top = 0;
        StackGetTop(&mst->min_st,&top);
        if(value < top)
            StackPushBack(&mst->min_st,value);
        else 
            StackPushBack(&mst->min_st,top);
    }
}
void MinStackPopBack(MinStack* mst)
{
    if(mst == NULL)
        return;
    if(mst->min_st.size > 0)
        mst->min_st.size--;
    if(mst->st.size > 0)
        mst->st.size--;
}
int MinStackGetTop(const MinStack* mst,StackDataType* value)
{
    if(mst == NULL || value == NULL)
        return 0;
    if(mst->st.size == 0)
        return 0;
    *value = mst->st.data[mst->st.size-1];
    return 1;
}
int MinStackGetMin(const MinStack* mst,StackDataType* value)
{
    if(mst == NULL || value == NULL)
        return 0;
    if(mst->min_st.size == 0)
        return 0;
    *value = mst->min_st.data[mst->min_st.size-1];
    return 1;
}
