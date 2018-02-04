#include<iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	
	long long n;
	cin>>n;
	
	if(n %10 != 0)
	{
		cout<<"1"<<endl;
		
		cout<<n%10;
	}
	
	else
	{
		cout<<"2";
	}
	
}
