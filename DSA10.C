#include<stdio.h>
#define max 100
#include<ctype.h>
#include<string.h>
int stack[max];
int top=-1;
void push(int item)
{
 if(top==max-1) printf("stack overflow");
 else{
 top++;
 stack[top]=item;
 }
}
int pop()
{
 int i;
 if(top==-1) printf("stack underflow");
 else
 {
 i=stack[top];
 top--;
 return i;
 }
 return 0;
}
void eval(char post[])
{
 char ch;
 int i,A,B,val;
 for(i=0;post[i]!=')';i++)
 {
 ch=post[i];
 if(isdigit(ch))
 push(ch-'0');
 else if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
 {
 A=pop();
 B=pop();
 switch(ch)
 {
 case '+':val=B+A;
 break;
 case '-':val=B-A;
 break;
 case '*':val=B*A;
 break;
 case '/':val=B/A;
 break;
 }
 push(val);
 }
 }
 printf("The result is:%d",pop());
}
int main()
{
 int i;
 char ch,post[max];
 printf("Enter the postfix exp:");
 for(i=0;i<max-1;i++)
 {
 scanf("%s",&post[i]);
 if(post[i]==')');break;
 }
 eval(post);
}