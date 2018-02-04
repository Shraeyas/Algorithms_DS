#include<iostream>
#include<map>
#include<vector>

using namespace std;

map<int, int>vis;
vector<int>adj[100];

void dfs(int s)
{
	vis[s] = 1;
	cout<<s<<" ";
	
	for(int i=0;i<adj[s].size();i++)
	{
		if(!vis[adj[s][i]])
		{
			dfs(adj[s][i]);
		}
	}
}

int main()
{
	int n, m;
	cin>>n>>m;
	
	for(int i=0;i<m;i++)
	{
		int x, y;
		cin>>x>>y;
		
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	cout<<"The Depth First Traversal will be:"<<endl;
	
	dfs(1);
}
