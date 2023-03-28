#include<stdio.h>
#include<conio.h>
void main()
{
	int x,y,*a,*b,t;
	printf("enter values of x and y\n");
	scanf("%d\n%d",&x,&y);
	printf("before swapping\nx=%d\ny=%d\n",x,y);
	a=&x;
	b=&y;
	t=*a;
	*a=*b;
	*b=t;
	printf("after swapping\nx=%d\ny=%d\n",x,y);
	getch();
	clrscr();
}