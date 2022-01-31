#include <iostream>
#include <vector>

using namespace std;

int main()
{
  long n, k, ans = 0;
  cin >> n >> k;
  
  vector <long> v, pfk, npfk, cur;
  
  for(long i = 0 ; i < n ; i++)
  {
    long x;
    cin >> x;
    
    v.push_back(x);
  }
  
  long x = k;
  
  for(long i = 2 ; i <= k ; i++)
  {
    if(!x)
      break;
    
    if(x % i == 0)
    {
      pfk.push_back(i);
      npfk.push_back(0);
      cur.push_back(0);
      
      while(x % i == 0)
      {
        npfk[npfk.size() - 1]++;
        x /= i;
      }
    }
  }
  long i = 0, j = 0;
  
  while(j < n)
  {
    long x = v[j];
    
    for(long l = 0 ; l < pfk.size() ; l++)
    {
      if(x % pfk[l] == 0)
      {
        while(x % pfk[l] == 0)
        {
          cur[l]++;
          x /= pfk[l];
        }
      }
    }
    
    if(cur.size() < pfk.size())
      continue;
    
    int ch = 1;
    
    for(int l = 0 ; l < cur.size() ; l++)
    {
      if(cur[l] < npfk[l])
      {
        ch = 0;
        break;
      }
    }
    
    if(ch)
    {
      ans += n - j;
    
      x = v[i];
      
      for(long l = 0 ; l < pfk.size() ; l++)
      {
        if(x % pfk[l] == 0)
        {
          while(x % pfk[l])
          {
            cur[l]--;
            x /= pfk[l];
          }
        }
        
        i++;
      }      
    }
    
    j++;
  }
    
  cout << ans;
}
