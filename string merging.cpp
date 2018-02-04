#include <iostream>
#include <tr1/unordered_map>

using namespace std;

tr1 :: unordered_map <int, tr1 :: unordered_map <int, int> > dp;

int solve(int i, int j, int n, int m, string s1, string s2, string ans, int k)
{
	if(i == s1.length() && j == s2.length())
	{
		return 1;
	}
	
	if(dp[i][j])
	return dp[i][j];
	
	if(k == 0)
	{
		return min(solve(i + 1, j, n, m, s1, s2, ans + s1[i], k + 1), solve(i, j + 1, n, m, s1, s2, ans + s2[j], k + 1));
	}
	
	if(i < s1.length() && j < s2.length())
	{
		int x, y;
		
		if(s1[i] == ans[k - 1])
		{
			x = solve(i + 1, j, n, m, s1, s2, ans + s1[i], k + 1);
		}
		
		else
		{
			x = solve(i + 1, j, n, m, s1, s2, ans + s1[i], k + 1) + 1;
		}
		
		
		if(s2[j] == ans[k - 1])
		{
			y = solve(i, j + 1, n, m, s1, s2, ans + s2[j], k + 1);
		}
		
		else
		{
			y = solve(i, j + 1, n, m, s1, s2, ans + s2[j], k + 1) + 1;
		}
		
		return dp[i][j] = min(x, y);
	}
	
	else
	{
		int x;
		
		if(i < s1.length())
		{
			if(s1[i] == ans[k - 1])
			{
				x = solve(i + 1, j, n, m, s1, s2, ans + s1[i], k + 1);
			}
			
			else
			{
				x = solve(i + 1, j, n, m, s1, s2, ans + s1[i], k + 1) + 1;
			}
		}
		
		else
		{
			if(s2[j] == ans[k - 1])
			{
				x = solve(i, j + 1, n, m, s1, s2, ans + s2[j], k + 1);
			}
			
			else
			{
				x = solve(i, j + 1, n, m, s1, s2, ans + s2[j], k + 1) + 1;
			}
		}
		
		return dp[i][j] = x;
	}
}

int main()
{
	//freopen("in.in", "r", stdin);
	
	int t;
	cin >> t;
	
	while(t--)
	{
		dp.clear();
		
		int n, m;
		cin >> n >> m;
		
		string s1, s2;
		cin >> s1 >> s2;
		
		cout << solve(0, 0, n, m, s1, s2, "", 0) << endl;
	}
}
