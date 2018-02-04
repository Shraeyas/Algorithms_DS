#include <iostream>
#include <vector>
#include <tr1/unordered_map>

using namespace std;

int n;
string grid[n];
vector <pair <int, int> > king;

void dfs(int x, int y, int move)
{
	
}

int main()
{
	int q;
	cin >> q;
	
	while(q--)
	{
		int n;
		cin >> n;
		
		for(int i = 0 ; i < n ; i++)
		{
			cin >> grid[i];
		}
		
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < n ; j++)
			{
				if(grid[i][j] == 'K')
				{
					king.push_back(make_pair(i, j));
				}
			}
		}
		
		for(int i =  0 ; i < king.size() ; i++)
		{
			
		}
	}
}
