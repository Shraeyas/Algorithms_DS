#include<bits/stdc++.h>
#include<tr1/unordered_map>
using namespace std;
tr1::unordered_map<int, vector<int> >adj, adj_dir;
tr1::unordered_map<int, bool>vis;
bool check_cycle(int start) {
//	cout << start << endl;
	vis[start] = true;
	int size = adj_dir[start].size();
	bool ans = true;
	for(int i = 0 ; i < size ; i++) {
		int node = adj_dir[start][i];
		if(!vis[node]) {
			ans = ans & check_cycle(node);
		}
		else {
			return false;
		}
	}
	return ans;
}
void check_comp(int start) {
	vis[start] = true;
	int size = adj[start].size();
	for(int i = 0 ; i < size ; i++) {
		int node = adj[start][i];
		if(!vis[node]) {
			check_comp(node);
		}
	}
}
int main() {
	freopen("in.in.cpp", "r", stdin);
	int n, m;
	cin >> n >> m;
	for(int i = 0 ; i < m ; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		adj_dir[a].push_back(b);
	}
	bool ans_cycle = true;
	int components = 0;
	for(int i = 1 ; i <= n ; i++) {
		if(!vis[i]) {
			
			ans_cycle = ans_cycle & check_cycle(i);
//			cout << "*************" << endl;
			vis.clear();
		}
		
	}
	vis.clear();
	for(int i = 1 ; i <= n ; i++) {
		if(!vis[i]) {
			components++;
			check_comp(i);
		}
	}
//	cout << ans_cycle << " " << components << endl;
	if(ans_cycle && components == 1) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}
