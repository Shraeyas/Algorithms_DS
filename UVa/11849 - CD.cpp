#include <iostream>
#include <tr1/unordered_map>

using namespace std;

int main()
{
    freopen("11849 - CD.txt", "r", stdin);
    
    int n, m;
    
    while(cin >> n >> m, n || m)
    {
        int ans = 0;
        tr1 :: unordered_map <int, int> hash;
        
        for(int i = 0 ; i < n ; i++)
        {
            int x;
            
            cin >> x;
            hash[x]++;
        }
        
        for(int i = 0 ; i <m ; i++)
        {
            int x;
            
            cin >> x;
            
            if(hash[x])
            {
                ans++;
            }
        }
        
        cout << ans << endl;
    }
}