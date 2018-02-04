#include<iostream>
#define MAX 100000
#define MAX2 400000

using namespace std;

int *a = new int[MAX];
int *segtree = new int[MAX2];

void construct(long lo, long hi, long pos)
{
	if(lo == hi)
	{
		segtree[pos] = a[lo];
		return;
	}
	
	long mid = lo + (hi - lo)/2;
	
	construct(lo, mid, 2*pos+1);
	construct(mid+1, hi, 2*pos+2);
	
	segtree[pos] = min(segtree[2*pos+1], segtree[2*pos+2]);
}

int query(long qlo, long qhi, long lo, long hi, long pos)
{
	if(qlo>hi || qhi<lo)
	{
		return 999999;
	}
	
	if(qlo<=lo && qhi>=hi)
	{
		return segtree[pos];
	}
	
	long mid = lo + (hi - lo)/2;
	
	return min(query(qlo, qhi, lo, mid, 2*pos+1), query(qlo, qhi, mid+1, hi, 2*pos+2));
}

int main()
{
	freopen("C:\\Users\\Shraeyas\\Documents\\pg\\pr_ag\\prag_RMQSQ.txt", "r", stdin);
	
	long n;
	scanf("%ld",&n);
	
	for(long i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}
	
	construct(0, n-1, 0);
	
	int q;
	scanf("%d", &q);
	
	for(int i=0;i<q;i++)
	{
		long x, y;
		scanf("%ld %ld",&x, &y);
		
		printf("%d\n", query(x, y, 0, n-1, 0));
	}
}
