#include <bits/stdc++.h>

using namespace std;

int main()
{
	//freopen("in.in", "r", stdin);
	
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	
	int *ar = new int [n];
	
	for(int i = 0 ; i < n ; i++)
	{
		cin >> ar[i];
	}
	
	int ans = INT_MIN, prod = 0;
	
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = i + 1 ; j < n ; j++)
		{
			for(int k =  i ; k <= j ; k++)
			{
				for(int l = k + 1 ; l <= j ; l++)
				{
					//cout << k << " " << l << endl;
					prod += ar[k] * ar[l];
				}
				
			}	
            
				ans = max(ans, prod);
				prod = 0;
		}	
	}
	
	cout << ans;
	
}


