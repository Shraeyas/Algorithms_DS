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
		return ans{1, 0, a};
	}
	
	ans next = extendedeuclid(b, a % b);
	
	ans cur;
	cur.x = next.y;
	cur.y = next.x - floor(a/b) * next.y;
	cur.gcd = next.gcd;
	
	return cur;
}

int main()
{
	// ax + by = c
	//c is multiple of gcd (a, b)
	
	
	int c = 7;								// extended euclid (a, b)
	ans p = extendedeuclid(2 * 7, 3 * 7);   // extended euclid((c / gcd(a, b)) * a, (c / gcd(a, b)) * b)
	
	cout << p.x << " " << p.y;
}
