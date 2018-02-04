#include <iostream>
#include <vector>

using namespace std;

struct val
{
    int x, y;
};

int abs(int x)
{
    return x < 0 ? x * -1 : x;
}
    
int main()
{
//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);
    
    int m;
    
    while(cin >> m)
    {
        vector <val> v1, v2;
        
        for(int i = 0 ; i < m ; i++)
        {
            string s;
            cin >> s;
            
            for(int j = 0 ; j < m ; j++)
            {
                if(s[j] == '1')
                {
                    val x;
                    
                    x.x = i;
                    x.y = j;
                    
                    v1.push_back(x);
                }
                
                else if(s[j] == '3')
                {
                    val x;
                    
                    x.x = i;
                    x.y = j;
                    
                    v2.push_back(x);
                }
            }
        }
        
        int ans = 999999, a1 = 0;
        
        for(int i = 0 ; i < v1.size() ; i++)
        {
            ans = 999999;
            
            for(int j = 0 ; j < v2.size() ; j++)
            {
                ans = min(ans, abs(v1[i].x - v2[j].x) + abs(v1[i].y - v2[j].y));
            }
            
            a1 = max(ans, a1);
        }
                          
        cout << a1 << endl;
    }
}