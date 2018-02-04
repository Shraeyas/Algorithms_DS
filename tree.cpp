#include <iostream>
#define mod 1000000007

using namespace std;

long solve(long h)
{
	if(h == 0)
	{
		return 1;	
	}
	
	if(h == 1)
	{
		return 1;
	}
	
	int x = solve(h - 1);
	int y = solve(h - 2);
	
	return (((x * y) % mod + (x * x) % mod) % mod + (x * y) % mod) % mod;
}

int main()
{
	int h;
	cin >> h;
	
	cout << solve(h);
}
