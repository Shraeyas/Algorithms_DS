#include <iostream>
#include <tr1/unordered_map>
#define max 50005

using namespace std;

int adj[max], vis[max], cycle[max];

int dfs(int s)
{
	vis[s] = 1;
	cycle[s] = 1;
	int x;
	
	if(!vis[adj[s]] && adj[s] != -1)
	{
		x = 1 + dfs(adj[s]);
	}
	
	else
	{
		x = 1;
	}
	
	vis[s] = 0;
	return x;
}

int main()
{
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t, cs = 1;
	cin >> t;
	
	while(t--)
	{
		int n;
		cin >> n;
		
		for(int i = 0 ; i < n ; i++)
		{
			vis[i + 1] = 0;
			adj[i + 1] = -1;
			cycle[i + 1] = 0;
		}
		
		for(int i = 0 ; i < n ; i++)
		{
			int u, v;
			cin >> u >> v;
			
			adj[u] = v;
		}
		
		int ans = -1, ind;
		
		for(int i = 1 ; i <= n ; i++)
		{
			if(!cycle[i])
			{	
				int x = dfs(i);
				
				if(ans < x)
				{
					ans = x;
					ind = i;
				}
			}
			
			cycle[i] = 1;
		}
		
		cout << "Case " << cs++ << ": ";
		cout << ind << endl;
	}
}
