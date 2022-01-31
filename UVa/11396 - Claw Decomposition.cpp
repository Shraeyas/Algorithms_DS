#include <iostream>
#include <vector>
#include <tr1/unordered_map>

using namespace std;

tr1 :: unordered_map <int, vector <int> > adj;
tr1 :: unordered_map <int, int> vis, color;
bool isbipartite = 1;

void dfs(int s, bool col)
{
	color[s] = col;
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
			{
				isbipartite = 0;
			}
		}
	}
}

int main()
{
	freopen("in.in", "r", stdin);
	
	int v;
	
	while(cin >> v, v)
	{
		adj.clear();
		vis.clear();
		color.clear();
		isbipartite = 1;
		
		int a, b;
		
		while(cin >> a >> b, a, b)
		{
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		for(int i = 1 ; i <= v ; i++)
		{
			if(!vis[i])
			{
				dfs(i, 0);
			}
		}
		
		if(isbipartite)
		{
			cout << "YES" << endl;
		}
		
		else
		{
			cout << "NO" << endl;
		}
	}
}
