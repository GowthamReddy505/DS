#include<stdio.h>
#define max 100
#include<ctype.h>
#include<string.h>
char stack[max];
int top=-1;
void push(char val)
{
 if(top==max-1) printf("stack oberflow");
 else{
 top++;
 stack[top]=val;
 }
}
char pop()
{
 char i;
 if (top==-1) printf("stack underflow");
 else{
 i=stack[top];
 top--;
 return i;
 }
 return 0;
}
int isop(char sy)
{
 if(sy=='*'||sy=='/'||sy=='+'||sy=='-'||sy=='^')
 return 1;
 else
 return 0;
}
int pre(char sy)
{
 if(sy=='^') return 3;
 else if(sy=='*'||sy=='/') return 2;
 else if(sy=='+'||sy=='-') return 1;
 else return 0;
}
void intopo(char in[],char po[])
{
 int i,j;
 char x,item;
 push('(');
 strcat(in,")");
 i=0;
 j=0;
 item=in[i];
 while(item!='\0')
 {
 if(item=='(')
 push(item);
 else if(isdigit(item)||isalpha(item))
 {
 po[j]=item;
 j++;
 }
 else if(isop(item)==1)
 {
 x=pop();
 while(isop(x)==1&&pre(x)>=pre(item))
 {
 po[j]=x;
 j++;
 x=pop();
 }
 push(x);
 push(item);
 }
 else if(item==')')
 {
 x=pop();
 while(x!='(')
 {
 po[j]=x;
 j++;
 x=pop();
 }
 }
 else
 {
 printf("invalid infix expression!!!");
 }
 i++;
 item=in[i];
 }
 if(top>-1)
 {
 printf("invalid infix expression!!!");
 }
 po[j]='\0';
}
int main()
{
 char po[max],in[max];
 printf("Enter the infix expression:");
 gets(in);
 intopo(in,po);
 printf("The postfix expression is:%s",po);
 return 0;
}
*/
/*
#include<stdio.h>
int main()
{
 int a[6]={4,1,8,6,2,7};
 int n,i,j,temp;
 for(i=0;i<6;i++)
 {
 for(j=0;j<6;j++)
 {
 if(a[j]>a[j+1])
 {
 temp=a[j];
 a[j]=a[j+1];
 a[j+1]=temp;
 }
 }
 }
 for(i=0;i<6;i++)
 {
 printf("%d,",a[i]);
 }
}
