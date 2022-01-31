#include<bits/stdc++.h>
#include<tr1/unordered_map>
using namespace std;
tr1::unordered_map<int, int>color;
tr1::unordered_map<int, vector<int> >adj;
bool bipartite(int start, int prev_color) {
	int curr_color = ((prev_color == 1) ? -1 : 1); 
//	cout << curr_color << endl;
	color[start] = curr_color;
	int size = adj[start].size();
	bool ans = true;
	for(int i = 0 ; i < size ; i++) {
		if(color[adj[start][i]] == curr_color) {
			return false;
		}
		if(color[adj[start][i]] == 0) {
			ans = ans & bipartite(adj[start][i], curr_color);
		}
	}
	return ans;
}
int main() {
	freopen("in.in.cpp", "r", stdin);
	int t;
	cin >> t;
	for(int test = 0 ; test < t ; test++) {
		int n, q;
		cin >> n >> q;
		adj.clear();
		color.clear();
		for(int i = 0 ; i < q ; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		bool ans = true;
		for(int i = 1 ; i <= n ; i++) {
			if(color[i] == 0) {
				ans = ans & bipartite(i, 1);
			}
		}
		cout << "Scenario #" << test + 1 << ":" << endl;
		if(ans == false) {
			cout << "Suspicious bugs found!" << endl;
		}
		else {
			cout << "No suspicious bugs found!" << endl;
		}
	}
}
