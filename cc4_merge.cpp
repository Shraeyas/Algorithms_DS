    #include <iostream>
    #include <vector>
    #include <tr1/unordered_map>
    #include <algorithm>
     
    using namespace std;
     
    void merge(vector <int> &, vector <int> , int, vector <int> , int);
     
    void mergesort(vector <int> &a, int size)
    {
    	if(size == 1)
    	return;
    	
    	int sl = size/2, l = 0;
    	
    	vector <int> left;
    	vector <int> right;
    	
    	for(int i = 0 ; i < sl ; i++)
    	{
    		left.push_back(a[i]);
    	}
    	
    	int j = 0;
    	for(int i = sl ; i < size ; i++)
    	{
    		right.push_back(a[i]);
    	}
    	
    	mergesort(left, left.size());
    	mergesort(right, right.size());
    	
    	merge(a, left, left.size(), right, right.size());
    }
     
    void merge(vector <int> &a, vector <int> left, int sl, vector <int> right, int sr)
    {
    	int l = 0, i = 0, j = 0;
    	
    	while(i < sl && j < sr)
    	{
    		if(left[i] != right[j])
    		{
    			left[i] = left[i] + right[j];
    			right[j] = left[i] - right[j];
    			left[i] = left[i] - right[j];
    			
    			i++, j++;
    		}
    		
    		else
    		{
    			if(i != sl - 1)
    			{
    				int temp = left[i];
    				left[i] = left[i + 1];
    				left[i + 1] = temp;
				}
				
				else if(j != sr - 1)
				{
    				int temp = right[j];
    				right[j] = right[j + 1];
    				right[j + 1] = temp;
				}
				
				else if(i == sl - 1)
				{
					if(sl != 1)
					{
	    				int temp = left[i];
	    				left[i] = left[i - 1];
	    				left[i - 1] = temp;
	    				
	    				i++;
					}
				}
				
				else if(j == sr - 1)
				{
					if(sr != 1)
					{
	    				int temp = right[j];
	    				right[j] = right[j - 1];
	    				right[j - 1] = temp;
	    				
	    				j++;
					}
				}
			}
    	}
    	
    	i = 0;
    	while(i < sl)
    	{
    		a[l++] = left[i++];
    	}
    	
    	j = 0;
    	while(j < sr)
    	{
    		a[l++] = right[j++];
    	}
    }
     
    int main()
    {
    	freopen("in.in", "r", stdin);
    	
    	int t;
    	cin >> t;
    	
    	while(t--)
    	{
    		vector <int> v, a, fin;
    		
    		int n;
    		cin >> n;
    		
    		for(int i = 0 ; i < n ; i++)
    		{
    			int x;
    			cin >> x;
    			
    			a.push_back(x);
    			v.push_back(x);
    		}
    		
    		//mergesort(a, n);
    		
    		int dis = 0, ans = 0;
    		
    		do
    		{
    			dis = 0;
    			for(int i = 0 ; i < n ; i++)
    			{
    				if(a[i] != v[i])
    				dis++;
				}
				
				if(dis > ans)
				{
					ans = dis;
					
				}
				
				if(dis == n)
				{
							
		    		cout << ans << endl;
		    		
		    		for(int i = 0 ; i < n ; i++)
		    		{
		    			cout << v[i] << " ";	
		    		}
		    		
					break;
				}
				
			}while (next_permutation (v.begin(), v.end()));
    		
    		/*for(int i = 0 ; i < n ; i++)
    		{
    			dis += (v[i] != a[i]);
    		}*/
    		
    		
    		cout << endl;
    	}
    } 
