#include <iostream>
#include <vector>
#include <tr1/unordered_map>

using namespace std;

vector<int> longestSubsequence(int *arr, int n)
{
	tr1 :: unordered_map <int, int> h;
	int mi = 100009, ma = -1;
	
	for(int i = 0 ; i < n ; i++)
	{
		h[arr[i]]++;
		
		mi = min(mi, arr[i]);
		ma = max(ma, arr[i]);
	}
	
	for
}

int main()
{
	vector <int> v;
	
	int n = 10;
	
	int arr[] = {10, 4, 9, 2, 6, 21, 22, 43, 12, 11};
	
	v = longestSubsequence(arr, n);
	
	for(int i = 0 ; i < v.size() ; i++)
	{
		cout << v[i] << " ";
	}
}
