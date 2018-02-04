#include<iostream>
#include<map>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	
	int t;
	cin>>t;
	
	while(t--)
	{
		map<int,map<int,int> >mat;
		
		int n,m,ma = 0;
		cin>>n>>m;
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>mat[i][j];
				
				mat[i][j]+= max(max(mat[i-1][j-1],mat[i-1][j+1]),mat[i-1][j]);		
				ma = max(ma,mat[i][j]);
			}
		}
		
		cout<<ma<<endl;
	}
}
