    #include <iostream>
    #include <vector>
    #include <tr1/unordered_map>
     
    using namespace std;
     
    int main()
    {
    	freopen("in.in", "r", stdin);
    	
    	int t;
    	cin >> t;
    	
    	while(t--)
    	{
    		vector <int> v, org;
    		tr1 :: unordered_map <int, vector <int> > ar;
    		tr1 :: unordered_map <int, int> ans;
    		
    		int n;
    		cin >> n;
    		
    		for(int i = 0 ; i < n ; i++)
    		{
    			int x;
    			cin >> x;
    			
    			org.push_back(x);
    			
    			if(ar[x].size() == 0)
    			{
    				ar[x].push_back(-1);
    				ar[x].push_back(-1);
    				
    				ar[x][0] = i;
    				v.push_back(x);
    			}
    			
    			else
    			{
    				ar[x][1] = i;
    			}
    		}
    		
    		int i = 0, j = v.size() - 1;
    		
    		while(i <= j)
    		{
    			if(ar[v[i]][0] == -1)
    			{
    				i++;
    				continue;
    			}
    			
    			if(ar[v[j]][0] == -1)
    			{
    				j--;
    				continue;
    			}
    			
    			int x = ar[v[i]][0];
    			ar[v[i]][0] = ar[v[i]][1];
    			ar[v[i]][1] = -1;
    			
    			int y = ar[v[j]][0];
    			ar[v[j]][0] = ar[v[j]][1];
    			ar[v[j]][1] = -1;
    			
    			ans[x] = v[j];
    			ans[y] = v[i];
    		}
    		
    		int dis = 0;
    			
    		
    		for(int i = 0 ; i < n ; i++)
    		dis += (org[i] != ans[i]);
    				
    		cout << dis << endl;
    				
    		for(int i = 0 ; i < n ; i++)
    		cout << ans[i] << " ";
    		
    		cout << endl;
    	}
    } 
