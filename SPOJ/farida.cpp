#include<stdio.h>
#include<cstring>
#define max1 10001

long a[max1];
long long dp[max1*4];
int n;

long long max(long long x, long long y)
{
	return x>y?x:y;
}

long long solve(int pos)
{
	if(dp[pos]!=0)
	return dp[pos];
	
	if(pos == n)
	return dp[pos] = 0;
	
	if(pos == n-1)
	return dp[pos] = a[pos];
	
	return dp[pos] = max(solve(pos + 2) + a[pos], solve(pos + 1));
}

int main()
{	
	int t, cs=1;
	scanf("%d", &t);
	
	while(t--)
	{
		memset(dp, 0, sizeof(dp));
		
		scanf("%d", &n);
			
		for(int i=0;i<n;i++)
		{
			scanf("%ld", &a[i]);
		}
		
		printf("Case %d: %lld\n", cs++, solve(0));
	}
}
