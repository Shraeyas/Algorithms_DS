#include <iostream>
#include <algorithm>
#include <vector>
#include <tr1/unordered_map>

using namespace std;

int main()
{
	int t;
	cin >> t;
	
	while(t--)
	{
		long long ans = 0;
		
		int n;
		cin >> n;
		
		vector <long> mat[n];
		
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < n ; j++)
			{
				int x;
				cin >> x;
				
				mat[i].push_back(x);
			}
			
			sort(mat[i].rbegin(), mat[i].rend());
		}
		
		ans = mat[n - 1][0];
		long last = mat[n - 1][0];
		bool ch = 0;
		
		for(int i = n - 2 ; i >= 0 ; i--)
		{
			ch = 0;
			for(int j = 0 ; j < n ; j++)
			{
				if(last > mat[i][j])
				{
					ans += mat[i][j];
					last = mat[i][j];
					
					ch = 1;
					
					goto ss;
				}
			}
			
			ss:;
			
			if(!ch)
			{
				cout << -1 << endl;
				goto label_;
			}
		}
		
		cout << ans << endl;
		
		label_:;
	}
}
