#include <iostream>
#include <vector>
#include <tr1/unordered_map>

using namespace std;

tr1 :: unordered_map <int, vector <int> > adj;
tr1 :: unordered_map <int, int> vis;
vector <int> v;

void dfs(int s)
{
	vis[s] = 1;
	
	for(int i = 0 ; i < adj[s].size() ; i++)
	{
		if(!vis[adj[s][i]])
		{
			dfs(adj[s][i]);
		}
	}
	
	v.push_back(s);
}

int main()
{
	freopen("in.in", "r", stdin);
	
	int n, m;
	
	while(cin >> n >> m, n || m)
	{
		adj.clear();
		vis.clear();
		v.clear();
		
		for(int i = 0 ; i < m ; i++)
		{
			int x, y;
			cin >> x >> y;
			
			adj[x].push_back(y);
		}
		
		for(int i = 1 ; i <= n ; i++)
		{
			if(!vis[i])
			dfs(i);
		}
		
		for(int i = v.size() - 1 ; i >= 0 ; i--)
		cout << v[i] << " ";
		
		cout << endl;
	}
}
