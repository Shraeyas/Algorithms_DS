#include <iostream>

using namespace std;

bool xx = 0;
int n;
string grid[100];

bool range(int x)
{
	if(x >= 0 && x < n)
	return 1;
	
	return 0;
}

void arr(int i, int j)
{
	if(!(range(i) && range(j)) || grid[i][j] == '.')
	return;
	
	if(grid[i][j] == 'x')
	xx = 1;
	
	grid[i][j] = '.';
	
	arr(i + 1, j);
	arr(i, j + 1);
	arr(i - 1, j);
	arr(i, j - 1);
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("in.in", "r", stdin);
	
	int t, cs = 1;
	cin >> t;
	
	while(t--)
	{
		cin >> n;
		
		for(int i = 0 ; i < n ; i++)
		{
			cin >> grid[i];
		}
		
		int ans = 0;
		
		for(int  i = 0 ; i < n ; i++)
		{
			for(int  j = 0 ; j < n ; j++)
			{
				xx = 0;
				
				if(grid[i][j] == '@' || grid[i][j] == 'x')
				arr(i, j);
				
				if(xx)
				ans++;
			}
		}
		
		cout << "Case " << cs++ << ": " << ans << endl;
		
	}
}
