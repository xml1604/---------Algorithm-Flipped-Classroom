#include"stack.h"

bool Initstack(Stack &s)             //构造一个空栈S
{
	s.base = (Point*)malloc(STACKSIZE*sizeof(Point));
	if(!s.base)return false;
	s.length = STACKSIZE;
	s.top = s.base;
	return true;
}

bool Push(Stack &s,Point e)         //插入元素e为新的栈顶元素
{
	if(s.top - s.base >= s.length)
	{
		s.base = (Point*)realloc(s.base,
			(s.length+STACKINCREASE)*sizeof(Point));
		if(!s.base)return false;
		s.length +=STACKINCREASE;
		s.top = s.base + s.length;
	}
	(*s.top).x = e.x;
	(*s.top).y = e.y;
	(*s.top).from = e.from;
	s.top ++;
	return true;
}

bool Pop(Stack &s,Point &e)          //若栈不为空，则删除S的栈顶元素
{
	if(s.top == s.base)return false;
	e.x = (*--s.top).x;
	e.y = (*s.top).y;
	e.from = (*s.top).from;
	return true;
}

void DestroyStack(Stack &s)        //销毁栈S，S不在存在
{
	free(s.base);
}

bool StackEmpty(Stack S)           //若栈S为空栈，则返回ture；否则返回false。
{
	if(S.base == S.top)
		return true;
	else 
		return false;
}

bool GetTop(Stack S,Point &e)       //若栈不为空，则取栈顶元素
{
	if(StackEmpty(S))
		return false;
	else
	{
		e.x = (*(S.top-1)).x;
		e.y = (*(S.top-1)).y;
		e.from = (*(S.top-1)).from;
		return true;
	}
}

int GetDeep(Stack S)               //取栈的深度
{	
	return (S.top-S.base);
}