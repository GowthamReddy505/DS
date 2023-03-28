#include<stdio.h>
#include<conio.h>
void selectionsort(int arr[],int n)
{
	int i,j,small,temp;
	for(i=0;i<n;i++)
	{
		small=i;
		for(j=i+1;j<n;j++) if(arr[j]<arr[small])
			small=j;
		temp=arr[small];
		arr[small]=arr[i];
		arr[i]=temp;
	}
}
void printarr(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%d ",arr[i]);
}
void main()
{
	int n;
	int arr[]={12,31,25,8,32,17};
	n=sizeof(arr)/sizeof(arr[0]);
	selectionsort(arr,n);
	printarr(arr,n);
}