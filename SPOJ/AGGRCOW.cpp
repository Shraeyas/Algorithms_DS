#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <long> v;

bool possible(long d, long c)
{
	long i = 1, prev = 0;
	
	while(i < v.size() && c)
	{
		if(v[i] - v[prev] >= d)
		{
			c--;
			prev = i;
			i++;
		}
		
		else
		{
			i++;
		}
	}
	
	if(c == 0)
	return 1;
	
	return 0;
}

int main()
{
	long t;
	cin >> t;
	
	while(t--)
	{
		v.clear();
		
		long n, c;
		cin >> n >> c;
		
		for(long i = 0 ; i < n ; i++)
		{
			long x;
			cin >> x;
			
			v.push_back(x);
		}
		
		sort(v.begin(), v.end());
		
		long start = v[0], end = v[n - 1];
		long mid = (start + end)/2;
		long ans = -1;
		
		while(start <= end)
		{
			bool ch = possible(mid, c - 1);
			
			if(ch)
			{
				ans = max(ans, mid);
				start = mid + 1;
			}
			
			if(!ch)
			{
				end = mid - 1;
			}
			
			mid = (start + end)/2;
		}
		
		cout << ans << endl;
	}
}
