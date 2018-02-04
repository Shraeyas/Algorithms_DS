#include <iostream>

using namespace std;

int solve(string s, int i, int j)
{
	
	if(j < 0 || i >= s.length())
	return 0;
	
	cout << i << " " << j << endl;
	
	if(i == j)
	return 1;
	
	if(s[i] == s[j])
	{
		int x = solve(s, i, j - 1);
		int y = solve(s, i + 1, j);
		int z = 1;
		
		return x + y + z;
	}
	
	else 
	{
		int x = solve(s, i, j - 1);
		int y = solve(s, i + 1, j);
		int z = solve(s, i + 1, j - 1);
		
		return x + y - z;
	}
}

int main()
{
	int t = 1;
		
	while(t--)
	{
		string s;
		cin >> s;
		
		cout << solve(s, 0, s.length());
	}
}
