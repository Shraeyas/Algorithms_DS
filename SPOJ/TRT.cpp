#include<bits/stdc++.h>
#include<tr1/unordered_map>
using namespace std;
int dp[2001][2001];
int solve(vector<int>&v, int i, int j, int day) {
	if(dp[i][j] != -1) {
		return dp[i][j];
	}
	if((i == v.size() && j == -1) || i > j) {
		return dp[i][j] = 0;
	}
	int x = 0, y = 0;
	if(i < v.size()) {
		x = solve(v, i + 1, j, day + 1) + day * v[i];
	}
	if(j >= 0) {
		y = solve(v, i, j - 1, day + 1) + day * v[j];
	}
	return dp[i][j] = max(x, y);
}
int main() {
	freopen("in.in", "r", stdin);
	memset(dp, -1, 2001 * 2001 * sizeof(int));
	int n;
	cin >> n;
	vector<int>v(n);
	for(int i = 0 ; i < n ; i++) {
		cin >> v[i];
	}
	cout << solve(v, 0, n - 1, 1);
}
