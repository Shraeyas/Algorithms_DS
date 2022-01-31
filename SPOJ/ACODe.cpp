#include <bits/stdc++.h>
using namespace std;
int *dp;
int solve(string &s, int i) {
	if(i == s.length()) {
		return 1;
	}
	int len = s.length() - i;
	if(dp[len]) {
		return dp[len];
	}
	int num = s[i] - '0';
	if(num > 0) {
		dp[len] = solve(s, i + 1);
	}
	else {
		return 0;
	}
	if(len >= 2) {
		int num = (s[i] - '0') * 10 + s[i + 1] - '0';
		if(num <= 26 && num > 0) {
			dp[len] += solve(s, i + 2);
		}
	}

	return dp[len];
}
int main() {
	string n;
	while(cin >> n, n != "0") {
		dp = new int [5001];
		memset(dp, 0, 5001 * sizeof(int));
		cout << solve(n, 0) << endl;
	}
}
