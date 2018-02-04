#include<iostream>
#include<map>

using namespace std;

int main()
{
	
	//while(t--)
	
		string s;
		cin>>s;
		
		long len = s.length(),x;
		
		if(len == 1 && s[0] == '0')
		return 0;
		
		else
		{
		
		//long dp[len]={0};
		
		map<long,long>dp;
		
		dp[0]=1;
		
		if(len>=2)
		{
			
			x=(s[0]-'0')*10 + s[1]-'0';
			
			if(x>=10 && x<=26)
			dp[1]++;
			
			if(s[1]!= '0')
			dp[1]++;
		}
		
		for(long i=2;i<len;i++)
		{
			//dp[i]+=dp[i-1];
			
			x = (s[i-1]-'0')*10 + s[i]-'0';
			
			if(x<=26 && x>=10)
			{
				dp[i]+=dp[i-2];	
			}
			
			if(s[i]!='0')
			{
				dp[i]+=dp[i-1];	
			}	
		}
		
		cout<<dp[len-1]<<endl;
		
		main();
	}
}
