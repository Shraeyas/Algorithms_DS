#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <tr1/unordered_map>

using namespace std;

struct s
{
  int x, y, f;
};

struct coor
{
  int x, y;
};

tr1 :: unordered_map <int, tr1 :: unordered_map <int, tr1 :: unordered_map <int, float> > > dp;

float dist(int x, int y, int x1, int y1)
{
  return sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
}

float solve(int i, s *ar, int n, float ans, int xp, int yp)
{
  if(i == n)
  {
    return ans;
  }
  
  coor ob;
  ob.x = xp;
  ob.y = yp;
 
  if(dp[xp][yp][i])
    return dp[xp][yp][i];
  
  return dp[xp][yp][i] = max(solve(i + 1, ar, n, ans + ar[i].f - dist(xp, yp, ar[i].x, ar[i].y), ar[i].x, ar[i].y), solve(i + 1, ar, n, ans, xp, yp));
}

int main()
{
  int n;
  cin >> n;
  
  s ar[n];
  
  for(int i = 0 ; i < n ; i++)
  {
    cin >> ar[i].x >> ar[i].y >> ar[i].f;
  }
  
  printf("%.6f", solve(1, ar, n, ar[0].f, ar[0].x, ar[0].y));
}
