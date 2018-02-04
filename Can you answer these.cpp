#include<iostream>
#include<map>

using namespace std;

struct node
{
	long long c_s;
};

map<long long, node>segtree;
map<long long, long long>a;

void build(long long lo, long long hi, long long pos)
{
	if(lo == hi)
	{
		segtree[pos].c_s = a[lo];
		return;
	}
	
	long long mid = lo + (hi - lo)/2;
	
	build(lo, mid, 2*pos + 1);
	build(mid + 1, hi, 2*pos + 2);
	
	segtree[pos].c_s = segtree[2*pos + 1].c_s + segtree[2*pos + 2].c_s;
}

long long query(long long lo, long long hi, long long qlo, long long qhi, long long pos)
{
	if(qlo<=lo && qhi>=hi)
	{
		return segtree[pos].c_s;
	}
	
	if(qlo>hi || qhi<lo)
	return 0;
	
	long long mid = lo + (hi-lo)/2;
	
	return query(lo, mid, qlo, qhi, 2*pos+1) + query(mid + 1, hi, qlo, qhi, 2*pos+2);
}

int main()
{
	ios::sync_with_stdio(0);
	
	long n;
	cin>>n;
	
	for(long i=0;i<n;i++)
	cin>>a[i];
	
	build(0,n-1,0);
	
	long long m;
	cin>>m;
	
	for(long long i=0;i<m;i++)
	{
		long long x, y;
		
		cin>>x>>y;
		x--, y--;
		
		cout<<query(0, n-1, x, y, 0)<<endl;
	}
}
