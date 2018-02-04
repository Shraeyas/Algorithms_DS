#include <iostream>
#include <tr1/unordered_map>

using namespace std;

int main()
{
	int t;
	cin >> t;
	
	while(t--)
	{
		long long n;
		cin >> n;
		
		long long ans = n * n * (n + 1);
		
		if(n > 4)
		{
			long long x = 3 + (n - 5) * 4;
			long long y = (n - 5);
			
			ans -= x * (x + y);
		}
		
		cout << ans << endl;
	}
}
