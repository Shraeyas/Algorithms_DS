#include <iostream>

using namespace std;

struct eo
{
	int even;
	int odd;
};

void build(int *a, int lo, int hi, eo *segtree, int pos)
{
	if(lo == hi)
	{
		if(a[lo] % 2)
		{
			segtree[pos].odd = 1;
			segtree[pos].even = 0;
		}
		
		else
		{
			segtree[pos].odd = 0;
			segtree[pos].even = 1;
		}
		
		return;
	}
	
	int mid = (lo + hi)/2;
	
	build(a, lo, mid, segtree, 2 * pos + 1);
	build(a, mid + 1, hi, segtree, 2 * pos + 2);
	
	segtree[pos].even = segtree[2 * pos + 1].even + segtree[2 * pos + 2].even;
	segtree[pos].odd = segtree[2 * pos + 1].odd + segtree[2 * pos + 2].odd;
}

void update(int *a, int lo, int hi, eo *segtree, int pos, int ind, int val)
{
	if(lo == hi)
	{
		segtree[pos].even = 0, segtree[pos].odd = 0;
		
		if(val % 2)
		{
			segtree[pos].odd = 1;
			segtree[pos].even = 0;
		}
		
		else
		{
			segtree[pos].odd = 0;
			segtree[pos].even = 1;
		}
		
		a[lo] = val;
		
		return;
	}
	
	int mid = (lo + hi)/2;
	
	if(ind <= mid)
	update(a, lo, mid, segtree, 2 * pos + 1, ind, val);
	
	else
	update(a, mid + 1, hi, segtree, 2 * pos + 2, ind, val);
	
	segtree[pos].even = segtree[2 * pos + 1].even + segtree[2 * pos + 2].even;
	segtree[pos].odd = segtree[2 * pos + 1].odd + segtree[2 * pos + 2].odd;
}

eo query(int *a, int lo, int hi, eo *segtree, int pos, int qlo, int qhi)
{
	if(qlo <= lo && qhi >= hi)
	{
		return segtree[pos];
	}
	
	if(qlo > hi || qhi < lo)
	{
		eo ret;
		ret.even = 0, ret.odd = 0;
		return ret;
	}
	
	int mid = (lo + hi)/2;
	eo x = query(a, lo, mid, segtree, 2 * pos + 1, qlo, qhi);
	eo y = query(a, mid + 1, hi, segtree, 2 * pos + 2, qlo, qhi);
	
	eo ans;
	ans.even = x.even + y.even, ans.odd = x.odd + y.odd;
	
	return ans;
}

int main()
{
	freopen("in.in", "r", stdin);

	int n;
	cin >> n;
	
	int *a = new int[n];
	
	for(int i = 0 ; i < n ; i++)
	{
		cin >> a[i];
	}
	
	eo *segtree = new eo [4 * n];
	
	build(a, 0, n - 1, segtree, 0);
	
	int q;
	cin >> q;
	
	while(q--)
	{
		int c, lo, hi;
		cin >> c >> lo >> hi;
		
		if(c == 0)
		{
			update(a, 0, n - 1, segtree, 0, lo - 1, hi);
		}
		
		else
		{
			eo ans = query(a, 0, n - 1, segtree, 0, lo - 1, hi - 1);
			
			if(c % 2)
			{
				cout << ans.odd << endl;
			}
			
			else
			{
				cout << ans.even << endl;
			}
		}
	}
}
