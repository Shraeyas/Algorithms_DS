#include<iostream>

using namespace std;

bool kmp(int *temp, string str, string pat)
{
	int i=0, j=0;
	
	while(i<str.length() && j<pat.length())
	{
		if(str[i] == pat[j])
		{
			i++;
			j++;
		}
		
		else
		{
			if(j!=0)
			{
				j = temp[j-1];
			}
			
			else
			{
				i++;
			}
		}		
	}
	
	if(j == pat.length())
	return true;
	
	return 0;
	
}

int main()
{
	string str, pat;
	cin>>str>>pat;
	
	int temp[pat.length()];
	temp[0] = 0;
	
	int i=1, j=0;
	
	while(i<pat.length())
	{
		if(pat[j] != pat[i])
		{
			if(j!=0)
			{
				j = temp[j-1];
			}
			
			else
			{
				temp[i] = 0;
				i++;
			}
		}
		
		else
		{
			temp[i] = j + 1;
			i++;
			j++;
		}
		
		
	}
	
	//for(int i=0;i<pat.length();i++)
	//cout<<temp[i]<<" ";
	
	cout<<kmp(temp, str, pat);
}
