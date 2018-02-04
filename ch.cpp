#include <iostream>
#include <tr1/unordered_map>

using namespace std;

tr1 :: unordered_map <string, bool> chk;
string str;

void solve(int i, string cur, string ans)
{
	if(i == str.length())
	{
		if(cur == "")
		cout << ans << endl;
		return;
	}
	
	if(chk[cur + str[i]])
	{
		solve(i + 1, "", ans + (ans == "" ? "" : " ") + cur + str[i]);
	}
	
	solve(i + 1, cur + str[i], ans);
}

int main()
{
	freopen("in.in", "r", stdin);
	
	int n;
	cin >> n;
	
	for(int i = 0 ; i < n ; i++)
	{
		string s;
		cin >> s;
		
		chk[s] = 1;
	}
	
	cin >> str;
	
	solve(0, "", "");
}
