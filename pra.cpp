        #include <iostream>
         
        using namespace std;
         
        bool ch = 0;
        int n, x;
         
        bool solve(int i, int s1, int s2, string ans)
        {
        	if(i == n + 1)
        	{
        		if(s1 == s2)
        		{
        			//cout << ans << endl;
        			
        			for(int i = 0 ; i < ans.length() ; i++)
        			{
        				if(ans[i] == '0')
        				cout << i + 1 << " ";
					}
					cout << endl << endl;
					
        			for(int i = 0 ; i < ans.length() ; i++)
        			{
        				if(ans[i] == '1')
        				cout << i + 1 << " ";
					}
					cout << endl;
					
        			return 1;
        		}
        		
        		else
        		{
        			return 0;
        		}
        	}
        	
        	if(i == x)
        	{
        		return solve(i + 1, s1, s2, ans + "2");
        	}
        	
        	if(!solve(i + 1, s1 + i, s2, ans + "0"))
        	return solve(i + 1, s1, s2 + i, ans + "1");
        	
        	return 1;
        }
         
        int main()
        {
        	freopen("in.in", "r", stdin);
        	
        	int t;
        	cin >> t;
        	
        	while(t--)
        	{
        		cin >> x >> n;
        		
        		bool f = 0;
    		
    			if(n % 2 == 1)
    			{
    				f = (((n + 1) / 2) % 2 == 1 ? 1 : 0);
    			}
    			
    			else
    			{
    				f = (((n) / 2) % 2 == 1 ? 1 : 0);
    			}
    			
    			if(f)
    			{
    				if(x % 2 == 0)
    				{
    					cout << "impossible" << endl;
    					goto pg;
    				}
    			}
    			
    			else
    			{
    				if(x % 2 == 1)
    				{
    					cout << "impossible" << endl;
    					goto pg;
    				}
    			}
    			
    			
    			
        		
        		if(!solve(1, 0, 0, ""))
        		{
        			cout << "impossible" << endl;
        		}
        		
        		pg:;
        		
        		cout << endl << endl << "Case  \n";
        	}
        }  
