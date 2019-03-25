#include <malloc.h>
#ifndef		STACK_H
#define		STACK_H
//-------------位置的存储表式方式
struct Point
{
	int x;
	int y;
	int from;
};
//--------------栈的存储方式--------------
#define STACKSIZE       70
#define STACKINCREASE   10
struct Stack
{
	Point *top;
	Point *base;
	int length;
};
//--------------操作集函数-----------------
bool Initstack(Stack &s);
bool Push(Stack &s,Point e);
bool Pop(Stack &s,Point &e);
void DestroyStack(Stack &s);
bool StackEmpty(Stack S);
bool GetTop(Stack S,Point &e);
int GetDeep(Stack S);

#endif