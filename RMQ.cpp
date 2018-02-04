#include <iostream>

using namespace std;

void build(int *a, int lo, int hi, int *segtree, int pos)
{
	if(lo == hi)
	{
		segtree[pos] = a[lo];
		return;
	}
	
	int mid = (lo + hi)/2;
	
	build(a, lo, mid, segtree, 2 * pos + 1);
	build(a, mid + 1, hi, segtree, 2 * pos + 2);
	
	segtree[pos] = min(segtree[2 * pos + 1], segtree[2 * pos + 2]);
}

int query(int *a, int lo, int hi, int *segtree, int pos, int qlo, int qhi)
{
	if(qlo <= lo && qhi >= hi)
	{
		return segtree[pos];
	}
	
	if(qlo > hi || qhi < lo)
	{
		return INT_MAX;
	}
	
	int mid = (lo + hi)/2;
	return min(query(a, lo, mid, segtree, 2 * pos + 1, qlo, qhi), query(a, mid + 1, hi, segtree, 2 * pos + 2, qlo, qhi));
}

void update(int *a, int lo, int hi, int *segtree, int pos, int ind, int val)
{
	if(lo == hi)
	{
		a[lo] = val;
		return;
	}
	
	int mid = (lo + hi)/2;
	
	if(ind <= mid)
	update(a, lo, mid, segtree, 2 * pos + 1, ind, val);
	
	else
	update(a, mid + 1, hi, segtree, 2 * pos + 2, ind, val);
	
	segtree[pos] = min(segtree[2 * pos + 1], segtree[2 * pos + 2]);
}

int main()
{
	freopen("in.in", "r", stdin);
	
	int n, q;
	cin >> n >> q;
	
	int *a = new int [n];
	
	for(int i = 0 ; i < n ; i++)
	{
		cin >> a[i];
	}
	
	int * segtree = new int [4 * n];
	
	build(a, 0, n - 1, segtree, 0);
	
	while(q--)
	{
		char c;
		int lo, hi;
		cin >> c >> lo >> hi;
		
		if(c == 'q')
		{
			cout << query(a, 0, n - 1, segtree, 0, lo - 1, hi - 1) << endl;
		}
		
		else
		{
			update(a, 0, n - 1, segtree, 0, lo - 1, hi);
		}
	}
}
