#include<bits/stdc++.h>
using namespace std;
int dp[6101][6101];
int solve(string &s, int i, int j) {
	if(dp[i][j] != -1) {
		return dp[i][j];
	}
	if(i >= j ) {
		return dp[i][j] = 0;
	}
	int x = INT_MAX, y = INT_MAX, z = INT_MAX;
	if(s[i] == s[j]) {
		x = solve(s, i + 1, j - 1);
	}
	y = solve(s, i + 1, j) + 1;
	z = solve(s, i, j - 1) + 1;
	return dp[i][j] = min(x, min(y, z));
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		memset(dp, -1, 6101 * 6101 * sizeof(int));
		string s;
		cin >> s;
		cout << solve(s, 0, s.length() - 1) << endl;
	}
}
