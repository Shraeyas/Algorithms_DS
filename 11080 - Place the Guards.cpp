#include <iostream>
#include <tr1/unordered_map>
#include <vector>

using namespace std;

tr1 :: unordered_map <int, vector <int> > adj;
tr1 :: unordered_map <int, int> vis, color;
int x, y;
bool isbipartite = 1;

void dfs(int s, bool col)
{
	color[s] = col;
	
	if(col)
	x++;
	
	else
	y++;
	
	vis[s] = 1;
	
	for(int i = 0 ; i < adj[s].size() ; i++)
	{
		if(!vis[adj[s][i]])
		{
			dfs(adj[s][i], !col);
		}
		
		else
		{
			if(color[adj[s][i]] != !col)
			isbipartite = 0;
		}
	}
}

int main()
{
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	
	int t;
	cin >> t;
	
	while(t--)
	{
		int ans = 0;
		
		adj.clear();
		vis.clear();
		color.clear();
		isbipartite = 1;
		
		int n, m;
		cin >> n >> m;
		
		for(int i = 0 ; i < m ; i++)
		{
			int x, y;
			cin >> x >> y;
			
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		
		for(int i = 0 ; i < n ; i++)
		{
			x = 0, y = 0;
			
			if(adj[i].size() == 0)
			{
				ans++;
			}
			
			else if(!vis[i])
			{
				dfs(i, 0);
			}
			
			ans += min(x, y);
		}
		
		if(isbipartite)
		{
			cout << ans << endl;
		}
		
		else
		{
			cout << -1 << endl;
		}
	}
}
