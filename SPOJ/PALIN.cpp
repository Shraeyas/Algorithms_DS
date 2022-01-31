#include<iostream>
using namespace std;
void solve(string &s) {
	bool check = false;
	int length = s.length();
	int left, right;
	if(length % 2 == 1) {
		int mid = length/2;
		left = mid - 1;
		right = mid + 1;
	}
	else {
		left = length/2 - 1;
		right = length/2;
	}
	while(left != -1) {
		if(s[left] == '9') {
			s[left--] = '0';
			s[right++] = '0';
			check = true;
		}
		else {
			if(s[left] > s[right]) {
				s[right++] = s[left--];
				check = true;
			}
			else if(s[left] < s[right]){
				if(check == true) {
					s[right++] = s[left--];
				}
				else {
					s[left] += 1;
					s[right++] = s[left--];
					check = true;
				}
			}
			else {
				left--;
				right++;
			}
		}
	}
}
void sanitize(string &s) {
	while(s.length() != 0) {
		if(s[0] == '0') {
			s = s.substr(1, s.length());
		}
		else {
			return;
		}
	}
}
int main() {
	freopen("in.in.cpp", "r", stdin);
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		sanitize(s);
		if(s.length() == 0) {
			s = "0";
		}
		int length = s.length();
		if(length % 2 == 1) {
			int mid = length/2;
			if(s[mid] != '9') {
				s[mid] = s[mid] + 1;
				int left = mid - 1, right = mid + 1;
				while(left != -1) {
					s[right] = s[left];
					right++;
					left--;
				}
			}
			else {
				s[mid] = '0';
				solve(s);
			}
		}
		else {
			solve(s);
		}
		string ans = s;
		sanitize(s);
		if(s.length() == 0) {
			ans = '1' + ans + '1';
		}
		cout << ans << endl;
	}
}
