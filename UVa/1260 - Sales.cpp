#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        vector <int> v;
        
        int n;
        cin >> n;
        
        for(int i = 0 ; i < n ; i++)
        {
            int x;
            cin >> x;
            
            v.push_back(x);
        }
        
        int ans = 0;
        
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < i ; j++)
            {
                if(v[i] >= v[j])
                    ans++;
            }
        }
        
        cout << ans << endl;
    }
}