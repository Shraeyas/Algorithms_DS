#include<iostream>
#include <cstring>

using namespace std;

int a[11][1000001], prime[1000001];

void precompute()
{
  memset(prime, 0, 1000001 * sizeof(int));
  memset(a, 0, 1000001*11 * sizeof(int));
  
  for(long i = 2 ; i <= 1000000 ; i++)
  {
    if(prime[i] == 0)
      
    for(long j = i ; j <= 1000000 ; j += i)
    {
      prime[j]++;
    }
  }
  
  for(int i = 0 ; i <= 10 ; i++)
  {
    for(long j = 1 ; j <= 1000000 ; j++)
    {
      if(prime[j] == i)
      {
        a[i][j] = 1 + a[i][j - 1];
      }
      
      else
      {
        a[i][j] = a[i][j - 1];
      }
    }
  }
}

int main()
{
  precompute();
  
  int t;
  cin >> t;
  
  while(t--)
  {
    int x, y, n;
    cin >> x >> y >> n;
    
    cout << a[n][y] - a[n][x] << endl;
  }
}
