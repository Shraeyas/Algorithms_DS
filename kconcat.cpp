#include <iostream>
#include <vector>

#define LONG_MIN -2147483647

using namespace std;

int main()
{
	freopen("in.in", "r", stdin);
	
	long t;
	cin >> t;
	
	while(t--)
	{
		vector <long> v;
				
		long n, k;
		cin >> n >> k;
		
		long lsum = LONG_MIN, rsum = LONG_MIN, tsum = 0, csum = LONG_MIN;
		
		for(long i = 0 ; i < n ; i++)
		{
			long x;
			cin >> x;
			
			v.push_back(x);
			tsum += x;
		}
		
		long x = 0;
		for(long i = 0 ; i < n ; i++)
		{
			x += v[i];
			if(lsum < x)
			{
				lsum = x;
			}
		}
		
		x = 0;
		for(long i = n - 1 ; i >= 0 ; i--)
		{
			x += v[i];
			if(rsum < x)
			{
				rsum = x;
			}
		}
		
		x = LONG_MIN;
		for(long i = 0 ; i < n ; i++)
		{
			if(x == LONG_MIN)
			{
				x = v[i];
			}
			
			else
			{
				x += v[i];
			}
			
			if(csum < x)
			{
				csum = x;
			}
			
			if(x < 0)
			{
				x = LONG_MIN;
			}
		}
		
		//cout << csum << " " << lsum << " " << rsum << endl << endl;
		
		/*
			k * tsum
			rsum + (k - 1) * tsum
			(k - 1) * tsum + lsum
			rsum + (k - 2) * tsum + lsum
		*/
			
			
		if(k == 1)
		{
			cout << csum << endl;
		}
		
		else if(k == 2)
		{
			
			long ans = max(k * tsum, rsum + (k - 2) * tsum + lsum);
			ans = max(ans, rsum + lsum);
			//ans = max(ans, rsum + tsum + lsum);
			ans = max(ans, csum);
			ans = max((k - 1) * tsum + lsum, ans);
			ans = max((k - 1) * tsum + rsum, ans);
				
			cout << ans << endl;
			
		}
		
		else
		{	
			long ans = max(k * tsum, rsum + (k - 2) * tsum + lsum);
			ans = max(ans, rsum + lsum);
			ans = max(ans, rsum + tsum + lsum);
			ans = max(ans, csum);
			ans = max((k - 1) * tsum + lsum, ans);
			ans = max((k - 1) * tsum + rsum, ans);
				
			cout << ans << endl;
			
		}
	}
}
