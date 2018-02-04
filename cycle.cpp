#include<iostream>
#include<map>
#include<vector>

#define max 100

using namespace std;

bool vis[max] = {0}, bvis[max] = {0};

map<int, vector<int> >adj;

void dfs(int s)
{
	//cout<<s<<endl;
	bvis[s] = 1;
	
	vis[s] = 1;
	
	for(int i=0;i<adj[s].size();i++)
	{
		if(bvis[adj[s][i]] == 1)
		{
			cout<<"Cycle found at "<<s<<endl;
		}
			
			
		if(!vis[adj[s][i]])
		{
			dfs(adj[s][i]);
			
			bvis[adj[s][i]] = 0;
		}
	}
}

int main()
{
	freopen("C://Users//Shraeyas//Documents//pg//pr_ag//prag_cycle.txt", "r", stdin);
	
	int n, m;
	cin>>n>>m;
	
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		
		adj[x].push_back(y);
		//adj[y].push_back(x);
	}
	
	dfs(1);
}
