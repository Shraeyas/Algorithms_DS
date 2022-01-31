#include <iostream>
#include <tr1/unordered_map>

using namespace std;

int main()
{
    freopen("11572 - Unique Snowflakes.txt", "r", stdin);
    
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;
        
        int from = 1, ans = 0, cnt = 0, ss = 0;
        tr1 :: unordered_map <int, int> hash;
                
        for(int i = 0 ; i < n ; i++)
        {
            int x;
            cin >> x;
            
            
            
            if(hash[x] != 0)
            {
                ss = max(ss, hash[x]);
                cnt = i + 1 - ss;
            }
            
            else
            {
                cnt++;    
                
            }
            ans = max(ans, cnt);
            
            hash[x] = i + 1;
        }
        
        cout << ans << endl;
    }
}