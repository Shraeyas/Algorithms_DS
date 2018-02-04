    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <bits/stdc++.h>
     
    using namespace std;
     
    int main(){
      ios_base::sync_with_stdio(false);
     
     freopen("in.in", "r", stdin);
     
      int N;
      cin >> N;
     
      const int MAX_BIT = 10;
      const int MAX_N = 1 << MAX_BIT;
      const int FULL_MASK = MAX_N - 1;
     
      vector<int> A(N);
      vector<int> dp(MAX_N);
     
      for (int i = 0; i < N; i++){
        string s;
        cin >> s;
     
        int mask = 0;
        for(int j = 0 ; j < s.length() ; j++)
          mask |= 1 << (s[j] - '0');
     
        A[i] = mask;
        dp[mask]++;
      }
     
      auto is_set = [](int nr, int b){
        return (nr >> b) & 1;
      };
     
      for (int j = 0; j < MAX_BIT; j++){
        for (int i = 0; i < MAX_N; i++){
          if (!is_set(i, j))
            dp[i] += dp[i | (1 << j)];
        }
      }
     
      int c = (int)count(A.begin(), A.end(), FULL_MASK);
      long long answer = 0;
     
      for (int x: A)
        answer += dp[FULL_MASK ^ x];
     
      answer -= c;
      answer /= 2;
      answer += c;
     
      cout << answer << endl;
     
      return 0;
    } 
