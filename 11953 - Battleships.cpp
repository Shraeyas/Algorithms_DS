#include <iostream>

using namespace std;

bool pg = 0;
int n;
string grid[100];

bool range(int x)
{
	if(x >= 0 && x < n)
	return 1;
	
	return 0;
}

void pra(int i, int j)
{
	if(!(range(i) && range(j)) || grid[i][j] == '.')
	return;
	
	if(grid[i][j] == 'x')
	pg = 1;
	
	grid[i][j] = '.';
	
	pra(i + 1, j);
	pra(i, j + 1);
	pra(i - 1, j);
	pra(i, j - 1);
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
				pg = 0;
				
				if(grid[i][j] == '@' || grid[i][j] == 'x')
				pra(i, j);
				
				if(pg)
				ans++;
			}
		}
		
		cout << "Case " << cs++ << ": " << ans << endl;
		
	}
}
