#include <iostream>
#include <cstring>

using namespace std;

string eval(string s, int n)
{
	string ans = "";
	ans += s[0];
	
	for(int i = 1 ; i < n ; i++)
	{
		if(s[i] != s[i - 1])
		{
			ans += s[i];
		}
	}
	
	return ans;
}

int lcs(string a, string b, int i, int j, int n, int m, int dp[][m + 1])
{
	if(i == n && j == m)
	{
		return 0;
	}
	
	if(dp[i][j] != -1)
	return dp[i][j];
	
	if(i == n)
	{
		return dp[i][j] = lcs(a, b, i, j + 1, n, m, dp);
	}
	
	if(j == m)
	{
		return dp[i][j] = lcs(a, b, i + 1, j, n, m, dp);
	}
	
	if(a[i] == b[j])
	{
		return dp[i][j] = lcs(a, b, i + 1, j + 1, n, m, dp) + 1;
	}
	
	else
	{
		return dp[i][j] = max(lcs(a, b, i + 1, j, n, m, dp), lcs(a, b, i, j + 1, n, m, dp));
	}
}

int main()
{
	//freopen("in.in", "r", stdin);

	ios_base :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--)
	{
		/**dp = new int [5001];
		for(int i = 0 ; i < 5001 ; i++)
		dp[i] = new int [5001];
		*/
		//memset(dp, -1, sizeof(int) * 5001 * 5001);
		
		
		int n, m;
		cin >> n >> m;
		
		string a, b;
		cin >> a >> b;
		
		a = eval(a, n);
		b = eval(b, m);
		
		n = a.length();
		m = b.length();
		
		int dp[n + 1][m + 1];
		
		for(int i = 0 ; i < n + 1 ; i++)
		{
			for(int j = 0 ; j < m + 1 ; j++)
			dp[i][j] = -1;
		}
		
		cout << a.length() + b.length() - lcs(a, b, 0, 0, n, m, dp) << endl;
		
		/*
		for(int i = 0 ; i < 5001 ; i++)
		delete [] dp[i];
		
		delete [] dp;
		*/
	}
}
