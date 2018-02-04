    #include <iostream>
    #include <tr1/unordered_map>
     
    using namespace std;
     
    tr1 :: unordered_map <long, long> ar;
     
    long sum (long s)
    {    	
    	long ans = 0;
    	
    	while(s)
    	{
    		if(s % 2)
    		ans -= s % 10;
    		
    		else
    		ans += s % 10;
    		
    		s /= 10;
    	}
    	
    	return (ans < (0) ? (ans * (-1)) : ans);
    }
     
    long pr(long n)
    {
    	long ans = 0;
    	
    	for(long i = 1 ; i <= n ; i++)
    	{
    		for(long j = 1 ; j <= n ; j++)
    		{
     			ans += sum(i + j);
     			cout << sum(i + j) << " ";
    		}
    		cout << endl;
    	}
    	
    	return ans;
    }
     
    int main()
    {
    	for(long i = 2 ; i <= 1000000 ; i++)
    	{
    		
    		//cout << sum(i) << " ";
    		ar[i - 1] = ar[i - 2] + sum(i);
		}
    	
    	cout << ar[5] << endl;
    	
    	int t;
    	cin >> t;
    	
    	while(t--)
    	{
    		long n;
    		cin >> n;
    		
    		long ans = ar[n] * (n - 1) + (n - 1) * (n - 1);
    		cout << ans << endl;
    	}
    } 
