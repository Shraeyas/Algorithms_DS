#include <iostream>

using namespace std;

struct ans
{
	int x;
	int y;
	int gcd;
};

int gcd(int a, int b)
{
	if(b == 0)
	return a;
	
	return gcd(b, a%b);
}

ans extendedeuclid(int a, int b)
{
	if(b == 0)		
	{
		ans base;
		
		base.x = 1;
		base.y = 0;
		base.gcd = a;
		
		return base;
	}
	
	ans next;
	next = extendedeuclid(b, a % b);
	
	ans cur;
	cur.x = next.y;
	cur.y = (next.x - (a/b) * next.y);
	cur.gcd = next.gcd;
	
	return cur;
}

int main()
{	
	int a = 5, b = 12, k = 2;
	
	ans final_ans = extendedeuclid(a, b);
	
	cout << final_ans.x;
}
