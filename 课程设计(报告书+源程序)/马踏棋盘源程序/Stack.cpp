#include"stack.h"

bool Initstack(Stack &s)             //����һ����ջS
{
	s.base = (Point*)malloc(STACKSIZE*sizeof(Point));
	if(!s.base)return false;
	s.length = STACKSIZE;
	s.top = s.base;
	return true;
}

bool Push(Stack &s,Point e)         //����Ԫ��eΪ�µ�ջ��Ԫ��
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

bool Pop(Stack &s,Point &e)          //��ջ��Ϊ�գ���ɾ��S��ջ��Ԫ��
{
	if(s.top == s.base)return false;
	e.x = (*--s.top).x;
	e.y = (*s.top).y;
	e.from = (*s.top).from;
	return true;
}

void DestroyStack(Stack &s)        //����ջS��S���ڴ���
{
	free(s.base);
}

bool StackEmpty(Stack S)           //��ջSΪ��ջ���򷵻�ture�����򷵻�false��
{
	if(S.base == S.top)
		return true;
	else 
		return false;
}

bool GetTop(Stack S,Point &e)       //��ջ��Ϊ�գ���ȡջ��Ԫ��
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

int GetDeep(Stack S)               //ȡջ�����
{	
	return (S.top-S.base);
}