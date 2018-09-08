#pragma once

#include<stdio.h>

#define MAX 50

typedef struct Point{
    int row;
    int col;
}Point;

typedef Point SeqStackType;

typedef struct SeqStack{
    SeqStackType* data;
    size_t size;
    size_t cap;
}SeqStack;

/*@brief 初始化栈
 *
 *@param stack
 */
void SeqStackInit(SeqStack* stack);
/*
 * @brief 入栈
 *
 * @param stack
 * @param value
 * */
void SeqStackPush(SeqStack* stack,SeqStackType value);
/*
 *@brief 出栈
 *
 *@param stack
 * */
void SeqStackPop(SeqStack* stack);
/*
 *@brief 取出栈顶元素
 *
 *@param stack
 * */
void SeqStackGet(SeqStack* stack,SeqStackType* value);
/*
 *@brief 打印栈
 *
 *@param stack
 * */
void SeqStackPrint(SeqStack stack);
/*
 *@brief 拷贝栈
 *
 *@param stack
 * */
void SeqStackAssign(SeqStack* to,SeqStack* from);
/*
 *@brief 销毁栈
 *
 *@param stack
 * */
void SeqStackDestroy(SeqStack* stack);
