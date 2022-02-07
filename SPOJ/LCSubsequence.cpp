#include<bits/stdc++.h>
#include<tr1/unordered_map>
using namespace std;
const int max_y = 25000;
int lcs(string &a, string &b, int m, int n, int dp[][max_y]) {
	if(dp[m][n] != -1) {
		return dp[m][n];
	}
	if(m == a.length() || n == b.length()) {
		return dp[m][n] = 0;
	}
	if(a[m] == b[n]) {
		return dp[m][n] = 1 + lcs(a, b, m + 1, n + 1, dp);
	}
	else {
		int x, y;
		x = lcs(a, b, m, n + 1, dp);
		y = lcs(a, b, m + 1, n, dp);
		return dp[m][n] = max(x, y);
	}
}
int main() {
	string a, b;
	cin >> a >> b;
	int m = a.length(), n = b.length();
	int dp[m + 1][max_y];
	memset(dp, -1, (m + 1) * max_y * sizeof(int));
	cout << lcs(a, b, 0, 0, dp) << endl;
}
