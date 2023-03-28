#include<stdio.h>
int binary(int arr[],int l,int r,int x)
{
	if(r>=l)
	{
		int mid=l+(r-l)/2;
		if(arr[mid]==x)
		{
			return mid;
		}
		if(arr[mid]>x)
		{
			return binary(arr,l,mid-1,x);
		}
		return binary(arr,mid+1,r,x);
	}
	return -1;
}
void main()
{
	int n,x,res;
	int arr[]={2,5,9,22,36,42,54,67};
	n=sizeof(arr)/sizeof(arr[0]);
	x=42;
	res=binary(arr,0,n-1,x);
	if(res==-1)
		printf("not found");
	else
		printf("element found at index %d",res);
}