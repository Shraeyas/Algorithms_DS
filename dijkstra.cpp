#include<iostream>
#define max 10000

using namespace std;

struct node
{
	int value;
	int name;
};

node q[max];
int size = 0;

void per_up(int);

void insert(int val, int name)
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
	per_down(0);
	return s;
}

int main()
{
	freopen("C:\\Users\\Shraeyas\\Documents\\pg\\pr_ag\\prag_dijk.txt", "r", stdin);
	
	ios::sync_with_stdio(0);
	
	int t;
	cin>>t;
	
	while(t--)
	{
		
	}
}
