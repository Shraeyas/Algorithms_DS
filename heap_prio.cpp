#include<iostream>
#include<map>
#include<stack>
#include<queue>

using namespace std;

map<int, int>heap;
int size = 0;

int par(int i)
{
	return (i-1)/2;
}

int lc(int i)
{
	return 2*i + 1;
}

int rc(int i)
{
	return 2*i + 2;
}

void print()
{
	for(int i=0;i<size;i++)
	printf("%d ",heap[i]);
}

void per_up(int i)
{
	int par_ = par(i), lc_ = lc(i), rc_ = rc(i);
	
	while(heap[i] < heap[par_] && par_>=0)
	{
		int pra = heap[par_];
		heap[par_] = heap[i];
		heap[i] = pra;
		
		i = par_;
		par_ = par(par_);
	}
}

int main()
{
	while(1)
	{
		int x;
		scanf("%d", &x);
		
		if(x == 1)
		break;
		
		heap[size++] = x;
		per_up(size-1);
	}
	
	print();
}
