#include <iostream>
#include <tr1/unordered_map>

struct node
{
	int x, y;
};

node ob, ans;
int ind = 100005;

tr1 :: unordered_map <int, int> vis;
tr1 :: unordered_map <int, vector <int> > adj;
tr1 :: unordered_map <int, int> h;

void dfs(int);

vector<int> longestSubsequence(int *arr, int n)
{
	vector <int> pg;
	
	
	
	for(int i = 0 ; i < n ; i++)
	{
		h[arr[i]] = i + 1;
	}
	
	ans.x = 100005, ans.y = -100005;
	int ansind = 100005;
  
	for(int i = 0 ; i < n ; i++)
	{
		if(h[arr[i] + 1])
		adj[arr[i]].push_back(arr[i] + 1);
		
		if(h[arr[i] - 1])
		adj[arr[i]].push_back(arr[i] - 1);
	}
	
	for(int i = 0 ; i < n ; i++)
	{
		if(!vis[arr[i]])
		{
			ob.x = 100005;
			ob.y = -100005;
          
			
			dfs(arr[i]);
			
			if(ob.y - ob.x > ans.y - ans.x)
			{
				ans = ob;
              	ansind = ind;
			}
          
          	else if((ob.y - ob.x == ans.y - ans.x) && ind < ansind)
            {
              ansind = ind;
              ans = ob;
            }
		}
	}
	
	for(int i = ans.x ; i <= ans.y ; i++)
	{
		pg.push_back(i);
	}
	
	return pg;
}

void dfs(int s)
{
	vis[s] = 1;
	if(ob.x > s)
    {
      ob.x = s;
      ind = h[s];
    }
  
  
	ob.y = max(ob.y, s);
	
	for(int i = 0 ; i < adj[s].size() ; i++)
	{
		if(!vis[adj[s][i]])
		{
			dfs(adj[s][i]);
		}
	}
}


