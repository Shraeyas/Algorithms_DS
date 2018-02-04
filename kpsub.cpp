#include <iostream>
#include <string>

using namespace std;

void solve(int, string);
string a[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void printKeypad(int num)
{
  
  solve(num, "");
}

void solve(int num, string s)
{
  if(!num)
  {
    cout << s << endl;
  }
  
  int p = num % 10;
  
  for(int i = 0 ; i < a[p].size() ; i++)
  {
	solve(num/10, a[p][i] + s);
  }
}

int main()
{
	printKeypad(23);
}
