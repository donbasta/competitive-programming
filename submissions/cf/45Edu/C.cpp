#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 3e5;
int L[N + 5];
int R[N + 5];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int tmp;
    bool ok;

    tmp = 0, ok = 1;
    for (auto c : s) {
      if (c == '(') tmp++;
      else tmp--;
      if (tmp < 0) ok = 0;
    }
    if (ok) {
      L[tmp]++;
    }

    reverse(s.begin(), s.end());
    tmp = 0, ok = 1;
    for (auto c : s) {
      if (c == ')') tmp++;
      else tmp--;
      if (tmp < 0) ok = 0;
    }
    if (ok) {
      R[tmp]++;
    }
  }

  ll ans = 0;
  for(int i = 0; i <= N; i++) {
    ans += 1LL * L[i] * R[i];
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