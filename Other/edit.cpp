#include<iostream>
#include<map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	
	int t;
	cin>>t;
	
	while(t--)
	{
		string a, b;
		cin>>a>>b;
		
		int m = a.length(), n=b.length();
		map<int, map<int, int> >dp;
		
		for(int i=0;i<=m;i++)
		{
			for(int j=0;j<=n;j++)
			{
				if(i == 0)
				{
					dp[i][j] = j;
				}
				
				else if(j == 0)
				{
					dp[i][j] = i;
				}
				
				else if(a[i-1] == b[j-1])
				{
					dp[i][j] = dp[i-1][j-1];
				}
				
				else
				{
					dp[i][j] = 1 + min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]);
				}
			}
		}
		
		cout<<dp[m][n]<<endl;
	}
}
