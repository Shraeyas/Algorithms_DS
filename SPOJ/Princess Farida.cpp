#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main()
{
	long long t,cs=1;
	cin>>t;
	
	while(t--)
	{
		long long n;
		cin>>n;
		
		vector<long long>p;
		map<long long,long long>dp;
		
		for(long long i=0;i<n;i++)
		{
			long long x;
			cin>>x;
			
			p.push_back(x);
		}
		
		if(n>0)
		{
			dp[0] = p[0];
		}
		
		if(n>1)
		{
			dp[1] = max(p[0] , p[1]);
		}
		
		for(long long i=2;i<n;i++)
		{
			dp[i]+= max(dp[i-1], p[i]+dp[i-2]);
		}
		
		cout<<"Case "<<cs++<<": "<<dp[n-1]<<"\n";
	}
}
