#include<iostream>
#include<queue>
#include<map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		long m;
		
		cin>>n>>m;
		int a[2][2*m],x,y;
		long l=0;
		
		for(long i=0;i<m;i++)
		{
			cin>>x>>y;
			a[0][l]=x;
			a[1][l++]=y;
			a[0][l]=y;
			a[1][l++]=x;
			
		}
		
		int s;
		cin>>s;
		int pra=s;
		queue<int>q;
		q.push(s);
		
		map<int,long>dist;
		long val=0;
		int ch=0;
		while(!q.empty())
		{
			val+=6;
			s=q.front();
			q.pop();
			for(int i=0;i<l;i++)
			{
				if(a[0][i]==s&&dist[a[1][i]-1]==0)
				{
					dist[a[1][i]-1]=dist[a[0][i]-1]+6;
					q.push(a[1][i]);
					ch=1;
					//cout<<a[1][i]<<" ";
				}
				
			}
			//if(ch==1)
			
		}
		for(int i=0;i<n;i++)
		{
			if(dist[i]==0)
			dist[i]=-1;
			
			if(i!=pra-1)
			cout<<dist[i]<<" ";
		}
		cout<<endl;
	}
}