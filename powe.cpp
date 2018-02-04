#include <iostream>
#include <tr1/unordered_map>

using namespace std;

int x = 0;
tr1 :: unordered_map <int, int> dp;

int power(int a, int b, int c)
{
	x++;

	if(b == 0)
	return dp[b] = 1;
	
	if(b % 2)
	{
		return dp[b] = power((a * a) % c, b/2, c);
	}
	
	else
	{
		return dp[b] = (a * power((a * a) % c, (b - 1)/2, c)) % c;
	}
}

int main()
{
	cout << power(2, 300, 7);
	cout << endl << x;
}
