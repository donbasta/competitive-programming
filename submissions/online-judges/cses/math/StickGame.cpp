#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e6;
bool dp[N + 5];
int n, k;

void solve() {
  cin >> n >> k;
  vector<int> p(k);
  for(int i = 0; i < k; i++) {
    cin >> p[i];
  }
  for(int i = 1; i <= n; i++) {
    bool win = 0;
    for(int j = 0; j < k; j++) {
      if(i == p[j]) {win = 1; break;}
      if(i < p[j]) continue;
      if(i > p[j]) {
        if(!dp[i - p[j]]) {
          win = 1; break;
        } 
      }
    }
    dp[i] = win;
  }
  string ans(n, '\0');
  for(int i = 0; i < n; i++) {
    ans[i] = (dp[i + 1] ? 'W' : 'L');
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}