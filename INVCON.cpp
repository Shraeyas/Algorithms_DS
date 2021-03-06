#include <iostream>
#include <vector>

using namespace std;

int n, ans = 0;

void merge(vector <long> &, vector <long> &, vector <long> &);

void merge_sort(vector <long> &v, int size)
{
	if(size == 1)
	return;
	
	vector <long> left, right;
	int mid = size/2, l = 0;
	
	for(int i = 0 ; i < mid ; i++)
	{
		left.push_back(v[l++]);
	}
	
	for(int i = mid ; i < size ; i++)
	{
		right.push_back(v[l++]);
	}
	
	merge_sort(left, left.size());
	merge_sort(right, right.size());
	
	merge(left, right, v);
}

void merge(vector <long> &left, vector <long> &right, vector <long> &v)
{
	int i = 0, j = 0, l = 0;
	
	while(i < left.size() && j < right.size())
	{
		if(left[i] < right[j])
		{
			v[l++] = left[i++];
		}
		
		else
		{
			ans++;
			v[l++] = right[j++];
		}
	}
	
	while(i < left.size())
	{
		v[l++] = left[i++];
	}
	
	while(j < right.size())
	{
		v[l++] = right[j++];
	}
}

int main()
{
	vector <long> v;
	cin >> n;
	
	for(int i = 0 ; i < n ; i++)
	{
		int x;
		cin >> x;
		
		v.push_back(x);
	}
	
	merge_sort(v, v.size());
		
	cout << ans;
}
