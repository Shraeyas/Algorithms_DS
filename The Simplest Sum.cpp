#include <iostream>
#include <cmath>

#define mod 1000000007

using namespace std;

long long solve(long long k, long long n)
{
	int r = floor((log(n * (k - 1)/k + 1))/log(k));
	
	long long term = 0;
	long long mul = n;
	long long add = 1;
	long long ans = 0;
	
	for(long long i = 0 ; i <= r ; i++)
	{
		term = (term + add) % mod;
		mul = (n - (term) + 1) % mod;
		
		//cout << mul << endl;
		
		add = (add * k) % mod;
		
		ans = (ans + (term * mul) % mod) % mod;
	}
	
	return ans;
}

long long org(long long k, long long n) 
{
    long long sum = 0;

    for (long long i = 1 ; i <= n % mod ; i += 1) 
	{
        sum = (sum + i) % mod;
        i = (i * k) % mod;
    }

    return sum;
}

int main()
{
	//freopen("in.in", "r", stdin);
	
	cout << ((99999999999 - 99999999888) + 1) % mod << endl;
	cout <<mod + ((99999999999 % mod - 99999999888) + 1) % mod << endl;
	
	int q;
	cin >> q;
	
	label:;
	
	
	while(q--)
	{
		long long k, a, b;
		cin >> k >> a >> b;
		
		if(a == 1)
		{
			cout << solve(k, b) << endl;
		}
		
		else
		{
			cout << solve(k, b) - solve(k, a - 1) << endl;
		}
	}
}
