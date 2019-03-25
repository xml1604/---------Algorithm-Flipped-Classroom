#include "stdio.h"
#include<stdlib.h>
#define mytype int//矩阵元素的数据类型
#define myinputmode "%d"//矩阵元素的输入格式
#define myprintmode "%4d"//矩阵元素的输出格式
/*以上参数的设置可根据所计算矩阵的元素的数值类型进行相应改变
如更改为浮点型数据则可以使用下面的设置
#define mytype float
#define myinputmode "%f"
#define myprintmode "%6.2f"
*/
/////////////////////////////////////////
/****************************************
函数名：is2
参数：m为长整型整数
功能：检测m是否是2的正整数次幂
返回值：返回布尔型变量
        true则表示m为2的正整数次幂
  false则表示m不是2的正整数次幂
****************************************/
int is2(int m)
{
 if(m<0)return 0;
 if(m>=2)
 {
  if((m%2)==0) return is2(m/2);
  else return 0;
 }
 else
 {
  if(m==1)return 1;
  else return 0;
 }
 return 0;
}
/////////////////////////////////////////
/****************************************
函数名：inputmatrix
参数：M为指向数组的指针，用来存储输入的矩阵
      m长整型，是数组M所存矩阵的维数
   name字符型数组，是需要进行数据输入的矩阵的名字
功能：矩阵数据输入的函数，通过输入矩阵的每个元素将
      矩阵存入数组
返回值：无
****************************************/
void inputmatrix(mytype * M,int m,char *name,int a[][200])
{
 int i,j;
 for(i=0;i<m;i++)
  for(j=0;j<m;j++)
  {
   
   M[i*m+j]=a[i+1][j+1];
	  
  }
}
/////////////////////////////////////////
/****************************************
函数名：printmatrix
参数：M为指向数组的指针，数组中存储着矩阵
      m长整型，是数组M所存矩阵的维数
   name字符型数组，是需要进行数据输入的矩阵的名字
功能：矩阵数据输出显示的函数，将矩阵元素一一显示一在屏幕上
返回值：无
****************************************/
void printmatrix(mytype * M,int m,int n,char *name)
{
 int i,j;
 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
   printf(myprintmode,M[i*m+j]);
  }
  printf("\n");
 }
}
void printmatrix2(mytype * M,int N,int m,int n,char *name)
{
 int i,j,k;
 for(k=0,i=0;k<m;i+=N,k++)
 {
  for(j=0;j<n;j++)
  {
   printf(myprintmode,M[i+j]);
  }
  printf("\n");
 }
}
/////////////////////////////////////////
/****************************************
函数名：Matrix_add_sub
参数：A，B为指向数组的指针，数组中存储着矩阵
   C为指向数组的指针，用来存储运算结果
      m长整型，是数组A、B、C所存矩阵的维数
   add为布尔型变量，为true则C=A+B，为false则C=A-B
功能：根据add值对A、B进行加减运算并将结果存入C
返回值：无
****************************************/
void Matrix_add_sub(mytype * A,mytype * B,mytype * C,int m,int add)
{
 long i;
 for(i=0;i<m*m;i++)
 {
  if(add==1)
   C[i]=A[i]+B[i];
  else
   C[i]=A[i]-B[i];
 }
}
/////////////////////////////////////////
/****************************************
函数名：GetHalfValue
参数：B为指向数组的指针，数组中存储着矩阵。其中B是指向m维矩阵中的一个元素。
   A为指向数组的指针，用来接收B中的四分之一数据
      m长整型，是数组B所指矩阵的维数
功能：从B所在位置向左和向右取矩阵的m/2维的子矩阵（子矩阵中包括B所指元素）并存入A
返回值：无
****************************************/
void GetHalfValue(mytype * A,mytype * B,int m)
{
 int i,j;
 for(i=0;i<m/2;i++)
 {
  for(j=0;j<m/2;j++)
  {
   A[i*m/2+j]=B[i*m+j];
  }
 }
}
/////////////////////////////////////////
/****************************************
函数名：UpdateHalfValue
参数：B为指向数组的指针，数组中存储着矩阵。其中B是指向m维矩阵中的一个元素。
   A为指向数组的指针，存储着一个m/2维矩阵
      m长整型，是数组B所指矩阵的维数
功能：把A矩阵所有元素存入从B所在位置向左和向右的m/2维的子矩阵（子矩阵中包括B所指元素）
返回值：无
****************************************/
void UpdateHalfValue(mytype * A,mytype * B,int m)
{
 int i,j;
 for(i=0;i<m/2;i++)
 {
  for(j=0;j<m/2;j++)
  {
   B[i*m+j]=A[i*m/2+j];
  }
 }
}
/////////////////////////////////////////
/****************************************
函数名：Matrix_multiplication
参数：A，B为指向数组的指针，数组中存储着矩阵。
   C为指向数组的指针，用来存储计算结果
      m长整型，是指针A、B所指矩阵的维数
功能：用分而治之算法和Strassen方法计算A与B的乘积并存入C
返回值：无
****************************************/
void Matrix_multiplication(mytype * A,mytype * B,mytype * C,int m)
{
 if(m>2)//当矩阵维数大于2时
 {
	//将矩阵A、B分为四个小矩阵，分别为A1、A2、A3、A4、B1、B2、B3、B4;
	mytype *A1,*A2,*A3,*A4,*B1,*B2,*B3,*B4,*C1,*C2,*C3,*C4,*D,*E,*F,*G,*H,*I,*J,*temp1,*temp2;
 A1=(mytype *)malloc(sizeof(mytype)*m*m/4);
 A2=(mytype*)malloc(sizeof(mytype)*m*m/4);
 A3=(mytype*)malloc(sizeof(mytype)*m*m/4);
 A4=(mytype*)malloc(sizeof(mytype)*m*m/4);
 B1=(mytype*)malloc(sizeof(mytype)*m*m/4);
 B2=(mytype*)malloc(sizeof(mytype)*m*m/4);
 B3=(mytype*)malloc(sizeof(mytype)*m*m/4);
 B4=(mytype*)malloc(sizeof(mytype)*m*m/4);
 C1=(mytype*)malloc(sizeof(mytype)*m*m/4);
 C2=(mytype*)malloc(sizeof(mytype)*m*m/4);
 C3=(mytype*)malloc(sizeof(mytype)*m*m/4);
 C4=(mytype*)malloc(sizeof(mytype)*m*m/4);
  GetHalfValue(A1,&A[0],m);
  GetHalfValue(A2,&A[m/2],m);
  GetHalfValue(A3,&A[m*m/2],m);
  GetHalfValue(A4,&A[m*m/2+m/2],m);
  GetHalfValue(B1,&B[0],m);
  GetHalfValue(B2,&B[m/2],m);
  GetHalfValue(B3,&B[m*m/2],m);
  GetHalfValue(B4,&B[m*m/2+m/2],m);
  //利用Strassen方法计算D、E、F、G、H、I、J
D=(mytype*)malloc(sizeof(mytype)*m*m/4);
E=(mytype*)malloc(sizeof(mytype)*m*m/4);
F=(mytype*)malloc(sizeof(mytype)*m*m/4);
G=(mytype*)malloc(sizeof(mytype)*m*m/4);
H=(mytype*)malloc(sizeof(mytype)*m*m/4);
I=(mytype*)malloc(sizeof(mytype)*m*m/4);
J=(mytype*)malloc(sizeof(mytype)*m*m/4);
 temp1=(mytype*)malloc(sizeof(mytype)*m*m/4);
 temp2=(mytype*)malloc(sizeof(mytype)*m*m/4);
  //D=A1(B2-B4)
  Matrix_add_sub(B2,B4,temp1,m/2,0);
  Matrix_multiplication(A1,temp1,D,m/2);
  //E=A4(B3-B1)
  Matrix_add_sub(B3,B1,temp1,m/2,0);
  Matrix_multiplication(A4,temp1,E,m/2);
  //F=(A3+A4)B1
  Matrix_add_sub(A3,A4,temp1,m/2,1);
  Matrix_multiplication(temp1,B1,F,m/2);
  //G=(A1+A2)B4
  Matrix_add_sub(A1,A2,temp1,m/2,1);
  Matrix_multiplication(temp1,B4,G,m/2);
  //H=(A3-A1)(B1+B2)
  Matrix_add_sub(A3,A1,temp1,m/2,0);
  Matrix_add_sub(B1,B2,temp2,m/2,1);
  Matrix_multiplication(temp1,temp2,H,m/2);
  //I=(A2-A4)(B3+B4)
  Matrix_add_sub(A2,A4,temp1,m/2,0);
  Matrix_add_sub(B3,B4,temp2,m/2,1);
  Matrix_multiplication(temp1,temp2,I,m/2);
  //J=(A1+A4)(B1+B4)
  Matrix_add_sub(A1,A4,temp1,m/2,1);
  Matrix_add_sub(B1,B4,temp2,m/2,1);
  Matrix_multiplication(temp1,temp2,J,m/2);
  //利用Strassen方法计算C1、C2、C3、C4
  //C1=E+I+J-G
  Matrix_add_sub(E,I,temp1,m/2,1);
  Matrix_add_sub(J,G,temp2,m/2,0);
  Matrix_add_sub(temp1,temp2,C1,m/2,1);
  //C2=D+G
  Matrix_add_sub(D,G,C2,m/2,1);
  //C3=E+F
  Matrix_add_sub(E,F,C3,m/2,1);
  //C4=D+H+J-F
  Matrix_add_sub(D,H,temp1,m/2,1);
  Matrix_add_sub(J,F,temp2,m/2,0);
  Matrix_add_sub(temp1,temp2,C4,m/2,1);
  //将计算结果存入数组C
  UpdateHalfValue(C1,&C[0],m);
  UpdateHalfValue(C2,&C[m/2],m);
  UpdateHalfValue(C3,&C[m*m/2],m);
  UpdateHalfValue(C4,&C[m*m/2+m/2],m);
  //释放内存
  //free(A1);
  //free(A2);free(A3);free(A4);free(B1);free(B2);free(B3);free(B4);free(C1);free(C2);free(C3);free(C4);
	//free(D);free(E);free(F);free(G);free(H);free(I);free(J);free(temp1);free(temp2);
 }
 else
 {
  //当矩阵维数小于2时用Strassen方法计算矩阵乘积
  mytype D,E,F,G,H,I,J;
  //D=A1(B2-B4)
  D=A[0]*(B[1]-B[3]);
  //E=A4(B3-B1)
  E=A[3]*(B[2]-B[0]);
  //F=(A3+A4)B1
  F=(A[2]+A[3])*B[0];
  //G=(A1+A2)B4
  G=(A[0]+A[1])*B[3];
  //H=(A3-A1)(B1+B2)
  H=(A[2]-A[0])*(B[0]+B[1]);
  //I=(A2-A4)(B3+B4)
  I=(A[1]-A[3])*(B[2]+B[3]);
  //J=(A1+A4)(B1+B4)
  J=(A[0]+A[3])*(B[0]+B[3]);
  //C1=E+I+J-G
  C[0]=E+I+J-G;
  //C2=D+G
  C[1]=D+G;
  //C3=E+F
  C[2]=E+F;
  //C4=D+H+J-F
  C[3]=D+H+J-F;
 }
}
/////////////////////////////////////////
int main()
{
 int N;
 FILE *fp;
int i=0,j,l,m=0,k=0,n=0,w=0,x=1;
char s[300],ch,pre;
int a[200][200]={0},b[200][200]={0},c[200][200]={0};
  mytype *A,*B,*C;
 //提示输入n维矩阵的维数
//printf("Please input the dimension of the Matrix.(n):");
 //获得用户输入的n维矩阵维数
 if((fp=fopen("arr.in","r"))==NULL){
		puts("wrong");
		exit(0);
	}
	while(1){
		fscanf(fp,"%d",&j);
		ch=fgetc(fp);
		k++;
		if(ch=='\n'||ch=='\r')
			break;
	}
	m++;
	pre=ch;
	while(1){
		ch=fgetc(fp);
		if(pre=='\n'&&ch=='\n')
			break;
		else{
			if(ch=='\n')
				m++;
			pre=ch;
		}
	}
	
	rewind(fp);
	for(i=1;i<=m;i++)
		for(j=1;j<=k;j++)
			fscanf(fp,"%d",&a[i][j]);
	fgets(s,20,fp);
	for(i=1;i<=k;i++){
		
		j=1;
		fscanf(fp,"%d",&b[i][j++]);
		ch=fgetc(fp);
		while(ch!='\n'&&ch!='\r'&&ch!=EOF){
			fscanf(fp,"%d",&b[i][j++]);
			ch=fgetc(fp);
		}
	}
	n=j-1;
	N=m>n?m:n;
	
	N=N>k?N:k;
	if(!is2(N)){
		while(1){
			x=x*2;
			if(x>N){
				N=x;
				break;
			}
		}
	}
	/*for(i=1;i<=N;i++){
		for(j=1;j<=N;j++)
			printf("%d ",a[i][j]);
		puts("");
	}
	puts("");
	for(i=1;i<=N;i++){
		for(j=1;j<=N;j++)
			printf("%d ",b[i][j]);
		puts("");
	}
	printf("N=%d ",N);puts("");/**/
 //scanf("%d",&N);
 
 //开辟空间存储用来存储n维矩阵元素
 A=(mytype*)malloc(sizeof(mytype)*N*N);
 B=(mytype*)malloc(sizeof(mytype)*N*N);
 C=(mytype*)malloc(sizeof(mytype)*N*N);
 //输入矩阵A、B
 inputmatrix(A,N,"A",a);
 inputmatrix(B,N,"B",b);
 /*printmatrix(A,N,N,"A");
 puts("");
printmatrix(B,N,N,"B");
puts("");*/
 if(N>1)//矩阵维数大于1则用分而治之算法计算
  Matrix_multiplication(A,B,C,N);
 else//矩阵维数为1则直接计算
  *C=(*A)*(*B);
 //输出矩阵A、B、C
 
 printmatrix2(C,N,m,n,"C");
 //puts("");
 //释放内存
 //free(A);free(B);free(C);
 //getchar();getchar();
 return 1;
}
