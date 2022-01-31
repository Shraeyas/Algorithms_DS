#include <iostream>
#include <vector>
#include <tr1/unordered_map>

using namespace std;

int main()
{
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector <int> v;
    
    for(int i = 1 ; i <= 20 ; i++)
    {
        v.push_back(i);
        v.push_back(i * 2);
        v.push_back(i * 3);
    }
    
    v.push_back(0);
    v.push_back(50);
    
    int n;
    
    
        tr1 :: unordered_map <int, tr1 :: unordered_map <int, tr1 :: unordered_map <int, int> > > per, com;
        tr1 :: unordered_map <int, int> pera, coma;
    
        //int pera[201], coma[200];
        //bool per[190][190][101], com[101][101][101];
        
        //int cm = 0, pr = 0;
        
        for(int i = 0 ; i < 62 ; i++)
        {
            for(int j = 0 ; j < 62 ; j++)
            {
                for(int k = 0 ; k < 62 ; k++)
                {
                    if(!per[v[i]][v[j]][v[k]])
                    {
                        per[v[i]][v[j]][v[k]] = 1;
                        
                        pera[v[i] + v[j] + v[k]]++;
                    }
                    
                    if(!com[v[i]][v[j]][v[k]])
                    {
                        com[v[i]][v[j]][v[k]] = 1;
                        com[v[i]][v[k]][v[j]] = 1;
                        com[v[k]][v[j]][v[i]] = 1;
                        com[v[j]][v[i]][v[k]] = 1;
                        com[v[k]][v[i]][v[j]] = 1;
                        com[v[j]][v[k]][v[i]] = 1;
                        
                        coma[v[i] + v[j] + v[k]]++;
                    }
                }
            }
        }
    
    
    while(cin >> n, n > 0)
    {
        
        if(!pera[n] || !coma[n])
        {
            cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS." << endl;
        }
        
        else
        {
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS " << coma[n] << "." << endl;
            cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << pera[n] << "." << endl;
        }
        
        cout << "**********************************************************************" << endl;
    }
    
    cout << "END OF OUTPUT" << endl;
}