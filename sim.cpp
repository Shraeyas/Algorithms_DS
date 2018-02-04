#include <iostream>
#include <cmath>

#define mod 1000000007

using namespace std;

long long pos(long long x)
{
	if(x < 0)
	return x * (-1);
	
	return x;
}

long long solve(long long k, long long n)
{
	int r = floor((log(n * (k - 1)/k + 1))/log(k));
	
	cout << r << endl;
	
	long long term = 0;
	long long mul = n;
	long long add = 1;
	long long ans = 0;
	
	for(long long i = 0 ; i <= r ; i++)
	{
		term = (term + add) % mod;
	//	mul = (n - (term) + 1);
		
		mul = (pos(n - term) + 1) % mod;
		
		//cout << mul << endl;
		
		add = (add * k) % mod;
		
		ans = (ans + (term * mul)) % mod;
	}
	
	return ans;
}

long long org(long long k, long long n) 
{
    long long sum = 0;

    for (long long i = 1 ; i <= n ; i += 1) 
	{
        sum = (sum + i) % mod;
        i = (i * k) % mod;
    }

    return sum % mod;
}

int main()
{
	//freopen("in.in", "r", stdin);
	
	// 9 99900 99930
	

	cout << solve(9, 99900 - 1) - solve(9, 99930) << endl;
	long long out = 0;
	
	for(long long a = 99900 ; a <= 99930 ; a++)
	{
		out = (out + org(9, a)) % mod;
	}
	cout << endl << out;
	/*
	for(long long k = 2 ; k <= 1000 ; k++)
	{
		for(long long a = 99900 ; a <= 100000 ; a++)
		{
			for(long long b = a ; b <= 100000 ; b++)
			{
				long long myans, organs = 0;
				
				if(a == 1)
				{
					myans = solve(k, b);
				}
				
				else
				{
					long long ans = (solve(k, b) % mod - solve(k, a - 1) % mod) % mod;
					ans = ((ans < 0) ? (ans * (-1)) : ans);
					
					myans = ans;
				}
				
				for(long long i = a ; i <= b ; i++)
				{
					organs = (organs + org(k, i)) % mod;
				}
				
				if(myans != organs)
				{
					cout << k << " " << a << " " << b << endl;
					cout << myans << " " << organs << endl;
					
					goto label;
				}
			}
		}
		
		cout << k << endl;
	}
	
	label:;
	/*
	
	
	long long q;
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
			
			long long ans = (solve(k, b) % mod - solve(k, a - 1) % mod) % mod;
			cout << ((ans < 0) ? (ans * (-1)) : ans) << endl;
		}
	}*/
}
