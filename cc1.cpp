#include <iostream>

using namespace std;

char swap(char sym)
{
	if(sym == 'R')
	return 'G';
	
	return 'R';
}

int add(char s1, char s2)
{
	if(s1 == 'R' && s2 == 'G')
	return 5;
	
	if(s1 == 'G' && s2 == 'R')
	return 3;
}

int main()
{
	freopen("in.in", "r", stdin);
	
	int t;
	cin >> t;
	
	while(t--)
	{
		int n, m, ans = 0, ansp = 0;
		char s1 = 'G', s2 = 'R';
		cin >> n >> m;
		
		string s[n];
		
		for(int i = 0 ; i < n ; i++)
		{
			cin >> s[i];
		}
		
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < m ; j++)
			{
				if(s[i][j] != s1)
				{
					ans += add(s[i][j], s1);
				}
				
				if(s[i][j] != s2)
				{
					ansp += add(s[i][j], s2);
				}
				
				s1 = swap(s1);
				s2 = swap(s2);
			}
			
			if(m % 2 == 0)
			{
				s1 = swap(s1);
				s2 = swap(s2);
			}
		}
		
		cout << min(ans, ansp) << endl;
	}
}
