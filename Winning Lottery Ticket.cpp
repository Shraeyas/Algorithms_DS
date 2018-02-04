#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

long long bits(string s)
{
	long long ans = 0;
	
	for(long long i = 0 ; i < s.length() ; i++)
	{
    	ans |= (1 << (s[i] - '0'));
    }
    
    return ans;
}

int main()
{
	freopen("in.in", "r", stdin);
	
	int n;
	cin >> n;
	
	long long *ar = new long long [2000000];
	memset(ar, 0, 2000000 * sizeof(long long));
	vector <long long> v;
	
	long long ans = 0;
	long long mul = pow(2, 10) - 1;
	
	for(int i = 0 ; i < n ; i++)
	{
		string s;
		cin >> s;
		
		long long x = bits(s);
		
		if(ar[x])
		{
			ar[x]++;
		}
		
		else
		{
			ar[x]++;
			v.push_back(x);
		}
	}
	
	long long sz = v.size();
	
	for(long long i = 0 ; i < sz ; i++)
	{
		for(long long j = i + 1 ; j < sz ; j++)
		{
			if(v[i] | v[j] == mul)
			{
				ans += ar[v[i]] * ar[v[j]];
			}
		}
	}
	
	cout << ans;
}
