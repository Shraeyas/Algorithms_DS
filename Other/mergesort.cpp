#include<iostream>
#include<stdlib.h>

using namespace std;

//int l=0;

void merge(int *left, int x, int *right, int y, int *a)
{
	int l=0,i,j;
	
	//cout<<n<<endl;
	for(i=0,j=0;i<x && j<y;)
	{
		if(left[i]<=right[j])
		{
			a[l++] = left[i++];
		}
		
		else
		{
			a[l++] = right[j++];	
		}
	}
	

	{
		while(i<x)
		{
			a[l++] = left[i++];
		}
	}
	
	{
		while(j<y)
		{
			a[l++] = right[j++];
		}
	}
	
	//for(int i=0;i<l;i++)
	//cout<<a[i]<<" ";
	
	//cout<<l<<endl;
}

void mergesort(int *a,int n)
{
	//cout<<n<<endl;
	if(n<2)
	return;
	
	int *left = new int [n/2];
	int *right = new int [n - n/2];
	
	//cout<<"left"<<endl;
	
	for(int i=0;i<n/2;i++)
	{
		left[i] = a[i];
		//cout<<a[i]<<" ";
	}
	
	//cout<<endl;
	
	//cout<<"right"<<endl;
	int p=0;
	
	for(int i=n/2;i<n;i++)
	{
		//p++;
		right[p++] = a[i];
		//cout<<a[i]<<" ";
	}
	
	//cout<<endl;
	
	mergesort(left,n/2);
	mergesort(right,p);
	
	merge(left,n/2,right,p,a);
	
	free(left);
	free(right);
}

int main()
{
	int a[]={10,2,7,3,1001,123,5,7,45,99,111},n=11;
	mergesort(a,n);
	
	for(int i=0;i<11;i++)
	cout<<a[i]<<" ";
}
