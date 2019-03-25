#include "stdio.h"
#include<stdlib.h>
#define mytype int//����Ԫ�ص���������
#define myinputmode "%d"//����Ԫ�ص������ʽ
#define myprintmode "%4d"//����Ԫ�ص������ʽ
/*���ϲ��������ÿɸ�������������Ԫ�ص���ֵ���ͽ�����Ӧ�ı�
�����Ϊ���������������ʹ�����������
#define mytype float
#define myinputmode "%f"
#define myprintmode "%6.2f"
*/
/////////////////////////////////////////
/****************************************
��������is2
������mΪ����������
���ܣ����m�Ƿ���2������������
����ֵ�����ز����ͱ���
        true���ʾmΪ2������������
  false���ʾm����2������������
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
��������inputmatrix
������MΪָ�������ָ�룬�����洢����ľ���
      m�����ͣ�������M��������ά��
   name�ַ������飬����Ҫ������������ľ��������
���ܣ�������������ĺ�����ͨ����������ÿ��Ԫ�ؽ�
      �����������
����ֵ����
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
��������printmatrix
������MΪָ�������ָ�룬�����д洢�ž���
      m�����ͣ�������M��������ά��
   name�ַ������飬����Ҫ������������ľ��������
���ܣ��������������ʾ�ĺ�����������Ԫ��һһ��ʾһ����Ļ��
����ֵ����
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
��������Matrix_add_sub
������A��BΪָ�������ָ�룬�����д洢�ž���
   CΪָ�������ָ�룬�����洢������
      m�����ͣ�������A��B��C��������ά��
   addΪ�����ͱ�����Ϊtrue��C=A+B��Ϊfalse��C=A-B
���ܣ�����addֵ��A��B���мӼ����㲢���������C
����ֵ����
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
��������GetHalfValue
������BΪָ�������ָ�룬�����д洢�ž�������B��ָ��mά�����е�һ��Ԫ�ء�
   AΪָ�������ָ�룬��������B�е��ķ�֮һ����
      m�����ͣ�������B��ָ�����ά��
���ܣ���B����λ�����������ȡ�����m/2ά���Ӿ����Ӿ����а���B��ָԪ�أ�������A
����ֵ����
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
��������UpdateHalfValue
������BΪָ�������ָ�룬�����д洢�ž�������B��ָ��mά�����е�һ��Ԫ�ء�
   AΪָ�������ָ�룬�洢��һ��m/2ά����
      m�����ͣ�������B��ָ�����ά��
���ܣ���A��������Ԫ�ش����B����λ����������ҵ�m/2ά���Ӿ����Ӿ����а���B��ָԪ�أ�
����ֵ����
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
��������Matrix_multiplication
������A��BΪָ�������ָ�룬�����д洢�ž���
   CΪָ�������ָ�룬�����洢������
      m�����ͣ���ָ��A��B��ָ�����ά��
���ܣ��÷ֶ���֮�㷨��Strassen��������A��B�ĳ˻�������C
����ֵ����
****************************************/
void Matrix_multiplication(mytype * A,mytype * B,mytype * C,int m)
{
 if(m>2)//������ά������2ʱ
 {
	//������A��B��Ϊ�ĸ�С���󣬷ֱ�ΪA1��A2��A3��A4��B1��B2��B3��B4;
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
  //����Strassen��������D��E��F��G��H��I��J
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
  //����Strassen��������C1��C2��C3��C4
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
  //����������������C
  UpdateHalfValue(C1,&C[0],m);
  UpdateHalfValue(C2,&C[m/2],m);
  UpdateHalfValue(C3,&C[m*m/2],m);
  UpdateHalfValue(C4,&C[m*m/2+m/2],m);
  //�ͷ��ڴ�
  //free(A1);
  //free(A2);free(A3);free(A4);free(B1);free(B2);free(B3);free(B4);free(C1);free(C2);free(C3);free(C4);
	//free(D);free(E);free(F);free(G);free(H);free(I);free(J);free(temp1);free(temp2);
 }
 else
 {
  //������ά��С��2ʱ��Strassen�����������˻�
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
 //��ʾ����nά�����ά��
//printf("Please input the dimension of the Matrix.(n):");
 //����û������nά����ά��
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
 
 //���ٿռ�洢�����洢nά����Ԫ��
 A=(mytype*)malloc(sizeof(mytype)*N*N);
 B=(mytype*)malloc(sizeof(mytype)*N*N);
 C=(mytype*)malloc(sizeof(mytype)*N*N);
 //�������A��B
 inputmatrix(A,N,"A",a);
 inputmatrix(B,N,"B",b);
 /*printmatrix(A,N,N,"A");
 puts("");
printmatrix(B,N,N,"B");
puts("");*/
 if(N>1)//����ά������1���÷ֶ���֮�㷨����
  Matrix_multiplication(A,B,C,N);
 else//����ά��Ϊ1��ֱ�Ӽ���
  *C=(*A)*(*B);
 //�������A��B��C
 
 printmatrix2(C,N,m,n,"C");
 //puts("");
 //�ͷ��ڴ�
 //free(A);free(B);free(C);
 //getchar();getchar();
 return 1;
}
