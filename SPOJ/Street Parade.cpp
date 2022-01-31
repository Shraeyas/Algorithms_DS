#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	
	long n,xx = 1;
	cin>>n;
	
	if(n == 0)
	return 0;
	
	stack<long>stkp,stks;
	stkp.push(0);
	
	for(long i=0;i<n;i++)
	{
		long x;
		cin>>x;
		
		if(x-stkp.top() == 1)
		{
			stkp.push(x);
		}
		
		else if(x-stkp.top() != 1)
		{
			if(stks.empty())
			{
				stks.push(x);
			}
			
			else
			{
				if(stks.top()>x)
				{
					stks.push(x);
				}
				
				else
				{
					xx = 0;
				}
			}
		}
		
		while(!stks.empty())
		{
			if(stks.top() - stkp.top() == 1)
			{
				stkp.push(stks.top());
				stks.pop();
			}
			
			else
			break;
		}
	}
	
	if(xx == 0)
	cout<<"no"<<endl;
	
	else
	{
		cout<<"yes"<<endl;
	}
	
	main();
}
