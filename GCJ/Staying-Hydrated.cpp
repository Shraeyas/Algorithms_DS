#include <bits/stdc++.h>

using namespace std;

int main ()
{
     freopen ("in.in", "r", stdin);

     int t, cs = 1;
     cin >> t;

     while (t--)
     {
          int k;
          cin >> k;
          vector <int> x, y;

          for (int i = 0; i < k; i++)
          {
               int x1, y1, x2, y2;
               cin >> x1 >> y1 >> x2 >> y2;

               x.push_back (x1);
               x.push_back (x2);

               y.push_back (y1);
               y.push_back (y2);
          }


          sort (x.begin (), x.end ());
          sort (y.begin (), y.end ());

          int mid;
          if (x.size () % 2 == 0)
          {
               mid = x.size () / 2 - 1;
          }

          else
          {
               mid = x.size () / 2;
          }

          cout << "Case #" << cs++ << ": " << x [mid] << " " << y [mid] << endl;
     }
}
