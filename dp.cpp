#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];

int solve(int i, int *a, int n, int k)
{
  if(k == 0)
    return 2;
  
  if(i == n)
    return 1;
  
  if(dp[i][k])
    return dp[i][k];
  
  if(a[i] <= k)
  {
    return dp[i][k] = max(solve(i + 1, a, n, k - a[i]), solve(i + 1, a, n, k));
  }
  
  else
  {
    return dp[i][k] = solve(i + 1, a, n, k);
  }
}

int main()
{
  memset(dp, 0, sizeof(int) * 1001 * 1001);
  int n, *a, k;
  
  cin >> n;
  
  a = new int [n];
  for(int i = 0 ; i < n ; i++)
  {
    cin >> a[i];
  }
  
  cin >> k;
  
  cout << (solve(0, a, n, k) == 2 ? "Yes" : "NO");
  
  return 0;
}

