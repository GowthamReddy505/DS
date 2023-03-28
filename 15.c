#include<stdio.h>
#include<conio.h>
struct dlist
{
	int no;
	struct dlist *lptr;
	struct dlist *rptr;
};
typedef struct dlist node;
node *start,*prev,*cur,*new1,*head;
void create();
void insert();
void del();
void display();
void main()
{
	int ch;
	char c;
	clrscr();
	do
	{
		printf("1.create\n2.insert\n3.delete\n4.display\n");
		printf("enter choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:create();
			break;
		case 2:insert();
			break;
		case 3:del();
			break;
		case 4:display();
			break;
		}
		printf("do u want to continue\n");
		c=getche();
	}while(c=='y');
	getch();
}
void create()
{
	new1=(node*)malloc(sizeof(node));
	printf("enter info\n");
	scanf("%d",&new1->no);
	new1->lptr=NULL;
	new1->rptr=NULL;
	head=new1;
}
void insert()
{
	int key,ch;
	clrscr();
	printf("1.beg\n2.mid\n3.end\n");
	printf("enter your choice\n");
	scanf("%d",&ch);
	new1=(node*)malloc(sizeof(node));
	printf("enter data\n");
	scanf("%d",&new1->no);
	cur=head;
	switch(ch)
	{
	case 1:new1->lptr=NULL;
		new1->rptr=cur;
		head=new1;
		break;
	case 2:printf("enter after which node to insert\n");
		scanf("%d",&key);
		while(cur->no!=key)
			cur=cur->rptr;
		new1->lptr=cur;
		new1->rptr=cur->rptr;
		cur->rptr=new1;
		new1->rptr->lptr=new1;
		break;
	case 3:while(cur->rptr!=NULL)
		cur=cur->rptr;
		new1->lptr=cur;
		new1->rptr=NULL;
		cur->rptr=new1;
		break;
	}
}
void del()
{
	int key,ch;
	clrscr();
	printf("1.beg\n2.mid\n3.end\n");
	printf("enter your choice\n");
	scanf("%d",&ch);
	cur=head;
	switch(ch)
	{
	case 1:head=cur->rptr;
		cur->rptr->lptr=NULL;
		free(cur);
		break;
	case 2:printf("enter which node to delete\n");
		scanf("%d",&key);
		while(cur->no!=key)
		{
			prev=cur;
			cur=cur->rptr;
		}
		cur->rptr->lptr=cur->lptr;
		prev->rptr=cur->rptr;
		break;
	case 3:while(cur->rptr!=NULL)
		{
			prev=cur;
			cur=cur->rptr;
		}
		prev->rptr=NULL;
		free(cur);
		break;
	}
}
void display()
{
	cur=head;
	while(cur!=NULL)
	{
		printf("%d<->",cur->no);
		cur=cur->rptr;
	}
}

