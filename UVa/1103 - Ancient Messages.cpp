#include <iostream>
#include <tr1/unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

string grid[202];
int n, m, ans = 0;

bool xrange(int x)
{
	if(x >= 0 && x < n + 2)
	return 1;

	return 0;
}

void func()
{

		for(int i = 0 ; i < n + 2 ; i++)
		{
			for(int j = 0 ; j < 4 * m + 2 ; j++)
			{
				cout << grid[i][j] << " ";
			}

			cout << endl;
		}
}

bool yrange(int x)
{
	if(x >= 0 && x < 4 * m + 2)
	return 1;

	return 0;
}

void ff(int, int);

void floodfill(int x, int y)
{
	grid[x][y] = 'm';

	if(xrange(x + 1) && yrange(y + 1))
	{
		if(grid[x + 1][y + 1] == '1')
		{
			floodfill(x + 1, y + 1);
		}

		else if(grid[x + 1][y + 1] == '0')
		{
			ans++;
			ff(x + 1, y + 1);
		}
	}

	if(xrange(x - 1) && yrange(y + 1))
	{
		if(grid[x - 1][y + 1] == '1')
		{
			floodfill(x - 1, y + 1);
		}

		else if(grid[x - 1][y + 1] == '0')
		{
			ans++;
			ff(x - 1, y + 1);
		}
	}

	if(xrange(x - 1) && yrange(y - 1))
	{
		if(grid[x - 1][y - 1] == '1')
		{
			floodfill(x - 1, y - 1);
		}

		else if(grid[x - 1][y - 1] == '0')
		{
			ans++;
			ff(x - 1, y - 1);
		}
	}

	if(xrange(x + 1) && yrange(y - 1))
	{
		if(grid[x + 1][y - 1] == '1')
		{
			floodfill(x + 1, y - 1);
		}

		else if(grid[x + 1][y - 1] == '0')
		{
			ans++;
			ff(x + 1, y - 1);
		}
	}

	if(xrange(x) && yrange(y + 1))
	{
		if(grid[x][y + 1] == '1')
		{
			floodfill(x, y + 1);
		}

		else if(grid[x][y + 1] == '0')
		{
			ans++;
			ff(x, y + 1);
		}
	}

	if(xrange(x + 1) && yrange(y))
	{
		if(grid[x + 1][y] == '1')
		{
			floodfill(x + 1, y);
		}

		else if(grid[x + 1][y] == '0')
		{
			ans++;
			ff(x + 1, y);
		}
	}

	if(xrange(x - 1) && yrange(y))
	{
		if(grid[x - 1][y] == '1')
		{
			floodfill(x - 1, y);
		}

		else if(grid[x - 1][y] == '0')
		{
			ans++;
			ff(x - 1, y);
		}
	}

	if(xrange(x) && yrange(y - 1))
	{
		if(grid[x][y - 1] == '1')
		{
			floodfill(x, y - 1);
		}

		else if(grid[x][y - 1] == '0')
		{
			ans++;
			ff(x, y - 1);
		}
	}


}

void ff(int x, int y)
{
	grid[x][y] = 'm';

	if(xrange(x + 1) && yrange(y + 1))
	{
		if(grid[x + 1][y + 1] == '0')
		{
			ff(x + 1, y + 1);
		}
	}

	if(xrange(x - 1) && yrange(y + 1))
	{
		if(grid[x - 1][y + 1] == '0')
		{
			ff(x - 1, y + 1);
		}
	}

	if(xrange(x + 1) && yrange(y - 1))
	{
		if(grid[x + 1][y - 1] == '0')
		{
			ff(x + 1, y - 1);
		}
	}

	if(xrange(x - 1) && yrange(y - 1))
	{
		if(grid[x - 1][y - 1] == '0')
		{
			ff(x - 1, y - 1);
		}
	}

	if(xrange(x) && yrange(y + 1))
	{
		if(grid[x][y + 1] == '0')
		{
			ff(x, y + 1);
		}
	}

	if(xrange(x + 1) && yrange(y))
	{
		if(grid[x + 1][y] == '0')
		{
			ff(x + 1, y);
		}
	}

	if(xrange(x - 1) && yrange(y))
	{
		if(grid[x - 1][y] == '0')
		{
			ff(x - 1, y);
		}
	}

	if(xrange(x) && yrange(y - 1))
	{
		if(grid[x][y - 1] == '0')
		{
			ff(x, y - 1);
		}
	}
}

int main()
{
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);

	tr1 :: unordered_map <int, char> xx;

	xx[0] = 'W';
	xx[1] = 'A';
	xx[2] = 'K';
	xx[3] = 'J';
	xx[4] = 'S';
	xx[5] = 'D';
	
	int cs = 1;

	while(cin >> n >> m, n || m)
	{
		vector <int> v;

		for(int i = 0 ; i < 202 ; i++)
		{
			grid[i].clear();
		}

		tr1 :: unordered_map <char, string> code;

		code['0'] = "0000";
		code['1'] = "0001";
		code['2'] = "0010";
		code['3'] = "0011";
		code['4'] = "0100";
		code['5'] = "0101";
		code['6'] = "0110";
		code['7'] = "0111";
		code['8'] = "1000";
		code['9'] = "1001";
		code['a'] = "1010";
		code['b'] = "1011";
		code['c'] = "1100";
		code['d'] = "1101";
		code['e'] = "1110";
		code['f'] = "1111";

		for(int  i = 0 ; i < 4 * m + 2 ; i++)
		grid[0] += '0';


		for(int  i = 0 ; i < 4 * m + 2 ; i++)
		grid[n + 1] += '0';

		for(int i = 1 ; i <= n ; i++)
		{
			string s;
			cin >> s;

			grid[i] += '0';

			for(int j = 1 ; j <= m ; j++)
			{
				for(int k = 0 ; k < 4 ; k++)
				{
					grid[i] += code[s[j - 1]][k];
				}
			}

			grid[i] += '0';
		}

		//func();

		for(int i = 0 ; i < n + 2 ; i++)
		{
			for(int j = 0 ; j < 4 * m + 2 ; j++)
			{
				ans = 0;
				int chk = 0;

				if(grid[i][j] == '1')
				{
					//func();
					//cout << endl;
					chk = 1;
					floodfill(i, j);

				}

				if(chk)
				{
					v.push_back(v.size() == 0 ? ans - 1 : ans);
				}
			}
		}

		string str;

		for(int i = 0 ; i < v.size() ; i++)
		{
			str += xx[v[i]];
		}

		sort(str.begin(), str.end());

		cout << "Case " << cs++ << ": " << str << endl;

	}
}
