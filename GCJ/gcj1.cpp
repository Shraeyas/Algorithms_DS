#include <iostream>

using namespace std;

long long p;

long long pow(long long x, long long y)
{
	long long num = 1;
	
	while(y)
	{
		if(y & 1)
		num = (num * x) % p;
		
		x = (x * x) % p;
		y >>= 1;
	}
	
	return num;
}

int main()
{
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
	
	long long t, cs = 1;
	cin >> t;
	
	while(t--)
	{
		long long a, n, nf = 1;
		cin >> a >> n >> p;
		nf = a;
		for(long long i = 1 ; i <= n ; i++)
		{
			nf = pow(nf, i) % p;
		}
		
		cout << "Case #" << cs++ << ": " << nf % p << endl;
	}
}
