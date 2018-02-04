#include<stdio.h>
#include<map>

#define min -9999999
#define max1 1<<16
#define max2 max1<<2

using namespace std;

struct node
{
	long best, lsum, rsum, total;
};

node *segtree = new node[max2];
int *a = new int[max1];

int maxfun(int pg, int ss)
{
	return max(pg, ss);
}

void pg(int pos)
{
	segtree[pos].total = segtree[2*pos+1].total + segtree[2*pos+2].total;
	segtree[pos].lsum = maxfun(segtree[2*pos + 1].lsum, segtree[2*pos + 1].total + segtree[2*pos+2].lsum);
	segtree[pos].rsum = maxfun(segtree[2*pos + 2].rsum, segtree[2*pos + 2].total + segtree[2*pos+1].rsum);
	segtree[pos].best = maxfun(maxfun(segtree[2*pos+1].best, segtree[2*pos+2].best), segtree[2*pos+1].rsum + segtree[2*pos+2].lsum);
}

void construct(int lo, int hi, int pos)
{
	if(lo == hi)
	{
		segtree[pos].best = a[lo];
		segtree[pos].lsum = a[lo];
		segtree[pos].rsum = a[lo];
		segtree[pos].total = a[lo];
		
		return;
	}
	
	int mid = lo + (hi - lo)/2;
	
	construct(lo, mid, 2*pos+1);
	construct(mid+1, hi, 2*pos+2);
	
	pg(pos);
}

node query(int qlo, int qhi, int lo, int hi, int pos)
{
	if(qlo>hi || qhi<lo)
	{
		return (node)				//MADE CHANGES HERE
		{
			min, 
			min, 
			min, 
			0
		};//return something empty
	}
	
	if(qlo<=lo && qhi>=hi)
	{
		//res = segtree[pos].best;
		return segtree[pos];
	}
	
	int mid = lo + (hi - lo)/2;
	
	node left = query(qlo, qhi, lo, mid, 2*pos+1), right = query(qlo, qhi, mid+1, hi, 2*pos+2), pr;
	
	pr.best = maxfun(left.rsum + right.lsum, maxfun(left.best, right.best));
	pr.lsum = maxfun(left.lsum, left.total + right.lsum);
	pr.rsum = maxfun(left.rsum + right.total, right.rsum);
	pr.total = left.total + right.total;
	
	return pr;
	
}


int main()
{

	//freopen("C:\\Users\\Shraeyas\\Documents\\pg\\pr_ag\\prag_gss1.txt", "r", stdin);
	
	int n;
	scanf("%d", &n);
	
	for(int i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}
	
	construct(0, n-1, 0);
		
	int q;
	scanf("%d", &q);
	
	while(q--)
	{
		int x,y;
		scanf("%d %d", &x, &y);
		x--, y--;
		
		node pra = query(x, y, 0, n-1, 0);
		
		printf("%d\n", maxfun(maxfun(pra.lsum, pra.rsum), maxfun(pra.total, pra.best)));
	}
}

