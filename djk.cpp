#include<iostream>
#include<cstring>
#include<vector>

#define max 3000

using namespace std;

struct node
{
	int value;
	int name;
};

node q[max];
int size = 0;
int dis[max] = {0};
vector<int>adj[max][2];

void per_up(int);

void insert(int name, int val)
{
	q[size].value = val;
	q[size++].name = name;
	
	per_up(size-1);
	
	return;
}

int par(int i)
{
	return (i-1)/2;
}

int lc(int i)
{
	return 2*i+1;
}

int rc(int i)
{
	return 2*i+2;
}

void per_up(int i)
{
	while(q[i].value < q[par(i)].value)
	{
		node s = q[i];
		q[i] = q[par(i)];
		q[par(i)] = s;
		
		i = par(i);
	}
}

void per_down(int i)
{
	while((q[i].value > q[lc(i)].value) || (q[i].value > q[rc(i)].value))		
	{
		if(q[lc(i)].value < q[rc(i)].value)
		{
			node s = q[i];
			q[i] = q[lc(i)];
			q[lc(i)] = q[i];
			
			i = lc(i);
		}
		
		else
		{
			node s = q[i];
			q[i] = q[rc(i)];
			q[rc(i)] = q[i];
			
			i = rc(i);
		}
	}
}

node extractmin()
{
	node s = q[0];
	q[0] = q[size-1];
	per_down(0);
	size--;
	
	return s;
}

void dijkstra(int s)
{
	insert(s, 0);
	int vis[max] = {0};
	
	while(size != 0)
	{
		node ss = extractmin();
		for(int i = 0 ; i < adj[ss.name][0].size() ; i++)
		{
			if(!vis[adj[ss.name][0][i]])
			{
				vis[adj[ss.name][0][i]] = 1;
				
				insert(adj[ss.name][0][i], dis[adj[ss.name][0][i]]);
				
				dis[adj[ss.name][0][i]] = dis[ss.name] + adj[ss.name][1][i];
			}
		}
	}
}


int main()
{
	//freopen("C:\\Users\\Shraeyas\\Documents\\pg\\pr_ag\\prag_dijk.txt", "r", stdin);
	
	ios::sync_with_stdio(0);
	
	int t;
	cin>>t;
	
	while(t--)
	{
		int m, n;
		cin>>n>>m;
		
		for(int i=0;i<m;i++)
		{
			int x, y, z;
			cin>>x>>y>>z;
			
			adj[x][0].push_back(y);
			adj[x][1].push_back(z);
			
			adj[y][0].push_back(x);
			adj[y][1].push_back(z);
		}
		
		int s;
		cin>>s;
		
		dijkstra(s);
		
		for(int i=0;i<n;i++)
		if(i!=s-1)
		cout<<dis[i]<<" ";
		
		cout<<endl;
		
		
		//refresh();
		memset(dis, 0, sizeof(dis));
		for(int i=0;i<m;i++)
		{
			adj[i][0].clear();
			adj[i][1].clear();
		}
	}
}
