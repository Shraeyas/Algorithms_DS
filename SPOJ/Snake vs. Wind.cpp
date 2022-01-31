#include <iostream>
#include <tr1/unordered_map>

using namespace std;

tr1 :: unordered_map <int, tr1 :: unordered_map <int, int> > vis, grid;

int n, ss = 1;
char ch;

bool range(int x, int y)
{
	if(x >= 0 && x < n && y >= 0 && y < n)
	return 1;
	
	return 0;
}

void dfs(int x, int y)
{
	vis[x][y] = 1;
	grid[x][y] = ss++;
	
	if(ch == 'n')
	{
		if(range(x - 1, y) && !vis[x - 1][y])
		dfs(x - 1, y);
		
		else if(range(x, y - 1) && !vis[x][y - 1])
		{
			dfs(x, y - 1);
		}
		
		else if(range(x, y + 1) && !vis[x][y + 1])
		{
			dfs(x, y + 1);
		}
		
		else if(range(x + 1, y) && !vis[x + 1][y])
		{
			dfs(x + 1, y);
		}
	}
	
	
	if(ch == 's')
	{
		
		if(range(x + 1, y) && !vis[x + 1][y])
		{
			dfs(x + 1, y);
		}
		
	
		else if(range(x, y - 1) && !vis[x][y - 1])
		{
			dfs(x, y - 1);
		}
		
		else if(range(x, y + 1) && !vis[x][y + 1])
		{
			dfs(x, y + 1);
		}
		
		else if(range(x - 1, y) && !vis[x - 1][y])
		dfs(x - 1, y);
		
	}
	
	
	if(ch == 'w')
	{
		if(range(x, y - 1) && !vis[x][y - 1])
		{
			dfs(x, y - 1);
		}
		
		else if(range(x - 1, y) && !vis[x - 1][y])
		dfs(x - 1, y);
		
		
		else if(range(x + 1, y) && !vis[x + 1][y])
		{
			dfs(x + 1, y);
		}
		
		
		else if(range(x, y + 1) && !vis[x][y + 1])
		{
			dfs(x, y + 1);
		}
	}
	
	
	if(ch == 'e')
	{
		if(range(x, y + 1) && !vis[x][y + 1])
		{
			dfs(x, y + 1);
		}
		
		else if(range(x - 1, y) && !vis[x - 1][y])
		dfs(x - 1, y);
		

		else if(range(x + 1, y) && !vis[x + 1][y])
		{
			dfs(x + 1, y);
		}
		
		else if(range(x, y - 1) && !vis[x][y - 1])
		{
			dfs(x, y - 1);
		}
	}
}

int main()
{
	cin >> n >> ch;	
	
	int x, y;
	cin >> x >> y;
	
	dfs(x, y);
	
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < n ; j++)
		{
			cout << grid[i][j] <<  " ";
		}
		
		cout << endl;
	}
}
