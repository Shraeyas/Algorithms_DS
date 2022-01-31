#include<iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	
	int t;
	cin>>t;
	
	while(t--)
	{
		string s;
		cin>>s;
		
		bool palindrome = 1;
		int len = s.length();
		
		for(long i=0;i<len/2;i++)
		{
			if(s[i]!=s[len - i -1])
			{	
				palindrome = 0;
				break;
			}
		}
		
		//If Given Number is Palindrome
		if(palindrome)
		{
			if(len % 2 == 0)
			{
				long l = len/2 - 1;
				long u = len/2;
				
				while(l>=0)
				{
							
					if(s[l] != '9')
					{
						s[l]++;
						s[u]++;
					
						break;
					}
				
					else
					{
						s[l] = '0';
						s[u] = '0';
					}
				
					l--;
					u++;
				}
				
				if(l<0)
				{
					cout<<1;
					
					for(long i=0;i<len-1;i++)
					cout<<0;
					
					cout<<1<<endl;
				}
			
				else
				{
					cout<<s<<endl;
				}
			}
			
			else
			{
				if(s[len/2]!='9')
				{
					s[len/2]++;
					cout<<s<<endl;
				}
				
				else
				{
					s[len/2]='0';
					
					int l = len/2 - 1;
					int u = len/2 + 1;
					
					while(l>=0)
					{
						if(s[l]!='9')
						{
							s[l]++;
							s[u]++;
							
							break;
						}
						
						else
						{
							s[l]='0';
							s[u]='0';
						}
						
						l--;
						u++;
					}
					
					if(l<0)
					{
						cout<<1;
						for(long i=0;i<len-1;i++)
						cout<<0;
						
						cout<<1<<endl;
					}
					
					else
					{
						cout<<s<<endl;
					}
				}
			}
		}
		
		
		//If Given Number is Not Palindrome
		else
		{
			long l,u,p=0;
			
			if(len % 2 == 0)
			{
				l = len/2 -1;
				u = len/2;
			}
			
			else
			{
				l = len/2 - 1;
				u = len/2 + 1; 	
			}
			
			while(l>=0)
			{
				if(s[l] - s[u] > 0)
				{
					p = 1;
					break;
				}
				
				if(s[l] - s[u] < 0)
				{
					p = 2;
					break;
				}
				
				l--;
				u++;
			}
			
			if(p == 1)
			{
				for(long  i=0;i<len/2;i++)
				{
					s[len - i - 1] = s[i];
				}
				
				cout<<s<<endl;
			}
			
			else if(p == 2 && len % 2 ==1 && s[len/2]!='9')
			{
				s[len/2]++;
				
				for(long i=0;i<len/2;i++)
				{
					s[len - i - 1]=s[i];
				}
				
				cout<<s<<endl;
			}
			
			else
			{
			
				if(len % 2 == 0)
				{
					l = len/2 -1;
					u = len/2;
				}
			
				else
				{
					l = len/2 - 1;
					u = len/2 + 1; 	
				}
				
				if(len % 2 ==1)
				{
					s[len/2] = '0';
				}
				
				while(l>=0)
				{
					if(s[l] <'9')
					{
						s[l]++;
						s[u] = s[l];
						
						break;
					}
					
					else
					{
						s[l] = '0';
						s[u] = '0';
					}
					
					l--;
					u++;
				}
				
				if(l>=0)
				{
					while(l>=0)
					{
						s[u] = s[l];
					
						l--;
						u++;
					}
				}
				
				cout<<s<<endl;
			}
		}
	}
}
