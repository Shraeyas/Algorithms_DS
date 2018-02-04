#include<iostream>
#include<stack>
#include<map>
#include<vector>

using namespace std;

map<int, int>vis;
map<int, vector<int> >adj;
vector<int>traversal;

void dfs(int s)
{
	stack<int>stk;
	stk.push(s);
	vis[s] = 1;
	traversal.push_back(s);
	
	while(!stk.empty())
	{
		int i = stk.top();
		stk.pop();
		
		for(int j = 0 ; j < adj[i].size() ; j++)
		{
			if(!vis[adj[i][j]])
			{
				traversal.push_back(adj[i][j]);
				stk.push(adj[i][j]);
				vis[adj[i][j]] = 1;
				break;
			}
		}
	}
}

int main()
{
	adj[1].push_back(2);
	adj[2].push_back(4);
	adj[3].push_back(4);
	adj[3].push_back(1);
	adj[2].push_back(1);
	adj[4].push_back(2);
	adj[4].push_back(3);
	adj[1].push_back(3);
	
	dfs(1);
	
	for(int i=0;i<traversal.size();i++)
	cout<<traversal[i]<<" ";
}
