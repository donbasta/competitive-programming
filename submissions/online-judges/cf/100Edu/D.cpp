#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<bool> mau(2 * n + 5);
  for (int i = 0; i < n; i++) {
    int b;
    cin >> b;
    mau[b] = 1;
  }
  vector<int> A, B;
  for (int i = 1; i <= 2 * n; i++) {
    if (mau[i]) B.emplace_back(i);
    else A.emplace_back(i);
  }
  int j = 0;
  int mx = 0;
  for (int i = 0; i < n; i++) {
    while (j < n && B[i] > A[j]) {
      j++;
    }
    if (j == n) {
      break;
    }
    mx++;
  }
  int mn = 0;
  for (int i = 1; i <= 2 * n; i++) {
    if (!mau[i]) break;
    mn++;
  } 
  cerr << mx << ' ' << mn << '\n';
  int cnt = mx - mn + 1;
  cout << cnt << '\n';
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