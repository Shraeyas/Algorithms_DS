#include<iostream>
#include<vector>

using namespace std;

long iv = 0;

long abs(long x)
{
	//return x<0 ? x*(-1) : x;
	return x;
}

long merge(vector<long>left, vector<long>right, vector<long>&a)
{
	long i = 0, j = 0, inv = 0 ;
	a.clear();
	
	while(i < left.size() && j < right.size())
	{
		if(left[i] <= right[j])
		{
			a.push_back(left[i++]);
		}
		
		else
		{
			
			inv+= left.size() - i;
			//cout<<right[j]<<" "<<inv<<" "<<a.size()<<endl<<endl;
			a.push_back(right[j++]);
		}
	}
	
	while(i < left.size())
	{
		a.push_back(left [i++]);
	}
	
	while(j < right.size())
	{
		a.push_back(right [j++]);
	}
	//cout<<inv<<endl;
	
	return inv;
}

void mergesort(vector<long>&v)
{
	if(v.size() == 1)
	return;
	
	vector<long>left,right;
	
	for(long i=0;i<v.size()/2;i++)
	left.push_back(v[i]);
	
	for(long i=v.size()/2;i<v.size();i++)
	right.push_back(v[i]);
	
	mergesort(left);
	mergesort(right);
	iv+= merge(left, right, v);
}

int main()
{
	ios::sync_with_stdio(0);
	
	int t;
	cin>>t;
	
	while(t--)
	{
		vector<long>v;
		iv = 0;
		
		long n;
		cin>>n;
		
		for(long i=0;i<n;i++)
		{
			long x;
			cin>>x;
			
			v.push_back(x);
		}
		
		mergesort(v);
		
		/*for(long i=0;i<v.size();i++)
		{
			cout<<v[i]<<" ";
		}*/
		//cout<<endl
		
		cout<<iv<<endl;
	}
}
