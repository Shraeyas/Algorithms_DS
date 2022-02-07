#include<bits/stdc++.h>
#include<tr1/unordered_map>
using namespace std;
typedef unsigned int uint;
const uint num = 250001;
uint m, n_;
const uint max_count = 250001;
int lcs(string &a, string &b, int m, int n, int count, uint dp[][n_][max_count]) {
	if(dp[m][n][count] != -1) {
		return dp[m][n][count];
	}
	if(m == a.length() || n == b.length()) {
		return dp[m][n][count] = count;
	}
	int x = 0, y, z;
	if(a[m] == b[n]) {
		x = lcs(a, b, m + 1, n + 1, count + 1, dp);
	}
	y = lcs(a, b, m, n + 1, 0, dp);
	z = lcs(a, b, m + 1, n, 0, dp);
	return dp[m][n][count] = max(max(count, x), max(y, z));
}
int main() {
	freopen("in.in", "r", stdin);
	string a, b;
	cin >> a >> b;
	m = a.length() + 1;
	n_ = b.length() + 1;
	uint dp[m][n_][max_count];
	memset(dp, -1, m * n_ * max_count * sizeof(uint));
	cout << lcs(a, b, 0, 0, 0, dp) << endl;
}
