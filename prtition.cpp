            #include <iostream>
            #include <cstring>
             
            using namespace std;
             
            
            
            
            int main()
            {
            	
            	long long t;
            	cin >> t;
            	
            	while(t--)
            	{
            		long long n, x;
            		
            		cin >> x >> n;
            		
            		string ans = "0";
        		
        			for(long long i = 0 ; i <= n ; i++)
        			{
        				ans += '0';	
    				}
    				
    				ans[x] = '2';
    				
    				long long s;
    				
            		s = (n * (n + 1))/2 - x;
            		
            		if(s % 2)
            		{
            			cout << "impossible" << endl;
            			goto pg;
					}
            		
            		
            		s /= 2;
            		
            		for(long long i = n ; i >= 1 ; i--)
            		{
            			if(i == x)
            			continue;
            			
            			if(s >= i && ((s - i) > n))
            			{
            				s -= i;
            				ans[i] = '1';
    					}
    					
    					else if(s >= i && ((s - i <= n) && ans[s - i] != '2'))
    					{
    						s -= i;
            				ans[i] = '1';
    					}
    					
    					if(!s)
    					break;
    				}
    				
    				if(s > 0)
    				cout << "impossible";
            		
            		else
            		for(long long i = 1 ; i <= n ; i++)
            		cout << ans[i];
            		cout << endl;
            		
            		pg:;
            		
            		//delete [] hash;
            	}
            }   
