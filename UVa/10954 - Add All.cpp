#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    freopen("10954 - Add All.tx", "r", stdin);
    
    int n;
    
    while(cin >> n, n)
    {
        priority_queue <int, vector <int>, greater <int> > pq;
        
        for(int i = 0 ; i < n ; i++)
        {
            int x;
            cin >> x;
            
            pq.push(x);
        }
        
        int ans = 0, cost = 0;
        
        while(n != 1)
        {
            ans = pq.top();
            pq.pop();
            
            
            ans += pq.top();
            pq.pop();
            
            pq.push(ans);
            
            cost += ans;
            
            n--;
        }
        
        cout << cost << endl;
    }
}