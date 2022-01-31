#include <bits/stdc++.h>
#include <cstring>

using namespace std;

int main() 
{
  int n;
  cin >> n;
  
  vector <int> ans;
  
  bool *vis = new bool [n + 1];
  memset(vis, 0, (n + 1) * sizeof(bool));
  
  int *mpf = new int [n + 1];
  memset(mpf, 0, (n + 1) * sizeof(int));
  
  mpf[1] = 1;
  for(int i = 2 ; i <= n ; i++)
  {
    if(!mpf[i])
    for(int j = i ; j <= n ; j += i)
    {
      if(!mpf[j])
      mpf[j] = i;
    }
  }
  
  for(int i = n ; i > 1 ; i--)
  {
  	if(!vis[i])
  	{
  		ans.push_back(i);
  		vis[i] = 1;
	}
	
	else
	{
		continue;
	}
	
	int x = i;
	int d;
	
	while(1)
	{
		int l = i;
		d = mpf[x];
		
		while(l)
		{
			if(!vis[l])
			{
				ans.push_back(l);
				vis[l] = 1;
			}
			
			l -= d;
		}
		
		while(x && x % d == 0 && d != 1)
		{
			x /= d;
		}
		
		if(x < 2)
		break;
	}
  }
  
  for(int i = 0 ; i < ans.size() ; i++)
  cout << ans[i] << " ";
  cout << 1;
  
}
