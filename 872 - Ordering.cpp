#include <iostream>
#include <tr1/unordered_map>
#include <vector>

using namespace std;

tr1 :: unordered_map <int, vector <int> > adj;
tr1 :: unordered_map <int, int> indegree;
tr1 :: unordered_map <int, bool> vis;
tr1 :: unordered_map <int, char> nam;
int n, ans = 1;

void dfs(vector <int>& res)
{	
	bool flag = 0;
	
	for(int i = 0 ; i < n ; i++)
	{
		if(indegree[i] == 0 && !vis[i])
		{
			for(int j = 0 ; j < adj[i].size() ; j++)
			{
				indegree[adj[i][j]]--;
			}
			
			vis[i] = 1;
			res.push_back(i);
			flag = 1;
			
			dfs(res);
			
			res.erase(res.end() - 1);
			vis[i] = 0;
			for(int j = 0 ; j < adj[i].size() ; j++)
			{
				indegree[adj[i][j]]++;
			}
		}
	}
	
	
	if(!flag)
	{
		for(int i = 0 ; i < res.size() ; i++)
		{
			cout << nam[res[i]];
			
			if(i != res.size() - 1)
			cout << " ";
		}
		
		cout << endl;
	}
}

bool chk(int s)
{
	vis[s] = 1;
	
	for(int i = 0 ; i < adj[s].size() ; i++)
	{
		if(!vis[adj[s][i]])
		{
			chk(adj[s][i]);
		}
		
		else
		ans = 0;
	}
}

int main()
{
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	
	int t;
	cin >> t;
	getchar();
	getchar();
	
	while(t--)
	{
		ans = 1;
		n = 0;
		adj.clear();
		indegree.clear();
		vis.clear();
		nam.clear();
		
		tr1 :: unordered_map <char, int> var;
		vector <int> res;
		
		string s;
		
		getline(cin, s);
		
		for(int i = 0 ; i < s.size() ; i++)
		{
			if(s[i] != ' ')
			{	
				nam[n] = s[i];
				var[s[i]] = n++;
			}
		}
		
		getline(cin, s);
		getchar();
		
		int fir = 0, sec = 2;
		adj[var[s[fir]]].push_back(var[s[sec]]);
		indegree[var[s[sec]]]++;
		
		for(int i = 0 ; i < s.size() ; i++)
		{
			if(s[i] == ' ')
			{
				fir = i + 1;
				sec = i + 3;
				
				adj[var[s[fir]]].push_back(var[s[sec]]);
			
				indegree[var[s[sec]]]++;
			}
		}
		
		chk(0);
		
		if(!ans)
		cout << "NO" << endl;
		
		else
		{
			vis.clear();
			dfs(res);
		}
		
		if(t)
		cout << endl;
	}
}
