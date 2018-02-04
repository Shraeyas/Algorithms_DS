#include <bits/stdc++.h>
#include <tr1/unordered_map>

using namespace std;

int main()
{
    freopen("10507 - Waking up brain.txt", "r", stdin);
    freopen("10507 - Waking up brain.out", "w", stdout);
    
    int n, m;
    
    while(cin >> n >> m)
    {
        tr1 :: unordered_map <int, vector<int> > adj;
        
        string x;
        cin >> x;
        
        bitset <26> awake;
        awake.reset();
        
        awake.set(x[0] - 'A');
        awake.set(x[1] - 'A');
        awake.set(x[2] - 'A');
        
        for(int i = 0 ; i < m ; i++)
        {
            cin >> x;
            
            adj[x[0] - 'A'].push_back(x[1] - 'A');
            adj[x[1] - 'A'].push_back(x[0] - 'A');
        }
        
        int days = 0;
        
        while(awake.count() < n)
        {
            int cur = 0;
            
            vector <int> woke;
            
            for(int i = 0 ; i < 26 ; i++)
            {
                int v = 0;
                
                if(!awake[i])
                for(int  j = 0 ; j < adj[i].size() ; j++)
                {
                    if(awake[adj[i][j]])
                        v++;
                    
                    if(v == 3)
                    {
                        woke.push_back(i);
                        cur = 1;
                    }
                }
            }
            
            for(int i = 0 ; i < woke.size() ; i++)
                awake.set(woke[i]);
            
            if(cur == 0)
            {
                cout << "THIS BRAIN NEVER WAKES UP" << endl;
                goto end;    
            }
            
            days++;
            
        }
        
        cout << "WAKE UP IN, " << days << ", YEARS" << endl;
        
        end:;
        
        getchar();
    }
}