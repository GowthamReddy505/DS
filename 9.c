#include<stdio.h>
#include<conio.h>
#define SIZE 10
void push(int);
void pop();
void display();
int stack[SIZE],top=-1;
main()
{
	int value,ch;
	while(1)
	{
		printf("\n* * * MENU * * *\n");
		printf("1.push\t2.pop\t3.display\t4.exit\n");
		printf("enter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter value to be inserted: ");
				scanf("%d",&value);
				push(value);
				break;
			case 2:pop();
				break;
			case 3:display();
				break;
			case 4:exit(0);
		}
	}
}
void push(int value)
{
	if(top==SIZE-1)
		printf("stack is full\n");
	top++;
	stack[top]=value;
	printf("insertion success\n");
}
void pop()
{
	if(top==-1)
		printf("stack is empty\n");
	printf("deleted=%d",stack[top]);
	top--;
}
void display()
{
	if(top==-1)
	printf("stack is empty\n");
	else
	{
		int i;
		printf("stack elements are\n");
		for(i=top;i>=0;i--)
			printf("%d ",stack[i]);
		}
}