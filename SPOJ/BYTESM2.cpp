#include<bits/stdc++.h>
using namespace std;
int dp[101][101];
int solve(vector<vector<int> >&matrix, int i, int j, int &row, int &col) {
	if(dp[i][j] != -1) {
		return dp[i][j];
	}
	if(i == row) {
		return dp[i][j] = 0;
	}
	int x = 0, y = 0, z = 0;
	if(j - 1 >= 0) {
		x = solve(matrix, i + 1, j - 1, row, col) + matrix[i][j - 1];
	}
	if(j + 1 < col) {
		y = solve(matrix, i + 1, j + 1, row, col) + matrix[i][j + 1];
	}
	z = solve(matrix, i + 1, j, row, col) + matrix[i][j];
	return dp[i][j] = max(x, max(y, z));
}
int main() {
	freopen("in.in", "r", stdin);
	int t;
	cin >> t;
	while(t--) {
		memset(dp, -1, 101 * 101 * sizeof(int));
		vector<vector<int> >matrix;
		int row, col;
		cin >> row >> col;
		for(int i = 0 ; i < row ; i++) {
			vector<int>v;
			for(int j = 0 ; j < col ; j++) {
				int x;
				cin >> x;
				v.push_back(x);
			}
			matrix.push_back(v);
		}
		int ans = 0;
		for(int i = 0 ; i < col ; i++) {
			ans = max(ans, solve(matrix, 1, i, row, col) + matrix[0][i]);
		}
		cout << ans << endl;
	}
}
