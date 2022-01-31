#include<iostream>
#include<map>

using namespace std;

map<long, long>dp;

long solve(long n)
{
	if(dp[n]!=0)
	{
		return dp[n];
	}
	
	if(n/2 + n/3 + n/4 > n)
	{
		return dp[n] = solve(n/2) + solve(n/3) + solve(n/4); 
	}
	
	if(n/2 + n/3 + n/4 <= n)
	{
		return n;
	}
}

int main()
{
	int t = 10;
	
	while(t--)
	{
		long n;
		scanf("%ld",&n);
		
		printf("%ld\n", solve(n));
	}
}
