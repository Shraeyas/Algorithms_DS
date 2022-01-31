#include <iostream>
#include <cstring>
#include <vector>

#define mod 1000000007

using namespace std;

long long a = 0;
long long *ans = new long long [750001];

long long pow(long long x, long long y)
{
  if(y < 0)
  return 0;
  
  long long num = 1;
  
  while(y)
  {
    if(y & 1)
      num = (num * x) % mod;
    
    x = (x * x) % mod;
    y >>= 1;
  }
  
  return num;
}

long long solve(long long cur, long long p)
{  
  long long ch = 0;
  
  if(dp[cur])
  return dp[cur];
  
  for(long long j = cur * 2 ; j <= 750000 ; j += cur)
  {
    if(ans[j])
    {
      ch = 1;
      return solve(j, p + 1);
    }
  }
  
  if(!ch)
    return dp[cur] = pow(2, p - 1);
}

int main()
{
  long long t;
  cin >> t;
  
  while(t--)
  {
    a = 0;
    vector <long long> v;        
    memset(ans, 0, 750001 * sizeof(long long));
    //memset(ans, 0, 750001 * sizeof(long long));
    
    long long n, p = 0;
    cin >> n;
    
    for(long long i = 0 ; i < n ; i++)
    {
      long long x;
      cin >> x;
      
      v.push_back(x);
      ans[x]++;
    }
    
    for(long long i = 0 ; i < n ; i++)
      a += solve(v[i], 0);
   
    cout << (a + n) % mod << endl;
  }
}
