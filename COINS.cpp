#include<iostream>
#include<map>

using namespace std;

map<long, long>dp;

long pg(long n)
{
	if(dp[n]!=0)
	{
		return dp[n];
	}
	
	if(n/2 + n/3 + n/4 > n)
	{
		return dp[n] = pg(n/2) + pg(n/3) + pg(n/4); 
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
		
		printf("%ld\n", pg(n));
	}
}
