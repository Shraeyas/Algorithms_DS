    #include <bits/stdc++.h>
     
    using namespace std;
     
    bool possible(int a, int b, int i)
    {
    	if(a == b)
    	return 1;
    	
    	int move;
    	
    	if(a > b)
    	{
    		if(i % 2 == 0)
    		{
    			move = (10 - i) / 2 + 1;
    		}
    		
    		else
    		{
    			i++;
    			move = (10 - i) / 2 + 1;
    		}
    		
    		return move >= (a - b);
    	}
    	
    	else
    	{		
    		if(i % 2 == 0)
    		{
    			move = (10 - i) / 2;
    		}
    		
    		else
    		{
    			i--;
    			move = (10 - i) / 2;
    		}
    		
    		return move >= (b - a);
    	}
    }
     
    string win(int a, int b, int i)
    {
    	if(a > b)
    	{
    		return "TEAM-A ";
    	}
    	
    	return "TEAM-B ";
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
    			if(possible(a, b, i))
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
    			}
    			
    			else
    			{
    				ch = 0;
    				cout << win(a, b, 0) << i - 1 << endl;
    				break;
    			}
    		}
    		
    		if(a != b && ch)
    		{
    			cout << win(a, b, 0) << ((a > b) ? 9 : 10) << endl;
			}
    		
    		else if(ch)
    		{	
    			for(int i = 10 ; i < 20 ; i += 2)
    			{
    				if(s[i] == '1')
    				a++;
    				
    				if(s[i + 1] == '1')
    				b++;
    				
    				if(a != b)
    				{
    					cout << win(a, b, 0) << i + 2 << endl;
    					break;
    				}
    			}
    			
    			if(a == b)
    			cout << "TIE" << endl;
    		}
    	}
    } 
