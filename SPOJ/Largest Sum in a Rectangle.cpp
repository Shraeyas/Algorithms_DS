#include <tr1/unordered_map>
#include <iostream>
#include <vector>

using namespace std;

tr1 :: unordered_map <int, tr1 :: unordered_map <int, int> > dp;

void solve (int r, int c)
{
	for (int i = 0 ; i < r ; i++)
	{
		for (int j = 0 ; j < c ; j++)
		{
			dp [i][j] = 0;
		}
	}
}

int main ()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		vector <int> v;
		
		int n;
		cin >> n;
		
		for (int i = 0 ; i < n ; i++)
		{
			int x;
			cin >> x;
			
			v.push_back (x);
		}
		
		solve(0, 0);
	}
}
