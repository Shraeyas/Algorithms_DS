#include <bits/stdc++.h>

using namespace std;

int *ar;

struct node
{
  int a;
  int b;
};

void sort_(vector <int> &v)
{
	int x = v.size();
	vector <int> v1;
	
	for(int i = 0 ; i < x ; i++)
	{
		for(int j = i + 1 ; j < x ; j++)
		{
			if(ar[v[j]] > ar[v[i]])
			{
				int temp = v[i];
				v[i] = v[j];
				v[j] = temp;
			}
		}
	}
	
}

void build(int *a, int lo, int hi, node *segtree, int pos)
{
  if(lo == hi)
  {
    segtree[pos].a = lo;
    segtree[pos].b = -1;
    
    return;
  }
  
  int mid = (lo + hi)/2;
  
  build(a, lo, mid, segtree, 2 * pos + 1);
  build(a, mid + 1, hi, segtree, 2 * pos + 2);
  
  int p, q, x, y, max1, max2;
  
  p = segtree[2 * pos + 1].a, q = segtree[2 * pos + 1].b;
  x = segtree[2 * pos + 2].a, y = segtree[2 * pos + 2].b;
  
  vector <int> v;
  
  if(p != -1)
  v.push_back(p);
  
  if(q != -1)
  v.push_back(q);
  
  if(x != -1)
  v.push_back(x);
  
  if(y != -1)
  v.push_back(y);
  
  sort_(v);
  
  if(v.size() >= 2)
  {
  	segtree[pos].a = v[0];
  	segtree[pos].b = v[1];
  }
  
  else
  {
  	segtree[pos].a = v[0];
  	segtree[pos].b = -1;
  }
}

node query(int lo, int hi, node *segtree, int pos, int qlo, int qhi)
{
	if(qlo <= lo && qhi >= hi)
	{
		node ret;
		
		ret.a = segtree[pos].a;
		ret.b = segtree[pos].b;
		
		return ret;
	}
	
	if(qlo > hi || qhi < lo)
	{
		node ret;
		
		ret.a = -1;
		ret.b = -1;
		
		return ret;
	}
	
	int mid = (lo + hi)/2;
	
	node r1 = query(lo, mid, segtree, 2 * pos + 1, qlo, qhi);
	node r2 = query(mid + 1, hi, segtree, 2 * pos + 2, qlo, qhi);
	
	node ret;
	
	int p, q, x, y, max1, max2;
	  
	  p = r1.a, q = r1.b;
	  x = r2.a, y = r2.b;
	  
	  vector <int> v;
	  
	  if(p != -1)
	  v.push_back(p);
	  
	  if(q != -1)
	  v.push_back(q);
	  
	  if(x != -1)
	  v.push_back(x);
	  
	  if(y != -1)
	  v.push_back(y);
	  
	  sort_(v);
	  
	  if(v.size() >= 2)
	  {
	  	ret.a = v[0];
	  	ret.b = v[1];
	  }
	  
	  else
	  {
	  	ret.a = v[0];
	  	ret.b = -1;
	  }
	
	return ret;
}

void update(int *a, int lo, int hi, node *segtree, int pos, int ind, int val)
{
	if(lo == hi)
	{
		segtree[pos].a = ind;
		a[ind] = val;
			
		return;
	}
	
	int mid = (lo + hi)/2;
	
	if(ind <= mid)
	{
		update(a, lo, mid, segtree, 2 * pos + 1, ind, val);
	}
	
	else
	{
		update(a, mid + 1, hi, segtree, 2 * pos + 2, ind, val);
	}
	
	int p, q, x, y;
	  
	  p = segtree[2 * pos + 1].a, q = segtree[2 * pos + 1].b;
	  x = segtree[2 * pos + 2].a, y = segtree[2 * pos + 2].b;
	  
	  vector <int> v;
	  
	  if(p != -1)
	  v.push_back(p);
	  
	  if(q != -1)
	  v.push_back(q);
	  
	  if(x != -1)
	  v.push_back(x);
	  
	  if(y != -1)
	  v.push_back(y);
	  
	  sort_(v);
	  
	  if(v.size() >= 2)
	  {
	  	segtree[pos].a = v[0];
	  	segtree[pos].b = v[1];
	  }
	  
	  else
	  {
	  	segtree[pos].a = v[0];
	  	segtree[pos].b = -1;
	  }
}

int main() 
{
  freopen("in.in", "r", stdin);
	
  int n;
  cin >> n;
  
  ar = new int[n];
  
  for(int i = 0 ; i < n ; i++)
  {
    cin >> ar[i];
  }
  
  node *segtree = new node [n * 4];
  
  build(ar, 0, n - 1, segtree, 0);
  
  int q;
  cin >> q;
  
  while(q--)
  {
  	char ch;
  	int qlo, qhi;
  	
  	cin >> ch >> qlo >> qhi;
  	
  	if(ch == 'Q')
  	{
  		node ans = query(0, n - 1, segtree, 0, qlo - 1, qhi - 1);
  		cout << ar[ans.a] + ar[ans.b] << endl;
	}
	
	else
	{
		update(ar, 0, n - 1, segtree, 0, qlo - 1, qhi);
	}	
  }
}
