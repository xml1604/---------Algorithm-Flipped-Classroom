#include <malloc.h>
#ifndef		STACK_H
#define		STACK_H
//-------------λ�õĴ洢��ʽ��ʽ
struct Point
{
	int x;
	int y;
	int from;
};
//--------------ջ�Ĵ洢��ʽ--------------
#define STACKSIZE       70
#define STACKINCREASE   10
struct Stack
{
	Point *top;
	Point *base;
	int length;
};
//--------------����������-----------------
bool Initstack(Stack &s);
bool Push(Stack &s,Point e);
bool Pop(Stack &s,Point &e);
void DestroyStack(Stack &s);
bool StackEmpty(Stack S);
bool GetTop(Stack S,Point &e);
int GetDeep(Stack S);

#endif