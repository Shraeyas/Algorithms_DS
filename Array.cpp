#include<iostream>
#include<map>
#include<stdio.h>

using namespace std;

map<long,long>segtree, a;

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
	
	segtree[pos] = max(segtree[2*pos + 1], segtree[2*pos + 2]);
}

long query(long qlo, long qhi, long lo, long hi, long pos)
{
	if(qlo<=lo && qhi>=hi)
	{
		return segtree[pos];
	}
	
	if(qlo>hi || qhi<lo)
	{
		return -1;
	}
	
	long mid = lo + (hi - lo)/2;
	return max(query(qlo, qhi, lo, mid, 2*pos + 1), query(qlo, qhi, mid+1, hi, 2*pos + 2));
}

int main()
{
	freopen("C:\\Users\\Shraeyas\\Documents\\pg\\pr_ag\\prag_arsub.txt", "r", stdin);	
	
	long n;
	scanf("%ld",&n);
	
	for(long i=0;i<n;i++)
	{
		scanf("%ld",&a[i]);
	}
	
	construct(0, n-1, 0);
	
	long k;
	scanf("%ld", &k);
	
	for(long i=0;i<n-k+1;i++)
	{
		printf("%ld ", query(i, i+k-1, 0, n-1, 0));
	}
}
