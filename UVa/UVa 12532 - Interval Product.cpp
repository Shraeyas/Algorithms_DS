#include <iostream>
#include <tr1/unordered_map>

using namespace std;

tr1 :: unordered_map <int, int> ar, segtree;

int getsign(int i)
{
	if(i < 0)
	return -1;
	
	if(i > 0)
	return 1;
	
	return 0;
}

int combine(int a, int b)
{
	if(a == 0 || b == 0)
	return 0;
	
	if(a < 0 && b < 0)
	return 1;
	
	if(a < 0 || b < 0)
	return -1;
	
	return 1;
}

char output(int x)
{
	if(x < 0)
	return '-';
	
	if(x > 0)
	return '+';
	
	return '0';
}

void ini_tree(int lo, int hi, int pos)
{
	if(lo == hi)
	{
		segtree[pos] = getsign(ar[lo]);
		return;
	}
	
	int mid = lo + (hi - lo)/2;
	
	ini_tree(lo, mid, 2 * pos + 1);
	ini_tree(mid + 1, hi, 2 * pos + 2);
	
	segtree[pos] = combine(segtree[2*pos + 1], segtree[2*pos + 2]);
}

int query(int qlo, int qhi, int lo, int hi, int pos)
{
	if(qlo > hi || qhi < lo)
	return 1;
	
	if(qlo <= lo && qhi >= hi)
	{
		return segtree[pos];
	}
	
	int mid = lo + (hi - lo)/2;
	
	return combine(query(qlo, qhi, lo,  mid, 2*pos + 1), query(qlo, qhi, mid + 1,  hi, 2*pos + 2));
}

void change(int i, int a, int lo, int hi, int pos)
{
	if(lo == hi && i == lo)
	{
		segtree[pos] = getsign(a);
		return;
	}
	
	if(i < lo || i > hi)
	return;
	
	int mid = lo + (hi - lo)/2;
	
	change(i, a, lo, mid, 2*pos + 1);
	change(i, a, mid + 1, hi, 2*pos + 2);
	
	segtree[pos] = combine(segtree[2*pos + 1], segtree[2*pos + 2]);
}

int main()
{
	freopen("12532 - Interval Product.txt", "r", stdin);
	freopen("out.out", "w", stdout);
	
	int n, k;
	
	while(cin >> n >> k)
	{
		for(int i = 0 ; i < n ; i++)
		{
			cin >> ar[i];
		}
		
		ini_tree(0, n - 1, 0);
		
		while(k--)
		{
			char ch;
			int a, b;
			
			cin >> ch >> a >> b;
			
			if(ch == 'C')
			{
				change(a - 1, b, 0, n - 1, 0);
			}
			
			else
			{
				cout << output(query(a - 1, b - 1, 0, n - 1, 0));
			}
		}
		
		cout << endl;
	}
}
