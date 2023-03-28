#include<stdio.h>
#include<math.h>
void insertionsort(int arr[],int n)
{
	int i,j,key;
	for(i=1;i<n;i++)
	{
		key=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j=j-1;
		}
	arr[j+1]=key;
	}
}
void printarr(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%d ",arr[i]);
}
int main()
{
	int n;
	int arr[]={12,11,9,88,22,8};
	n=sizeof(arr)/sizeof(arr[0]);
	insertionsort(arr,n);
	printarr(arr,n);
}
