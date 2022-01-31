#include <iostream>
#include <set>

using namespace std;

int main()
{
    freopen("11136 - Hoax or what.txt", "r", stdin);
    
    long n;
    
    while(cin >> n, n)
    {
        multiset <long> bills;
        long ans = 0;
        
        for(long i = 0 ; i < n ; i++)
        {
            long k;
            
            cin >> k;
            
            for(long j = 0 ; j < k ; j++)
            {
                long x;
                
                cin >> x;
                bills.insert(x);
            }
            
            auto it = bills.end();
            it = bills.end();
            it--;
            ans += *it;
            bills.erase(it);
            
            it = bills.begin();
            ans -= *it;
            
            bills.erase(it);
        }
        
        cout << ans << endl;
    }
}