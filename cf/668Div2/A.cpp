#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, k;
string s;

void solve() {
  cin >> n >> k;
  cin >> s;
  vector<int> ar(k);
  int one = 0, zero = 0;
  for(int i = 0; i < k; i++) {
    bool fix = 0;
    int cur = -1;
    for(int j = i; j < n; j += k) {
      if(s[j] == '?') continue;
      int now = s[j] - '0';
      if(!fix) { cur = now; fix = 1; }
      else if(fix) {
        if(now != cur) {
          cout << "NO" << '\n';
          return;
        }
      }
    }
    if(cur == 0) zero++;
    else if(cur == 1) one++;
  }
  if(zero <= k / 2 && one <= k / 2) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  cin >> TC;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}