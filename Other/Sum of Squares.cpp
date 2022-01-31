#include <iostream>

using namespace std;

struct node
{
	long long ssum, sum;
	long long l0, l1;
};

void build(long long *ar, long long lo, long long hi, node *segtree, long long pos)
{
	if(lo == hi)
	{
		segtree[pos].ssum = ar[lo] * ar[lo];
		segtree[pos].sum = 2 * ar[lo];
		
		segtree[pos].l0 = 0;
		segtree[pos].l1 = 0;
		
		return;
	}
	
	long long mid = (lo + hi)/2;
	
	build(ar, lo, mid, segtree, 2 * pos + 1);
	build(ar, mid + 1, hi, segtree, 2 * pos + 2);
	
	segtree[pos].ssum = segtree[2 * pos + 1].ssum + segtree[2 * pos + 2].ssum;
	segtree[pos].sum = segtree[2 * pos + 1].sum + segtree[2 * pos + 2].sum;
	
	segtree[pos].l0 = 0;
	segtree[pos].l1 = 0;
}

void pro0(long long lo, long long hi, node *segtree, long long pos)
{
	if(segtree[pos].l0 != 0)
	{
		segtree[pos].ssum = segtree[pos].l0 * segtree[pos].l0 * (hi - lo + 1);
		segtree[pos].sum = 2 * segtree[pos].l0 * (hi - lo + 1);
		
		if(lo != hi)
		{
			segtree[2 * pos + 1].l0 = segtree[pos].l0;			
			segtree[2 * pos + 2].l0 = segtree[pos].l0;
		}
		
		segtree[pos].l0 = 0;
		segtree[pos].l1 = 0;
	}
	
	return;
}

void pro1(long long lo, long long hi, node *segtree, long long pos)
{
	if(segtree[pos].l1 != 0)
	{
		segtree[pos].ssum += (hi - lo + 1) * segtree[pos].l1 * segtree[pos].l1 + segtree[pos].sum * segtree[pos].l1;
		segtree[pos].sum += 2 * (hi - lo + 1) * segtree[pos].l1;
		
		if(lo != hi)
		{
			segtree[2 * pos + 1].l1 += segtree[pos].l1;
			segtree[2 * pos + 2].l1 += segtree[pos].l1;
		}
		
		segtree[pos].l0 = 0;
		segtree[pos].l1 = 0;
	}
	
	return;
}

void update0(long long lo, long long hi, node *segtree, long long pos, long long qlo, long long qhi, long long x)
{
	pro0(lo, hi, segtree, pos);
	pro1(lo, hi, segtree, pos);
	
	if(qlo <= lo && qhi >= hi)
	{
		segtree[pos].l0 = x;
		pro0(lo, hi, segtree, pos);
		
		return;
	}
	
	if(qlo > hi || qhi < lo)
	{
		return;
	}
	
	long long mid = (lo + hi)/2;
	
	update0(lo, mid, segtree, 2 * pos + 1, qlo, qhi, x);
	update0(mid + 1, hi, segtree, 2 * pos + 2, qlo, qhi, x);
	
	segtree[pos].ssum = segtree[2 * pos + 1].ssum + segtree[2 * pos + 2].ssum;
	segtree[pos].sum = segtree[2 * pos + 1].sum + segtree[2 * pos + 2].sum;
}

void update1(long long lo, long long hi, node *segtree, long long pos, long long qlo, long long qhi, long long x)
{
	pro0(lo, hi, segtree, pos);
	pro1(lo, hi, segtree, pos);
	
	if(qlo <= lo && qhi >= hi)
	{
		segtree[pos].l1 = x;
		pro1(lo, hi, segtree, pos);
		
		return;
	}
	
	if(qlo > hi || qhi < lo)
	{
		return;
	}
	
	long long mid = (lo + hi)/2;
	
	update1(lo, mid, segtree, 2 * pos + 1, qlo, qhi, x);
	update1(mid + 1, hi, segtree, 2 * pos + 2, qlo, qhi, x);
	
	
	segtree[pos].ssum = segtree[2 * pos + 1].ssum + segtree[2 * pos + 2].ssum;
	segtree[pos].sum = segtree[2 * pos + 1].sum + segtree[2 * pos + 2].sum;
}

long long query(long long lo, long long hi, node *segtree, long long pos, long long qlo, long long qhi)
{
	pro0(lo, hi, segtree, pos);
	pro1(lo, hi, segtree, pos);
	
	if(qlo <= lo && qhi >= hi)
	{		
		return segtree[pos].ssum;
	}
	
	if(qlo > hi || qhi < lo)
	{
		return 0;
	}
	
	long long mid = (lo + hi)/2;
	
	long long a = query(lo, mid, segtree, 2 * pos + 1, qlo, qhi);
	long long b = query(mid + 1, hi, segtree, 2 * pos + 2, qlo, qhi);
	
	return a + b;
}

int main()
{
//	/freopen("in.in", "r", stdin);
	
	long long t, cs = 1;
	cin >> t;
	
	while(t--)
	{
		cout << "Case " << cs++ << ":" << endl;
		long long n, q;
		cin >> n >> q;
		
		long long *ar = new long long[n];
		
		for(long long i = 0 ; i < n ; i++)
		{
			cin >> ar[i];
		}
		
		node *segtree = new node [4 * n];
		build(ar, 0, n - 1, segtree, 0);
		
		/*for(long long i = 0 ; i < 7 ; i++)
		cout << segtree[i].l0 << " ";
		cout << endl;*/
		
		while(q--)
		{
			long long c, st, end, x;
			
			cin >> c;
			
			if(c == 0)
			{
				cin >> st >> end >> x;
				
				update0(0, n - 1, segtree, 0, st - 1, end - 1, x);
			}
			
			else if(c == 1)
			{
				cin >> st >> end >> x;
				
				update1(0, n - 1, segtree, 0, st - 1, end - 1, x);
			}
			
			else
			{
				cin >> st >> end;
				cout << query(0, n - 1, segtree, 0, st - 1, end - 1);
			}
		}
		cout << endl;
		delete [] segtree;
		delete [] ar;
	}
	
}

