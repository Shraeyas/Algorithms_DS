#include <iostream>
#include <vector>

using namespace std;

struct node
{
	int one;
	char flag;
};

vector<node>segtree(4096009);
string r;


char find_action(char ch)
{
	if(ch == 'S')
	return 'C';
	
	if(ch == 'C')
	return 'S';
	
	if(ch == 'F')
	return 'N';
	
	return 'F';
}

void propagate(int pos, int a, int b)
{
	if(segtree[pos].flag == 'N')
	return;
	
	if(segtree[pos].flag == 'S')
	{
		segtree[pos].one = b - a + 1;
	}
	
	if(segtree[pos].flag == 'C')
	{
		segtree[pos].one = 0;
	}
	
	if(segtree[pos].flag == 'F')
	{
		segtree[pos].one = b - a + 1 - segtree[pos].one;
	}
	
	if(a != b)
	{
		if(segtree[pos].flag == 'S')
		{
			segtree[2*pos + 1].flag = 'S';
			segtree[2*pos + 2].flag = 'S';
		}
		
		else if(segtree[pos].flag == 'C')
		{
			segtree[2*pos + 1].flag = 'C';
			segtree[2*pos + 2].flag = 'C';
		}
		
		else if(segtree[pos].flag == 'F')
		{
			segtree[2*pos+1].flag = find_action(segtree[2*pos+1].flag);
			segtree[2*pos+2].flag = find_action(segtree[2*pos+2].flag);			 
		}
	}
	
	segtree[pos].flag = 'N';
}

void ini_tree(int pos, int lo, int hi)
{
	segtree[pos].flag = 'N';
	if(lo == hi)
	{
		segtree[pos].one = (r[lo] - '0');
		
		return;
	}
	
	int mid = lo + (hi - lo)/2;
	
	ini_tree(2 * pos + 1, lo, mid);
	ini_tree(2 * pos + 2, mid+1, hi);
	
	segtree[pos].one = segtree[2*pos+1].one + segtree[2*pos+2].one;
	
}

void set(int qlo, int qhi, int lo, int hi, int pos)
{
	propagate(pos, lo, hi);
	
	if(qlo>hi || qhi<lo)
	return;
	
	
	if(lo == hi)
	{
		segtree[pos].one = 1;
		return;
	}
	
	if(qlo<=lo && qhi>=hi)
	{
		segtree[pos].one = hi - lo + 1;
		
		segtree[2*pos+1].flag = 'S';
		segtree[2*pos+2].flag = 'S';
		
		return;
	}
	
	int mid = lo + (hi - lo)/2;
	
	set(qlo, qhi, lo, mid, 2*pos+1);
	set(qlo, qhi, mid+1, hi, 2*pos+2);
	
	segtree[pos].one = segtree[2*pos+1].one + segtree[2*pos+2].one;
}


void unset(int qlo, int qhi, int lo, int hi, int pos)
{
	propagate(pos, lo, hi);
	
	if(qlo>hi || qhi<lo)
	return;
	
	
	if(lo == hi)
	{
		segtree[pos].one = 0;
		return;
	}
	
	if(qlo<=lo && qhi>=hi)
	{
		segtree[pos].one = 0;
		
		segtree[2*pos+1].flag = 'C';
		segtree[2*pos+2].flag = 'C';
		
		return;
	}
	
	int mid = lo + (hi - lo)/2;
	
	unset(qlo, qhi, lo, mid, 2*pos+1);
	unset(qlo, qhi, mid+1, hi, 2*pos+2);
	
	segtree[pos].one = segtree[2*pos+1].one + segtree[2*pos+2].one;
}


void flip(int qlo, int qhi, int lo, int hi, int pos)
{
	propagate(pos, lo, hi);
	
	if(qlo>hi || qhi<lo)
	return;
	
	if(lo == hi)
	{
		segtree[pos].one ^= 1;
		return;
	}
	
	if(qlo<=lo && qhi>=hi)
	{
		segtree[pos].one = hi - lo + 1 - segtree[pos].one;
		
		segtree[2*pos+1].flag = find_action(segtree[2*pos+1].flag);
		segtree[2*pos+2].flag = find_action(segtree[2*pos+2].flag);
		
		return;
	}
	
	int mid = lo + (hi - lo)/2;
	
	flip(qlo, qhi, lo, mid, 2*pos+1);
	flip(qlo, qhi, mid+1, hi, 2*pos+2);
	
	segtree[pos].one = segtree[2*pos+1].one + segtree[2*pos+2].one;
}

int query(int qlo, int qhi, int lo, int hi, int pos)
{
	if(hi<qlo || lo>qhi)
	return 0;
	
	propagate(pos, lo, hi);
	
	if(qlo<=lo && qhi>=hi)
	return segtree[pos].one;
	
	int mid = lo + (hi - lo)/2;
	
	return query(qlo, qhi, lo, mid, 2*pos+1) + query(qlo, qhi, mid+1, hi, 2*pos+2);
}


int main()
{
	freopen("UVa 11402 - Ahoy Pirates.txt", "r", stdin);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t, cs = 1;
	cin>>t;
	
	while(t--)
	{
		cout<<"Case "<<cs++<<":"<<endl;
		
		segtree.clear();
		r = "";
		
		int m;
		cin>>m;
		
		for(int i=0;i<m;i++)
		{
			string s;
			int p;
			
			cin>>p;
			cin>>s;
			
			for(int j=0;j<p;j++)
			r += s;
		}
		
		int q;
		cin>>q;
		
		int n = r.length();
		
		ini_tree(0, 0, n-1);
		
		/*	
		string chk;
		for(int i=0;i<4*n;i++)
		chk += segtree[i].one+'0';
		cout<<chk<<endl<<r<<endl;
		*/
	
		//cout<<r<<endl;
	
		int qu = 1;
		while(q--)
		{
			
			char ch;
			int a, b;
			
			cin >> ch >> a >> b;
			
			if(ch == 'F')
			{	
			/*
				string chk;
				for(int i=0;i<4*n;i++)
				cout<<segtree[i].one<<" ";
				cout<<endl<<r<<endl;
				*/
				set(a, b, 0, n-1, 0);				//Update
				
				/*
				chk = "";
				for(int i=0;i<4*n;i++)
				cout<<segtree[i].one<<" ";
				cout<<endl<<r<<endl;*/
			}
			
			else if(ch == 'E')
			{
				unset(a, b, 0, n-1, 0);			    //Update
			}
			
			else if(ch == 'I')
			{
				
				
				/*string chk = "";
				for(int i=0;i<4*n;i++)
				cout<<segtree[i].one<<" ";
				cout<<endl<<r<<endl;
				*/
				
				flip(a, b, 0, n-1, 0);				//Update	
				
				/*
				chk = "";
				for(int i=0;i<4*n;i++)
				cout<<segtree[i].one<<" ";
				cout<<endl<<r<<endl;*/
			}
			
			else
			{
						
				cout<<"Q"<<qu++<<": ";
				cout << query(a, b, 0, n-1, 0) << endl;
			}
			
		}
	}
}
