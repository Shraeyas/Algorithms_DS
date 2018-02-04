#include<iostream>

using namespace std;

int partition(int *a, int start, int end)
{
	int pindex = start;
	int pivot = a[end];
	
	for(int i = start; i <= end-1; i++)
	{
		if(a[i] <= pivot)
		{
			int temp = a[pindex];
			a[pindex] = a[i];
			a[i] = temp;
			pindex++;
		}
	}
	
	int temp = a[pindex];
	a[pindex] = a[end];
	a[end] = temp;
			
	return pindex;
}

void quicksort(int *a, int start, int end)
{
	if(start >= end)
	return;
	
	//cout<<"in"<<endl;
	
	int p_in = partition(a, start, end);
	quicksort(a, start, p_in-1);
	quicksort(a, p_in+1, end);
}

int main()
{
	int a[] = {1,0,2,9,8,3,4,7,5,6};
	quicksort(a,0,9);
	
	for(int i=0;i<=9;i++)
	cout<<a[i]<<" ";
}
