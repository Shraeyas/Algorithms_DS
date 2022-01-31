#include <bits/stdc++.h>

using namespace std;

struct node
{
  int a;
  int b;
  int ind;
};

node combine(node x, node y)
{
  node ans;
  
  if(x.a > y.a)
  {
    return x;
  }
  
  else if(x.a < y.a)
  {
    return y;
  }
  
  else
  {
    if(x.b < y.b)
      return x;
    
    else if(x.b > y.b)
    {
      return y;
    }
    
    else
    {
      if(x.ind < y.ind)
        return x;
      
      else
        return y;
    }
  }
}

void build(long *a, long *b, int lo, int hi, node *segtree, int pos)
{
  if(lo == hi)
  {
    segtree[pos].a = a[lo];
    segtree[pos].b = b[lo];
    segtree[pos].ind = lo;
    
    return;
  }
  
  int mid = (lo + hi)/2;
  
  build(a, b, lo, mid, segtree, 2 * pos + 1);
  build(a, b, mid + 1, hi, segtree, 2 * pos + 2);
  
  segtree[pos] = combine(segtree[2 * pos + 1], segtree[2 * pos + 2]);
}

node query(int lo, int hi, node *segtree, int pos, int qlo, int qhi)
{
  if(qlo <= lo && qhi >= hi)
  {
    return segtree[pos];
  }
  
  if(qlo > hi || qhi < lo)
  {
    node ret;
    ret.a = INT_MIN;
    
    return ret;
  }
  
  int mid = (lo + hi)/2;
  
  node l = query(lo, mid, segtree, 2 * pos + 1, qlo, qhi);
  node r = query(mid + 1, hi, segtree, 2 * pos + 2, qlo, qhi);
  
  node ans = combine(l, r);
  
  return ans;
}

int main() 
{
  freopen("in.in", "r", stdin);
	
  int n, q;
  cin >> n;
  
  long *a = new long[n];
  long *b = new long[n];
  
  for(int i = 0 ; i < n ; i++)
  {
    cin >> a[i];
  }
  
  for(int i = 0 ; i < n ; i++)
  {
    cin >> b[i];
  }
  
  node *segtree = new node[3 * n];
  build(a, b, 0, n - 1, segtree, 0);
  
  
  cin >> q;
  
  while(q--)
  {
    int qlo, qhi;
    cin >> qlo >> qhi;
    
    cout << query(0, n - 1, segtree, 0, qlo - 1, qhi - 1).ind + 1 << endl;
  }
}
