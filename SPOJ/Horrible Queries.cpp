#include <bits/stdc++.h>

using namespace std;

struct node
{
  long long sum, lazy;
};

void build(long long lo, long long hi, node *segtree, long long pos)
{
  if(lo == hi)
  {
    segtree[pos].sum = 0;
    segtree[pos].lazy = 0;
    
    return;
  }
  
  long long mid = (lo + hi)/2;
  
  build(lo, mid, segtree, 2 * pos + 1);
  build(mid + 1, hi, segtree, 2 * pos + 2);
  
  segtree[pos].sum = 0;
  segtree[pos].lazy = 0;
}

void update(long long lo, long long hi, node *segtree, long long pos, long long v, long long qlo, long long qhi)
{
	if(segtree[pos].lazy != 0)
	{
		segtree[pos].sum += segtree[pos].lazy * (hi - lo + 1);
		    
	    if(lo != hi)
		{			
			segtree[2 * pos + 1].lazy += segtree[pos].lazy;
			segtree[2 * pos + 2].lazy += segtree[pos].lazy;
		}
		
		segtree[pos].lazy = 0;	
	}
	
    if(qlo <= lo && qhi >= hi)
    {
    	segtree[pos].sum += v * (hi - lo + 1);
		
		if(lo != hi)
		{			
			segtree[2 * pos + 1].lazy += v;
			segtree[2 * pos + 2].lazy += v;
		}
		
		return;
    }

  	if(qlo > hi || qhi < lo)
	{
		return;
	}
	
	long long mid = (lo + hi)/2;
	
	update(lo, mid, segtree, 2 * pos + 1, v, qlo, qhi);
	update(mid + 1, hi, segtree, 2 * pos + 2, v, qlo, qhi);
	
	segtree[pos].sum = segtree[2 * pos + 1].sum + segtree[2 * pos + 2].sum;
}

long long query(long long lo, long long hi, node *segtree, long long pos, long long qlo, long long qhi)
{	
	if(qlo > hi || qhi < lo)
	{
		return 0;
	}
	
	if(segtree[pos].lazy != 0)
	{
		segtree[pos].sum += segtree[pos].lazy * (hi - lo + 1);
	    
	    if(lo != hi)
		{			
			segtree[2 * pos + 1].lazy += segtree[pos].lazy;
			segtree[2 * pos + 2].lazy += segtree[pos].lazy;
		}
		
		segtree[pos].lazy = 0;	
	}
	
	if(qlo <= lo && qhi >= hi)
	{    
	    return segtree[pos].sum;
	}
	
	long long mid = (lo + hi)/2;
	
	long long x = query(lo, mid, segtree, 2 * pos + 1, qlo, qhi);
	long long y = query(mid + 1, hi, segtree, 2 * pos + 2, qlo, qhi);
	
	return x + y;
}

int main() 
{
  //freopen("in.in", "r", stdin);
 
  node *segtree;
  
  long long t;
  cin >> t;
  
  while(t--)
  {
    long long n, c;
    cin >> n >> c;
      
	segtree = new node [4 * n];
    
    build(0, n - 1, segtree, 0);
    
    while(c--)
    {
      bool c;
      cin >> c;
      
      if(!c)
      {
        long long p, q, v;
        cin >> p >> q >> v;
        
        update(0, n - 1, segtree, 0, v, p - 1, q - 1);
      }
      
      else
      {
        long long p, q;
        cin >> p >> q;
        
        cout << query(0, n - 1, segtree, 0, p - 1, q - 1) << endl;
      }
    }
    
    delete [] segtree;
  }
}
