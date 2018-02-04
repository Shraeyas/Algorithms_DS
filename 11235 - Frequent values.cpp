#include <iostream>
#include <tr1/unordered_map>

using namespace std;

int main()
{
    freopen("11235 - Frequent values.txt", "r", stdin);
    
    int n;
    
    while(cin >> n, n)
    {
        tr1 :: unordered_map <int, int> ar, hash, f, r;
        
        int m;
        cin >> m;
        
        for(int i = 0 ; i < n ; i++)
        {
            int x;
            cin >> x;
            
            ar[i] = x;
            
            if(ar[i] == ar[i-1])
            {
                hash[i] = hash[i-1] + 1;
            }
            
            else
            {
                hash[i] = 1;
            }
            
            f[i] = max(hash[i], f[i-1]);
        }
        
        for(int i = n - 1 ; i >= 0 ; i--)
        {
            if(ar[i] == ar[i+1])
            {
                hash[i] = hash[i+1] + 1;
            }
            
            else
            {
                hash[i] = 1;
            }
        }
        
        
        for(int i = n - 1 ; i >= 0 ; i--)
        {
            b[i] = max(hash[i], b[i-1])
        }
    }
}