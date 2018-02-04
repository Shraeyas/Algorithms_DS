#include<iostream>
#include<string.h>
#include<map>

using namespace std;

map<long,map<long,long> >dp,op;

long min(long a, long b)
{
	return a<b ? a:b;
}

long res(string a, long m, string b, long n)
{
	if(op[m][n] != 0)
	return dp[m][n];
	
	if(m == 0)
	{
		op[m][n] = 1;
		return dp[m][n] = n;
	}
	
	if(n == 0)
	{
		op[m][n] = 1;
		return dp[m][n] = m;
	}
	
	if(a[m-1] == b[n-1])
	{
		op[m][n] = 1;
		return dp[m][n] = res(a,m-1,b,n-1);
	}
	
	
	op[m][n] = 1;
	return dp[m][n] = min(min(res(a,m,b,n-1),res(a,m-1,b,n)),res(a,m-1,b,n-1)) + 1;
}

int main()
{
	ios::sync_with_stdio(0);
	
	long t;
	cin>>t;
	
	while(t--)
	{
		//char a[2000],b[2000];
		dp.clear();
		op.clear();
		
		string a,b;
		cin>>a>>b;
		
		long m = a.length(), n = b.length();
		
		cout<<res(a,m,b,n)<<endl;
	}
}
