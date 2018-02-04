#include <iostream>
#include <vector>

using namespace std;

long prod(int i, vector <int> v, int p)
{
	if(i == v.size())
	{
		return p;
	}
	
	return max(prod(i + 1, v, v[i] * p), prod(i + 1, v, p));
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("in.in", "r", stdin);
	
	int n;
	vector <int> v;
	
	while(1)
	{
		while(cin >> n, n != -999999)
		{
			v.push_back(n);
		}
	}
}
