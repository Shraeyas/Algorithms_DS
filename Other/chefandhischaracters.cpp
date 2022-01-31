#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

int main()
{
	freopen("in.in", "r", stdin);
	
	int t;
	cin >> t;
	
	while(t--)
	{
		int label_ = 0;
		
		string s;
		cin >> s;
		getchar();
		
		for(int i = 0 ; i < s.length() - 3 ; i++)
		{
			string chk = "";
			
			for(int j = i ; j < i + 4 ; j++)
			{
				chk += s[j];
			}
			
			sort(chk.begin(), chk.end());
			
			if(chk == "cefh")
			label_++;
		}
		
		if(label_ > 0)
		cout << "lovely " << label_ << endl;
		
		else
		cout << "normal" << endl;
	}
}
