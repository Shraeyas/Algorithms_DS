#include <iostream>
#include <climits>
#include <tr1/unordered_map>

using namespace std;

struct node
{
	long lsum, rsum, best, total;
};

node combine(node l, node r)
{
	node ans;
	
	if(l.lsum == LONG_MIN)
	return r;
	
	if(r.rsum == LONG_MIN)
	return l;
	
	ans.lsum = max(l.total + r.lsum, l.lsum);
	ans.rsum = max(l.rsum + r.total, r.rsum);
	ans.total = l.total + r.total;
	ans.best = max(l.rsum + r.lsum, max(l.best, r.best));
	
	return ans;
}

void build(long *ar, long lo, long hi, node *segtree, long pos)
{
	if(lo == hi)
	{
		segtree[pos].lsum = ar[lo];
		segtree[pos].rsum = ar[lo];
		segtree[pos].best = ar[lo];
		segtree[pos].total = ar[lo];
		
		return;
	}
	
	long mid = lo + (hi - lo)/2;
	
	build(ar, lo, mid, segtree, 2 * pos + 1);
	build(ar, mid + 1, hi, segtree, 2 * pos + 2);
	
	segtree[pos] = combine(segtree[2 * pos + 1], segtree[2 * pos + 2]);
}

node query(long lo, long hi, node *segtree, long pos, long qlo, long qhi)
{
	if(qlo <= lo && qhi >= hi)
	{
		return segtree[pos];
	}
	
	if(qlo > hi || qhi < lo)
	{
		node ans;
		
		ans.lsum = LONG_MIN;
		ans.rsum = LONG_MIN;
		ans.total = 0;
		ans.best = LONG_MIN;
      
		return ans;
	}
	
	long mid = lo + (hi - lo)/2;
	
	node l = query(lo, mid, segtree, 2 * pos + 1, qlo, qhi);
	node r = query(mid + 1, hi, segtree, 2 * pos + 2, qlo, qhi);
	
  //
    //cout << combine(l, r).best << endl;
	return combine(l, r);
}

int main()
{
	//freopen("in.in", "r", stdin);
	
	long n;
	scanf("%ld", &n);
	
	long *ar = new long [n];
	
	for(long i = 0 ; i < n ; i++)
	{
		scanf("%ld", &ar[i]);
	}
	
	node *segtree = new node [4 * n];
	build(ar, 0, n - 1, segtree, 0);
	
    //for(int i = 0 ; i < 5 ; i++)
    //cout << segtree[i].best << endl;
      
	long q;
	scanf("%ld", &q);
	
	while(q--)
	{
		long qlo, qhi;
		scanf("%ld %ld", &qlo, &qhi);
		
        node ans = query(0, n - 1, segtree, 0, qlo - 1, qhi - 1);
      
		printf("%ld\n", ans.best);
	}
}

