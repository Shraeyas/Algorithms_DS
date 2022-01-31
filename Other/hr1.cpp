#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("in.in", "r", stdin);
	
	int t;
	cin >> t;
	
	while(t--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		
		int ans = 0;
		
		while(1)
		{
			if(abs(2 * ans - a - b) == abs(c - ans))
			break;
			
			ans++;
		}
		
		cout << ans << endl;
	}
}
