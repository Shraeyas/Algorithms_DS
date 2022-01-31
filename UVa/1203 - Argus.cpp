#include <iostream>
#include <queue>

using namespace std;

int main()
{
    freopen("1203 - Argus.txt", "r", stdin);
    
    priority_queue < pair <pair <int, int> , int > >pq;
    
    string s;
    
    while(cin >> s, s != "#")
    {
        int id, in;
        cin >> id >> in;
        
        pq.push(make_pair(make_pair(-in, -id), -in));
    }
    
    int k;
    cin >> k;
    
    while(k--)
    {
        int id = pq.top().first.second;
        int val = pq.top().first.first;
        int next = pq.top().second;
        
        cout << -id << endl;
        
        pq.pop();
        pq.push(make_pair(make_pair(val + next, id), next));
        
    }
}