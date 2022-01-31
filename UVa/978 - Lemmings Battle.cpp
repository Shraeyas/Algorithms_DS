#include <iostream>
#include <queue>
#include <queue>

using namespace std;

int main()
{
    freopen("978 - Lemmings Battle.txt", "r", stdin);
    
    int t;
    cin >> t;
    
    while(t--)
    {
        priority_queue <int, vector<int> > b_pq, w_pq;
        
        int n, b, w;
        
        cin >> n >> w >> b;
        
        for(int i = 0 ; i < w ; i++)
        {
            int x;
            cin >> x;
            
            w_pq.push(x);
        }
        
        for(int i = 0 ; i < b ; i++)
        {
            int x;
            cin >> x;
            
            b_pq.push(x);
        }
        
        while(!w_pq.empty() && !b_pq.empty())
        {
            int sz = n;
            vector <int> bl, wh;
            
            while(sz-- && !w_pq.empty() && !b_pq.empty())
            {
                int y = w_pq.top(), x = b_pq.top();
                
                w_pq.pop();
                b_pq.pop();
                
                bl.push_back(x);
                wh.push_back(y);
            }
            
            for(int i = 0 ; i < bl.size() ; i++)
            {
                if(bl[i] > wh[i])
                {
                    b_pq.push(bl[i] - wh[i]);
                }
                
                else if(bl[i] < wh[i])
                {
                    w_pq.push(wh[i] - bl[i]);
                }
            }
        }
        
        if(w_pq.empty() && b_pq.empty())
        {
            cout << "green and blue died" << endl;
        }
        
        else if(w_pq.empty())
        {
            cout << "blue wins" << endl;
            
            while(!b_pq.empty())
            {
                cout << b_pq.top() <<endl;
                b_pq.pop();
            }
            
            
        }
        
        else
        {
            cout << "green wins" << endl;
            
            while(!w_pq.empty())
            {
                cout << w_pq.top() <<endl;
                w_pq.pop();
            }
            
            
        }
        
        if(t)
            cout << endl;
    }
}