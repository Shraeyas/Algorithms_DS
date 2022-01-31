#include<bits/stdc++.h>
#include<tr1/unordered_map>
using namespace std;
bool *prime;
tr1::unordered_map<int, vector<int> >adj;
void generate_primes() {
	for(int i = 2 ; i < sqrt(10000) ; i++) {
		for(int j = i * i ; j < 10000; j+=i) {
			prime[j] = 0;
		}
	}
}
void get_one_off(int n) {
	int num;
	num = floor(n/10) * 10;
	for(int i = 0 ; i <= 9 ; i++) {
		int x = num + i;
		if(prime[x] && n != x) {
			adj[n].push_back(x);
		}
	}
	num = floor(n/100) * 100 + n % 10;
	for(int i = 0 ; i <= 9 ; i++) {
		int x = num + i * 10;
		if(prime[x] && n != x) {
			adj[n].push_back(x);
		}
	}
	num = floor(n/1000) * 1000 + n % 100;
	for(int i = 0 ; i <= 9 ; i++) {
		int x = num + i * 100;
		if(prime[x] && n != x) {
			adj[n].push_back(x);
		}
	}
	num = floor(n/10000) * 10000 + n % 1000;
	for(int i = 1 ; i <= 9 ; i++) {
		int x = num + i * 1000;
		if(prime[x] && n != x) {
			adj[n].push_back(x);
			adj[x].push_back(n);
		}
	}
}
void generate_graph() {
	for(int i = 1000 ; i < 10000 ; i++) {
		if(prime[i]) {
			get_one_off(i);
		}
	}
}
int get_shortest_path(int a, int b) {
	queue<int>q;
	q.push(a);
	bool *vis = new bool[10000];
	memset(vis, 0, 10000 * sizeof(bool));
	int *path = new int[10000];
	memset(path, 10000, 10000 * sizeof(int));
	path[a] = 0;
	while(!q.empty()) {
		int top = q.front();
		q.pop();
		vis[top] = true;
		int size = adj[top].size();
		for(int i = 0 ; i < size ; i++) {
			int node = adj[top][i];
			if(!vis[node]) {
				q.push(node);
			}
			path[node] = min(path[node], path[top] + 1);
		}
	}
	return path[b];
}
int main() {
	freopen("in.in.cpp", "r", stdin);
	prime = new bool[10000];
	memset(prime, 1, 10000 * sizeof(bool));
	generate_primes();
	generate_graph();
	int n;
	cin >> n;
	while(n--) {
		int a, b;
		cin >> a >> b;
		int ans = get_shortest_path(a, b);
		cout << ans << endl;
	}
}
