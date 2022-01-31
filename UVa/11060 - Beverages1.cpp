#include <iostream>
#include <vector>
#include <tr1/unordered_map>

using namespace std;

tr1 :: unordered_map <int, vector <int> > adj;
tr1 :: unordered_map <int, int> vis;
vector <int> res;

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
	
	res.push_back(s);
}

int main()
{
	freopen("in.in", "r", stdin);
	
	int n, cs = 1;
	
	while(cin >> n)
	{
		adj.clear();
		vis.clear();
		res.clear();
		
		tr1 :: unordered_map <string, int> name;
		tr1 :: unordered_map <int, string> ind;
		
		for(int i = 0 ; i < n ; i++)
		{
			string s;
			cin >> s;
			
			name[s] = i;
			ind[i] = s;
		}
		
		int m;
		cin >> m;
		
		for(int i = 0 ; i < m ; i++)
		{
			string p, q;
			cin >> p >> q;
			
			int a, b;
			
			a = name[p], b = name[q];
			adj[b].push_back(a);
		}
		
		for(int i = 0 ; i < n ; i++)
		{
			if(!vis[i])
			dfs(i);
		}
		
		cout << "Case #" << cs++ << ": Dilbert should drink beverages in this order: ";
		
		for(int i = 0 ; i < res.size() ; i++)
		{
			cout << ind[res[i]] << " ";
		}
		
		cout << "." << endl;
	}
}
