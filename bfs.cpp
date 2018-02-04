#include<iostream>
#include<queue>
#include<map>
#include<vector>

using namespace std;

map<int, int>vis;
vector<int>adj[100];

void bfs(int s)
{
	queue<int>q;
	q.push(s);
	vis[s] = 1;
	
	cout<<s<<" ";
	
	while(!q.empty())
	{	
		for(int i=0;i<adj[s].size();i++)
		{
			if(!vis[adj[s][i]])
			{
				cout<<adj[s][i]<<" ";
				
				vis[adj[s][i]] = 1;
				q.push(adj[s][i]);
			}
		}
		
		q.pop();
		s = q.front();
		
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	int n, m;
	cin>>n>>m;
	
	for(int i=0;i<m;i++)
	{
		int x, y;
		cin>>x>>y;
		
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	cout<<"The Breadth First Traversal will be:"<<endl;
	
	bfs(1);
}
