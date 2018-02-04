#include <iostream>
#include <map>
#include <cstring>
#include <stdio.h>
#include <tr1/unordered_map>

using namespace std;

tr1 :: unordered_map <char, int> pg;

char* uniqueChar(char *str)
{
    // Write your code here
 	char *st = new char[strlen(str)];
 	st[0] = '\0';

	for(int i = 0 ; i < strlen(str) ; i++)
    {
      if(pg[str[i]] == 0)
      {
        int len = strlen(st);
        st[len] = str[i];
        st[len + 1] = '\0';
      }
      
      pg[str[i]]++;
    }

  return st;  
}

int main()
{
	char str[50] = "aaabbccd";
	cout << uniqueChar(str);
}
