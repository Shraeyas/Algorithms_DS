#include <iostream>
#include <tr1/unordered_map>

using namespace std;

int main()
{
	freopen("in.in", "r", stdin);
	
	int t;
	cin >> t;
	
	while(t--)
	{
		tr1 :: unordered_map <int, tr1 :: unordered_map <int, int> > mtr;
		
		int n, q;
		cin >> n >> q;
		
		for(int i = 0 ; i < q ; i++)
		{
			int x, y, z;
			cin >> x >> y >> z;
			
			mtr[x][y] = ((z == 0) ? -1 : 1);
		}
		
		for(int i = 1 ; i <= n ; i++)
		{
			for(int j = 1 ; j <= n ; j++)
			{
				if(mtr[i][j] != 0 && i != j)
				{
					for(int k = 1 ; k <= n ; k++)
					{
						if(mtr[j][k] != 0)
						{
							if(mtr[k][i] != 0)
							{
								if(mtr[i][j] == mtr[j][k] && mtr[j][k] == mtr[k][i])
								{
									cout << "no" << endl;
									goto label;
								}
							}
						}
					}
				}
			}
		}
		
		cout << "yes" << endl;
		label:;
	}
}
