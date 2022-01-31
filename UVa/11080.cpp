#include <iostream>
#include <vector>
#include <tr1\unordered_map>

using namespace std;

tr1 :: unordered_map <int, vector <int> > adj;
tr1 :: unordered_map <int, bool> vis;
tr1 :: unordered_map <int, int> col;
vector <int> res;

void print();

void dfs(int s)
{
	vis[s] = 1;
	
	for(int i = 0 ; i < adj[s].size() ; i++)
	{
		if(!vis[adj[s][i]])
		{
			res.push_back(adj[s][i]);
			
			print();
			
			dfs(adj[s][i]);
		}
	}
}

void print()
{
	for(int i = 0 ; i < res.size() ; i++)
	{
		cout << res[i] << " ";
	}
	
	cout << endl;
}

int main()
{
	freopen("in.in", "r", stdin);
	
	int t;
	cin >> t;
	
	while(t--)
	{
		adj.clear();
		vis.clear();
		col.clear();
		res.clear();
		
		int n, m;
		cin >> n >> m;
		
		for(int i = 0 ; i < m ; i++)
		{
			int x, y;
			cin >> x >> y;
			
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		
		for(int i = 1 ; i <= n ; i++)
		{
			if(!vis[i])
			dfs(i);
		}
	}
}
