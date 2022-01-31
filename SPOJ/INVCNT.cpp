#include<bits/stdc++.h>
using namespace std;
long ans = 0;
void merge(vector<long>&v, vector<long>left_array, vector<long>right_array) {
	long l_index = 0, l_size = left_array.size(), r_index = 0, r_size = right_array.size(), index = 0;
	while(l_index != l_size && r_index != r_size) {
		if(left_array[l_index] > right_array[r_index]) {
			v[index] = right_array[r_index];
			ans += l_size - l_index;
			r_index++;
			index++;
		}
		else {
			v[index++] = left_array[l_index++];
		}
	}
	while(l_index != l_size) {
		v[index++] = left_array[l_index++];
//		ans++;
	}
	while(r_index != r_size) {
		v[index++] = right_array[r_index++];
	}
}
void divide(vector<long>&v) {
	long size = v.size();
	if(size == 1) {
		return;
	}
	long mid = size/2;
	vector<long>left_array, right_array;
	for(long i = 0 ; i <= mid - 1 ; i++) {
		left_array.push_back(v[i]);
	}
	for(long i = mid ; i < size ; i++) {
		right_array.push_back(v[i]);
	}
	divide(left_array);
	divide(right_array);
	merge(v, left_array, right_array);
}
void solve(vector<long>&v) {
	divide(v);
}
int main() {
	freopen("in.in.cpp", "r", stdin);
	long t;
	cin >> t;
	while(t--) {
		long n;
		cin >> n;
		vector<long>v(n);
		for(long i = 0 ; i < n ; i++) {
			cin >> v[i];
		}
		ans = 0;
		solve(v);
		cout << ans << endl;
	}
}
