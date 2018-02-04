#include <iostream>
#include <cmath>

using namespace std;

struct ans
{
	long x, y, gcd;
};

ans extendedeuclid(long a, long b)
{
	if(b == 0)
	{
		ans ret;
		ret.gcd = a;
		ret.x = 1;
		ret.y = 0;
		
		return ret;
	}
	
	ans prev = extendedeuclid(b, a % b);
	
	ans cur;
	cur.x = prev.y;
	cur.y = prev.x - floor(a/b) * prev.y;
	cur.gcd = prev.gcd;
	
	return cur;
}

int main()
{
  long t;
  //cin >> t;
  
  //while(t--)
  {
	long a, b, c;
	//cin >> b;
    
    //if(c % gcd(a, b) != 0)
      //cout << 0;
    
    //else
    {
      ans modinv = extendedeuclid(7, 12);

	  long m = 12;
      long b_modinv = modinv.x;
      cout << (b_modinv % m + m) % m <<" " << modinv.y<<endl;
      
      long y_min = ((c%a) * b_modinv);
      long n = ((c / b) - y_min)/a;

      //cout << n + 1 << endl;
    }
  }
}
