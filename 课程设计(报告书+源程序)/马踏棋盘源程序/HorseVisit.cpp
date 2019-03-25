#include<iostream.h>
#include"stack.h"
#include <iomanip.h>

Point g_round[8] = {0,0,0};
void SetRound(Point cur)//查找所在位置的所有可走位置的坐标，将其赋给g_round[8]
{
	Point round[] = 
	{
		cur.x-2,cur.y+1,0,cur.x-1,cur.y+2,0,
		cur.x+1,cur.y+2,0,cur.x+2,cur.y+1,0,
		cur.x+2,cur.y-1,0,cur.x+1,cur.y-2,0,
		cur.x-1,cur.y-2,0,cur.x-2,cur.y-1,0
	};
	for(int i=0;i<8;i++)
	{
		g_round[i].x = round[i].x;
		g_round[i].y = round[i].y;
	}
}
bool GetRound(int i,Point &pt)//将所在位置周围所有八个位置坐标赋予指针变量pt，并判断其合理性
{
	pt.x = g_round[i-1].x;
	pt.y = g_round[i-1].y;
	if(pt.x<0 || pt.y<0 || pt.x>7 || pt.y>7)//判断其合理性
		return false;
	else 
		return true;
}

void main()
{
	int s=1;
	char yn;
	cout<<"===============马踏棋盘的程序设计==============="<<endl;
	cout<<endl;
	while(s)
	{
		int order[8][8] = {0};     //初始化
		int count = 0;             //计数器，记录的是第几步棋
		
		Point begin;
		cout<<"请输入马在棋盘上的初始位置x和y。"<<endl;
		cout<<"[其中 1≤x≤8 且 1≤y≤8 ；例如：4 7] :";
		cin>>begin.x>>begin.y;
		begin.from = 0;
		while(begin.x>8 || begin.x<1 || begin.y>8 || begin.y<1)
		{
			cout<<"输入有误!请您重新输入......"<<endl;
			cout<<endl;
			cout<<"请输入马在棋盘上的初始位置x和y。"<<endl;
		    cout<<"[其中 1≤x≤8 且 1≤y≤8 ；例如：4 7] :";
			cin>>begin.x>>begin.y;
			cout<<endl;
		}
		begin.x--;    //实际下标是0~7，
		begin.y--;
		
		Stack horseVisit;
		Point cur,next;
		Initstack(horseVisit);
		Push(horseVisit,begin);       //首位置进栈
		order[begin.x][begin.y] = ++count;        //计数器加1
		
		while(count<64)
		{                            //其余63步棋的走法
			GetTop(horseVisit,cur);
			SetRound(cur);
			
			bool flag = false;
			for(int i=cur.from+1;i<=8;i++)
			{       //按照逆时针的优先规则，选出下一个可用的新位置
				if(GetRound(i,next) && order[next.x][next.y]==0)
				{        //可用位置未曾使用，则进栈，计数器加1
					flag = true;
					order[next.x][next.y] = ++count;
					
					Pop(horseVisit,cur);
					cur.from = i;
					Push(horseVisit,cur);
					
					next.from = 0;
					Push(horseVisit,next);
					break;
				}
			}
			if(!flag)
			{         //如果当前位置周围没有路径，则退栈，直至退到存在有最佳位置的坐标
				int j=0,p;
				if(begin.x==2 && begin.y==6) p=4;
				else p=5;
				while(j<p && GetDeep(horseVisit)>1)
				{
					Pop(horseVisit,cur);
					order[cur.x][cur.y] = 0;
					count--;
					j++;
				}
			}
		}
		DestroyStack(horseVisit);     //完成后销毁栈
		cout<<"棋盘表示:"<<endl;
		cout<<"               1   2   3   4   5   6   7   8"<<endl;
		cout<<"            ┌─┬─┬─┬─┬─┬─┬─┬─┐"<<endl;
		for(int i=0;i<8;i++)
		{            //输出order数组，数组上数值为路径
			cout<<setw(12)<<i+1<<setw(2)<<"│";
			for(int j=0;j<8;j++)
			{
				cout<<resetiosflags(ios::right)<<setw(2)<<order[i][j]<<"│";
			}
			cout<<endl;   
			if(i==7)cout<<"            └─┴─┴─┴─┴─┴─┴─┴─┘"<<endl;
			else cout<<"            ├─┼─┼─┼─┼─┼─┼─┼─┤"<<endl;
		}
		cout<<"您是否需要继续运行该程序（y--继续：n--退出）:";
		cin>>yn;
		cout<<endl;
		if(yn=='y'||yn=='Y')  s=1;
		else  
		{
			s=0;
			cout<<"===================谢谢使用！==================="<<endl;
		}
	}
}