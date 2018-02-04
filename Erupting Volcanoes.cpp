#include <iostream>
#include <vector>
#include <queue>
#include <tr1/unordered_map>

using namespace std;

int n, m, ans = 0;

tr1 :: unordered_map <int, tr1 :: unordered_map <int, int> > grid, vis;

bool range(int x, int y)
{
	if(x >= 0 && x < n && y >= 0 && y < n)
	return 1;
	
	return 0;
}

void push_nbr(int x, int y, queue <pair <int, int> > &sq, int w)
{
    if(w == 0)
        return;
        
	if(range(x - 1, y - 1) && !vis[x - 1][y - 1])
	{
        vis[x - 1][y - 1] = 1;
        grid[x - 1][y - 1] += w;
        
        sq.push(make_pair(x - 1, y - 1));
	}
	
	
	if(range(x, y - 1) && !vis[x][y - 1])
	{
        vis[x][y - 1] = 1;
        grid[x][y - 1] += w;
        
        sq.push(make_pair(x, y - 1));
	}
	
	
	if(range(x - 1, y) && !vis[x - 1][y])
	{
        vis[x - 1][y] = 1;
        grid[x - 1][y] += w;
        
        sq.push(make_pair(x - 1, y));
	}
	
	
	if(range(x + 1, y + 1) && !vis[x + 1][y + 1])
	{
        vis[x + 1][y + 1] = 1;
        grid[x + 1][y + 1] += w;
        
        sq.push(make_pair(x + 1, y + 1));
	}
	
	
	if(range(x, y + 1) && !vis[x][y + 1])
	{
        vis[x][y + 1] = 1;
        grid[x][y + 1] += w;
        
        sq.push(make_pair(x, y + 1));
	}
	
	
	if(range(x + 1, y) && !vis[x + 1][y])
	{
        vis[x + 1][y] = 1;
        grid[x + 1][y] += w;
        
        sq.push(make_pair(x + 1, y));
	}
	
	
	if(range(x - 1, y + 1) && !vis[x - 1][y + 1])
	{
        vis[x - 1][y + 1] = 1;
        grid[x - 1][y + 1] += w;
        
        sq.push(make_pair(x - 1, y + 1));
	}
	
	
	if(range(x + 1, y - 1) && !vis[x + 1][y - 1])
	{
        vis[x + 1][y - 1] = 1;
        grid[x + 1][y - 1] += w;
        
        sq.push(make_pair(x + 1, y - 1));
	}
}

queue <pair <int, int> > push_all(queue <pair <int, int> > q, int w)
{
	queue <pair <int, int> > sq;
	
	while(!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		
		push_nbr(x, y, sq, w);
		
		q.pop();
	}
	
	return sq;
}

void bfs(int x, int y, int w)
{	
	grid[x][y] += w;
	ans = max(ans, grid[x][y]);
	vis[x][y] = 1;
	
	queue <pair <int, int> > q;
	q.push(make_pair(x, y));
	
	while(w)
	{
        w--;
		q = push_all(q, w);
	}

}

int main()
{
	cin >> n >> m;
	
	for(int i = 0 ; i < m ; i++)
	{
		vis.clear();
		
		int x, y, w;
		cin >> x >> y >> w;
		bfs(x, y, w);	
	}
    
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
            ans = max(ans, grid[i][j]);
    }
	
	cout << ans;
}
