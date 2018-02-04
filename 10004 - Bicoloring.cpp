#include <iostream>
#include <vector>
#include <tr1/unordered_map>

using namespace std;

tr1 :: unordered_map <int, vector <int> > adj;
tr1 :: unordered_map <int, bool> vis, col;

int ch = 1;

void dfs(int s, bool c)
{
	vis[s] = 1;
	col[s] = c;
	
	for(int i = 0 ; i < adj[s].size() ; i++)
	{
		if(!vis[adj[s][i]])
		{
			dfs(adj[s][i], !c);
		}
		
		else if(col[adj[s][i]] == col[s])
		{		
			ch = 0;
		}
	}
}

int main()
{
	freopen("in.in", "r", stdin);
	
	int n, m;
	
	while(cin >> n, n)
	{
		cin >> m;
		
		adj.clear();
		vis.clear();
		col.clear();
		
		ch = 1;
		
		for(int i = 0 ; i < m ; i++)
		{
			int x, y;
			cin >> x >> y;
			
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		
		dfs(0, 0);
		
		if(ch)
		{
			cout << "BICOLORABLE." << endl;
		}
		
		else
		{
			cout << "NOT BICOLORABLE." << endl;
		}
	}
}
