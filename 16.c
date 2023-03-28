#include<stdio.h>
#include<malloc.h>
struct slist
{
 int co;
 int po;
 struct slist *ptr;
};
typedef struct slist node;
node *head,*head1,*head2,*new1,*cur,*start1,*start2;
void create(node *head)
{
 cur=head;
 int i;
 do{
 new1=(node*)malloc(sizeof(node));
 printf("Enter the Coeff:");
 scanf("%d",&new1->co);
 printf("Enter the power:");
 scanf("%d",&new1->po);
 new1->ptr=NULL;
 cur->ptr=new1;
 cur=new1;
 printf("do you want to continue?? if yes 1:");
 scanf("%d",&i);
 }while(i==1);
}
void display(node *head)
{
 cur=head->ptr;
 while(cur!=NULL)
 {
 printf("%d^%d+",cur->co,cur->po);
 cur=cur->ptr;
 }
}
void polyadd(node *head1,node *head2)
{
 start1=head1->ptr;
 start2=head2->ptr;
 printf("\n\nThe added polynomial is:\n");
 while(start1!=NULL&&start2!=NULL)
 {
 if(start1->po==start2->po)
 {
 printf("%d^%d+",start1->co+start2->co,start1->po);
 start1=start1->ptr;
 start2=start2->ptr;
 }
 else if(start1->po>start2->po)
 {
 printf("%d^%d+",start1->co,start1->po);
 start1=start1->ptr;
 }
 else
 {
 printf("%d^%d+",start2->co,start2->po);
 start2=start2->ptr;
 }
 }
 while(start1!=NULL)
 {
 printf("%d^%d+",start1->co,start1->po);
 start1=start1->ptr;
 }
 while(start2!=NULL)
 {
 printf("%d^%d+",start2->co,start2->po);
 start2=start2->ptr;
 }
}
int main()
{
 head1=(node*)malloc(sizeof(node));
 printf("Enter the first polynomial:\n");
 create(head1);
 printf("The first polynomial is:\n");
 display(head1);
 head2=(node*)malloc(sizeof(node));
 printf("\nEnter the second polynomial:\n");
 create(head2);
 printf("The second polynomial is:\n");
 display(head2);
 polyadd(head1,head2);
}
