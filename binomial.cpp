#include <iostream>
#include <tr1/unordered_map>

#define mod 1000000007

using namespace std;

tr1 :: unordered_map <int, long> fact;

long pow(long x, long y)
{
    long ans = 1;
    
    while(y)
    {
        if(y&1)
        ans = (ans * x) % mod;
        
        x = (x * x) % mod;
        
        y >>= 1;
    }
    
    return ans;
}

void calc()
{
	fact[0] = 1;
	
	for(int i = 1 ; i <= 1000 ; i++)
	{
		fact[i] = (fact[i - 1] * i) % mod;
	}
}

long pg(int i, int j)
{
	if(i <= j)
	return (i * j) % mod;
	
	long r = (fact[i] * pow(fact[j], mod - 2)) % mod;
	
	return (r * pow(fact[i - j], mod - 2)) % mod;
}

int main()
{
	int t;
	cin >> t;
	
	calc();
	
	while(t--)
	{
		long ans = 0;
		
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		
		for(int i = a ; i <= b ; i++)
		{
			for(int j = c ; j <= d ; j++)
			{
				ans = (ans + pg(i, j)) % mod;
			}
		}
		
		cout << ans << endl;
	}
}
