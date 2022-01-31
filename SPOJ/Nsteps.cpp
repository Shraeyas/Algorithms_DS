#include<iostream>

using namespace std;

int main()
{	
	ios::sync_with_stdio(0);
	
	int t;
	cin>>t;
	
	while(t--)
	{
		int x,y;
		cin>>x>>y;
		
		if(x==y)
		{
			if(x%2 == 0)
			{
				cout<<x+x<<endl;
			}	
			
			else
			{
				cout<<x+x-1<<endl;
			}
		}
		
		else if(x-y == 2)
		{
			if(x%2 == 0)
			{
				cout<<x+y<<endl;
			}	
			
			else
			{
				cout<<x+y-1<<endl;
			}
		}
		
		else
		{
			cout<<"No Number\n";
		}
	}
}
