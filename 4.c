#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void merge(int a[],int l,int m,int r)
{
	int i,j,k;
	int n1=m-l+1;
	int n2=r-m;
	int L[10],R[10];
	for(i=0;i<n1;i++)
		L[i]=a[l+i];
		for(j=0;j<n2;j++)
			R[j]=a[m+j+1];
	i=0;
	j=0;
	k=l;
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j]){
			a[k]=L[i];
			i++;
		}
		else
		{
			a[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		a[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		a[k]=R[j];
		j++;
		k++;
	}
}
void mergesort(int a[],int l,int r)
{
	if(l<r)
	{
		int m=l+(r-l)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,r);
		merge(a,l,m,r);
	}
}
void printarr(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
}
int main()
{
	int n;
	int arr[]={99,12,6,34,33,4,1};
	n=sizeof(arr)/sizeof(arr[0]);
	mergesort(arr,0,n-1);
	printarr(arr,n);
	getch();
	return 0;
}