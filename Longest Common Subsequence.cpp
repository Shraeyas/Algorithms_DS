#include<iostream>
#include<map>

using namespace std;

int main()
{
	freopen("C:\\Users\\Shraeyas\\Documents\\pg\\pr_ag\\prag_lcs.txt", "r", stdin);
	
	map<long, map<long, long> >dp;
	
	string s1, s2;
	cin>>s1>>s2;
	
	for(long i=0;i<s1.length();i++)
	{
		for(long j=0;j<s2.length();j++)
		{
			if(s1[i] == s2[j])
			{
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			
			else
			{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	cout<<dp[s1.length()-1][s2.length()-1]<<endl;
}
