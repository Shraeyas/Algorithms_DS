#include <iostream>

using namespace std;

bool possible(int a, int b, int t)
{
	if(a == b)
	return 1;
	
	if(a > b)
	{
		int m_r_b;
		
		if(t % 2 == 0)
		m_r_b = (10 - t)/2;
		
		else
		m_r_b = (10 - t + 1)/2;
		
		return (m_r_b >= (a - b));
	}
	
	if(b > a)
	{
		int m_r_a;
		
		if(t % 2 == 0)
		m_r_a = (10 - t)/2;
		
		else
		m_r_a = (10 - t + 1)/2 - 1;
		
		return (m_r_a >= (b - a));
	}
}

int main()
{
	freopen("in.in", "r", stdin);
	
	char s[20];
	
	while(scanf("%s", s) != EOF)
	{
		int a = 0, b = 0, ch = 1;
		
		for(int i = 1 ; i <= 10 ; i++)
		{
			if(i % 2 == 1)
			{
				if(s[i - 1] == '1')
				a++;
			}
			
			else
			{
				if(s[i - 1] == '1')
				b++;
			}
			
			if(!possible(a, b, i))
			{
				ch = 0;
				
				if(a > b)
				{
					cout << "TEAM-A " << i << endl;
				}
				
				else
				{
					cout << "TEAM-B " << i << endl;
				}
				
				break;
			}
		}
		
		if(ch)
		{
			for(int i = 10 ; i < 20 ; i += 2)
    			{
    				if(s[i] == '1')
    				a++;
    				
    				if(s[i + 1] == '1')
    				b++;
    				
    				if(a != b)
    				{
    					if(a > b)
						{
							cout << "TEAM-A " << i + 2 << endl;
						}
						
						else
						{
							cout << "TEAM-B " << i + 2 << endl;
						}
						
    					break;
    				}
    			}
    			
    			if(a == b)
    			cout << "TIE" << endl;
		}
	}
}
