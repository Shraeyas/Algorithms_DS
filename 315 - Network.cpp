#include <iostream>
#include <vector>

using namespace std;

vector <vector <int> > adj(1000);
tr1 :: unordered_map <int, int> vis;
int ans = 0, num = 0;

void dfs(int s, int x)
{
	vis[s] = 1;
	
	
}

int main()
{
	int n;
	
	while(cin >> n, n)
	{		
		int x;
		ans = 0;
		adj.clear();
		
		while(cin >> x, x)
		{
			string s;
			getline(cin, s);
			
			for(int i = 0 ; i < s.length() ; i += 2)
			{
				adj[x].push_back(s[i] - '0');
			}
		}
		
		for(int i = 1 ; i <= n ; i++)
		{
			vis.clear();
			
			if(i != 1)
			dfs(1, i);
			
			else
			dfs(2, i);
			
			if(num == )
		}
		
		cout << ans << endl;
	}
}
