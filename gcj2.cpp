#include <iostream>
#include <cstring>

using namespace std;

int *red, *blue, n;
long *r, *b, ans = 999999;

long max(long x, long y)
{
	if(x < y)
	return x;
	
	return y;
}

void solve(long long cur)
{
	int ch = 0, in = cur;
	
	for(int i = 0 ; i < n ; i++)
	{
		if(!red[i])
		{
			red[i] = 1;
			
			for(int j = 0 ; j < n ; j++)
			{
				if(!blue[j])
				{
					cur += r[i] ^ b[j];
					
					solve(cur);
					
					red[i] = 0, blue[j] = 1;
					solve(cur);
					ch = 1;
					
					blue[j] = 0;
					
				}
			}
		}
	}
	
	if(ch == 0)
	ans = max(ans, cur);
}

int main()
{
	int t, cs = 1;
	cin >> t;
	
	while(t--)
	{
		ans = 999999;
		cin >> n;
		
		red = new int [n + 1];
		blue = new int [n + 1];
	
		r = new long [n];
		b = new long [n];
		
		memset(red, 0, (n + 1) * sizeof(int));
		memset(blue, 0, (n + 1) * sizeof(int));
		
		for(int i = 0 ; i < n ; i++)
		{
			cin >> r[i];
		}
		
		for(int i = 0 ; i < n ;i++)
		{
			cin >> b[i];
		}
		
		solve(0);
		
		cout << "Case #" << cs++ << ": " << ans << endl;
	}
}
