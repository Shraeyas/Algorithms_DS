#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    int n, m;
    
    while(cin >> n, n)
    {
        cin >> m;
        
        vector <float> v1, v2, fin;
        
        for(int i = 0 ; i < n ; i++)
        {
            int x;
            cin >> x;
            
            v1.push_back(x);
        }
        
        for(int i = 0 ; i < m ; i++)
        {
            int x;
            cin >> x;
            
            v2.push_back(x);
        }
        
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                fin.push_back(v2[i]/v1[j]);
            }
        }
        
        sort(fin.begin(), fin.end());
        float ans = 0;
        
        for(int i = 1 ; i < fin.size() ; i++)
        {
            ans = max(ans, fin[i] / fin[i - 1]);
        }
        
        cout << fixed << setprecision(2) << ans << endl;
    }
}