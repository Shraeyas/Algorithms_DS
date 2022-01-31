#include <iostream>

using namespace std;

struct node
{
	long long val, len;
};


long long pow(long long x, long long y)
{
  long long res = 1;
  
  while(y)
  {
    if(y & 1)
      res = (res * x) % 3;
      
	x = (x * x) % 3;
    y >>= 1;
  }
  
  return res;
}

node combine(node a, node b)
{
	node ans;
	
	if(a.len == 0)
	return b;
	
	if(b.len == 0)
	return a;
	
	ans.len = a.len + b.len;
	ans.val = ((pow(2, b.len) * a.val) % 3 + b.val % 3) % 3;
	
	return ans;
}


void build(string &s, long long lo, long long hi, node *segtree, long long pos)
{
	if(lo == hi)
	{
		segtree[pos].val = (s[lo] == '1' ? 1 : 0);
		segtree[pos].len = 1;
		
		return;
	}
	
	long long mid = (lo + hi)/2;
	
	build(s, lo, mid, segtree, 2 * pos + 1);
	build(s, mid + 1, hi, segtree, 2 * pos + 2);
	
	segtree[pos] = combine(segtree[2 * pos + 1], segtree[2 * pos + 2]);
}

node query(long long lo, long long hi, node *segtree, long long pos, long long qlo, long long qhi)
{
	if(qlo <= lo && qhi >= hi)
	{
		return segtree[pos];
	}
	
	if(qlo > hi || qhi < lo)
	{
		node ans;
		
		ans.val = 0;
		ans.len = 0;
		
		return ans;
	}
	
	long long mid = (lo + hi)/2;
	
	node l = query(lo, mid, segtree, 2 * pos + 1, qlo, qhi);
	node r = query(mid + 1, hi, segtree, 2 * pos + 2, qlo, qhi);
	
	return combine(l, r);
}

void update(string &a, long long lo, long long hi, node *segtree, long long pos, long long ind)
{
	if(lo == hi)
	{
		a[lo] = '1';
		segtree[pos].val = 1;
		
		return;
	}
	
	long long mid = (lo + hi)/2;
	
	if(ind <= mid)
	{
		update(a, lo, mid, segtree, 2 * pos + 1, ind);
	}
	
	else
	{
		update(a, mid + 1, hi, segtree, 2 * pos + 2, ind);
	}
	
	segtree[pos] = combine(segtree[2 * pos + 1], segtree[2 * pos + 2]);
}

int main()
{
	freopen("in.in", "r", stdin);
	
	long long n;
	cin >> n;
	
	string s;
	cin >> s;
	
	node *segtree = new node [3 * n];
	build(s, 0, n - 1, segtree, 0);
	
	long long q;
	cin >> q;
	
	while(q--)
	{
		long long x, qlo, qhi;
		cin >> x;
		
		if(!x)
		{
			cin >> qlo >> qhi;
			cout << query(0, n - 1, segtree, 0, qlo, qhi).val % 3 << endl;
		}
		
		else
		{
			cin >> qlo;
			update(s, 0, n - 1, segtree, 0, qlo);
		}
	}
}
