#include<iostream>
#include<map>
#include<vector>
#include<stack>

using namespace std;

map<int, vector<int> >adj;
stack<int>stk;
map<int, int>vis;

void tps(int s)
{
	vis[s] = 1;
	
	for(int i=0;i<adj[s].size();i++)
	{
		if(!vis[adj[s][i]])
		{
			tps(adj[s][i]);
		}
	}
	
	stk.push(s);
}

int main()
{
	freopen("C://Users//Shraeyas//Documents//pg//pr_ag//prag_cycle.txt", "r", stdin);
	
	int n, m;
	cin>>n>>m;
	
	for(int i=0;i<m;i++)
	{
		int x, y;
		cin>>x>>y;
		
		adj[x].push_back(y);
	}
	
	tps(1);
	
	while(!stk.empty())
	{
		cout<<stk.top()<<" ";
		stk.pop();
	}
}
