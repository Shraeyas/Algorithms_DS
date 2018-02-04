#include <iostream>

using namespace std;

string s[21];
char ch;
int cur = 0;
int m, n;

void floodfill(int x, int y)
{	
	cur++;
	s[x][y] = ch + 1;
		
	if(y == 0 && s[x][n - 1] == ch)
	{
		floodfill(x, n - 1);
	}
	
	if(y == n - 1 && s[x][0] == ch)
	{
		floodfill(x, 0);
	}
	
	if(x + 1 < m)
	if(s[x + 1][y] == ch)
	{
		floodfill(x + 1, y);
	}
	
	if(y + 1 < n)
	if(s[x][y + 1] == ch)
	{
		floodfill(x, y + 1);
	}
	
	if(x - 1 >= 0)
	if(s[x - 1][y] == ch)
	{
		floodfill(x - 1, y);
	}
	
	if(y - 1 >= 0)
	if(s[x][y - 1] == ch)
	{
		floodfill(x, y - 1);
	}
}

int main()
{
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	
	while(cin >> m >> n)
	{
		for(int i = 0 ; i < m ; i++)
		{
			cin >> s[i];
		}
		
		int x, y;
		cin >> x >> y;
		
		ch = s[x][y];
		floodfill(x, y);
		
		int ans = -1;
		cur = 0;
		
		for(int i = 0 ; i < m ; i++)
		{
			for(int  j = 0 ; j < n ; j++)
			{
				if(s[i][j] == ch)
				{
					cur = 0;
					floodfill(i, j);
				}
				
				ans = max(ans, cur);
			}
		}
		
		cout << ans << endl;
		
		
	}
}
