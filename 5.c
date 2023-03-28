#include<stdio.h>
void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
int partition(int arr[],int low,int high)
{
	int pivot=arr[high];
	int i=low-1,j;
	for(j=low;j<=high-1;j++)
	{
		if(arr[j]<pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return(i+1);
}
int quick(int arr[],int low,int high)
{
	if(low<high)
	{
		int p=partition(arr,low,high);
		quick(arr,low,p-1);
		quick(arr,p+1,high);
	}   return 0;
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
	int arr[]={99,12,8,4,65,3,9,1};
	n=sizeof(arr)/sizeof(arr[0]);
	quick(arr,0,n-1);
	printarr(arr,n);
}