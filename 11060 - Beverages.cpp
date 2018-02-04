#include <iostream>
#include <vector>
#include <tr1/unordered_map>

using namespace std;

vector <int> ans;
tr1 :: unordered_map <int, vector <int> > adj;
tr1 :: unordered_map <int, int> vis;

void dfs(int s)
{
	vis[s] = 1;
	
	for(int i = 0 ; i < adj[s].size() ; i++)
	{
		if(!vis[adj[s][i]])
		dfs(adj[s][i]);
	}
	
	ans.push_back(s);
}

int main()
{
	freopen("in.in", "r", stdin);
	
	int n, cs = 1;
	
	while(cin >> n)
	{
		vis.clear();
		adj.clear();
		ans.clear();
		
		tr1 :: unordered_map <string, int> hash;
		vector <string> v;
		
		for(int i = 0 ; i < n ; i++)
		{
			string s;
			cin >> s;
			
			v.push_back(s);
			hash[s] = i;
		}
		
		int m;
		cin >> m;
		
		for(int i = 0 ; i < m ; i++)
		{
			string s1, s2;
			cin >> s1 >> s2;
			
			adj[hash[s1]].push_back(hash[s2]);
			//adj[hash[s2]].push_back(hash[s1]);
		}
		
		for(int i = 0 ; i < n ; i++)
		{
			if(!vis[i])
			dfs(i);
		}
		
		cout << "Case #" << cs++ << ": Dilbert should drink beverages in this order: ";
		
		for(int i = ans.size() - 1 ; i >= 0 ; i--)
		{
			cout << v[ans[i]] << " ";
		}
		
		cout << "." << endl;
		
	}
}
