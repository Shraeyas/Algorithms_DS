#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector <int> v;
	
	for(int i = 0 ; i < n ; i++)
	{
		int x;
		cin >> x;
		
		v.push_back(x);
	}
	
	int ans = -99999, sum = 0;
	
	for(int i = 0 ; i < n ; i++)
	{
		if(sum < 0)
		{
			ans = max(ans, sum);
			sum = 0;
		}
		
		sum += v[i];
		ans = max(ans, sum);
	}
	
	cout << ans;
}
