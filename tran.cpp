#include<iostream>
#include<stack>

using namespace std;

int main()
{
	//freopen("C:\\Users\\Shraeyas\\Documents\\pg\\pr_ag\\prag_tran.txt", "r", stdin);
	
	ios::sync_with_stdio(0);
	
	int t;
	cin>>t;
	
	while(t--)
	{
		string s, p_g="";
		cin>>s;
		
		stack<char>stk;
		
		for(int i=0;i<s.length();i++)
		{
			if(s[i] == '+' || s[i] == '-'|| s[i] == '/'|| s[i] == '*' || s[i] == '^')
			stk.push(s[i]);
			
			else if(s[i] == ')')
			{
				p_g+=stk.top();
				stk.pop();
			}
			
			else if(s[i] == '(')
			{
				
			}
			
			else
			{
				p_g+=s[i];
			}
		}
		
		cout<<p_g<<endl;
	}
}
