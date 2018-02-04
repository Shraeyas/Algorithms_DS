#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int ans = 0;
int n;
int *a = new int[n];

void solve(int i, int j)
{
	if(j - i < 1)
	return;
	
	if(i == 0)
	{
		if(a[j])
		{
			ans++;
		}
		
		solve(i + 1, j);
		solve(i, j - 1);
		solve(i + 1, j - 1);
		
		return;
	}
	
	if(a[j] - a[i - 1] > 0)
	{
		ans++;
		
		solve(i + 1, j);
		solve(i, j - 1);
		solve(i + 1, j - 1);
		
		return;
	}
}

int main()
{
	int k;
	cin >> n >> k;
	
	memset(a, 0, n * sizeof(int));
	
	vector <int> v(n);
	
	for(int i = 0 ; i < n ; i++)
	{
		cin >> v[i];
		
		if(v[i] % k == 0)
		{
			if(i == 0)
			{
				a[i] = 1;
			}
			
			else
			{
				a[i] = a[i - 1] + 1;
			}
		}
		
		else
		{
			if(i == 0)
			{
				a[i] = 0;
			}
			
			else
			{
				a[i] = a[i - 1];
			}
		}
	}
	
	for(int i = 0 ; i < n ; i++)
	cout << a[i] << " ";
		
	solve(0, n - 1);
	cout << endl << ans;
	
}
