#include <iostream>
#include <tr1/unordered_map>

using namespace std;

struct node
{
	int x, y;
};

int main()
{
	//freopen("in.in", "r", stdin);
	
	int t;
	cin >> t;
	
	while(t--)
	{
		tr1 :: unordered_map <int, tr1 :: unordered_map <int, int> > adj;
		
		tr1 :: unordered_map <int, node> m;
		
		int n, q;
		cin >> n >> q;
		
		for(int i = 0 ; i < q ; i++)
		{
			int a, b, z;
			cin >> a >> b >> z;
			
			adj[a][b] = ((z == 0) ? -1 : 1);
			
			m[i].x = a;
			m[i].y = b;
		}
		
		for(int i = 0 ; i < q ; i++)
		{
			for(int j  = 0 ; j < n ; j++)
			{
				
			int pg = m[i].x, ss = m[i].y;
			
			if(m[i].x == m[i].y)
			{
				if(adj[m[i].x][m[i].y] == 1)
				{
					cout << "no" << endl;
					goto label;
				}
			}
			
			else if(adj[m[i].x][m[i].y] != 0 && adj[m[i].y][m[i].x] != 0 && adj[m[i].x][m[i].y] != adj[m[i].y][m[i].x])
			{
				cout << "no" << endl;
				goto label;
			}
			
			else if(adj[pg - 1][ss] != 0 && adj[pg - 1][ss + 1] != 0 && adj[pg][ss] != 0)
			{
				if(adj[pg - 1][ss] == adj[pg - 1][ss + 1] && adj[pg][ss] == adj[pg - 1][ss + 1])
				{
					cout << "no" << endl;
					goto label;
				}
			}
			
			
			
			}
		}
		
		cout << "yes" << endl;
		
		label:;
	}
}
