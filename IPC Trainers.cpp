            #include<iostream>
            #include<vector>
            #include<queue>
            #include<algorithm>
            #include<cstring>
            
            #define max 100005
             
            using namespace std;
            
            struct node
            {
            	long long day, time, sad, index;		
    		}v[100005];
    		
    		struct compare_sort
    		{
    		    public :
    			bool operator()(const node &x, const node &y)
    			{
    			    return x.day < y.day;
    			}
    		}c_s;
    		
    		struct c_pq
    		{
    		  bool operator()(const node& x, const node& y)
    		  {
    		      return x.sad < y.sad;
    		  }
    		};
    		
            
            int main()
            {
            	//freopen("IPC Trainers.txt", "r", stdin);
            	
            	
            	int test;
            	cin>>test;
            	
            	while(test--)
            	{
            		long long n, ds, maxi = 0;
            		priority_queue<node, vector<node>, c_pq>pq;
            		
    				memset(v, 0, sizeof(v));
            	
            		cin >> n >> ds;
            		
            		for(long long i = 0 ; i < n ; i++)
            		{
            			long long d, t, s;
            			cin >> d >> t >> s;
            			
            			v[i].day = d;
            			v[i].time = t;
            			v[i].sad = s;
            			v[i].index = i;
            			
            			maxi += t*s;
            		}
            		
            		sort(v, v + n, c_s);
            		
            		for(long long i=0;i<n;i++)
            		v[i].index = i;
            		
            		long long ind = 0;
            		
            		for(long long i = 1 ; i <= ds ; i++)
            		{
            			while(ind < n && v[ind].day == i)
    					{
    						pq.push(v[ind++]);
    					}
    					
    					if(!pq.empty())
    					{
    						v[pq.top().index].time--;
    						maxi -= v[pq.top().index].sad;
    						
    						if(v[pq.top().index].time == 0)
    						{
    							pq.pop();
    						}
    					}
    				}
    				
            		
            		cout<<maxi<<endl;
            	}
            }   
