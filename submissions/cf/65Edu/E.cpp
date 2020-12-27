#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n, x;
  cin >> n >> x;

  vector<bool> ada(x+1);
  vector<int> la(x+1), fi(x+1);
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    if (!ada[t]) {
      fi[t] = i;
    }
    la[t] = i;
    ada[t] = 1;
  }

  vector<int> ve;
  ve.push_back(0);
  for (int i = 1; i <= x; i++) {
    if (ada[i])
      ve.push_back(i);
  }
  ve.push_back(x+1);
  int sz = (int)ve.size();

  int le = ve[1], ri = ve[sz-2];
  for (int i = 2; i < sz-1; i++) {
    if (la[ve[i-1]] < fi[ve[i]]) {
      le = ve[i+1] - 1;
    } else {
      break;
    }
  }
  for (int i = sz-2; i >= 2; i--) {
    if (la[ve[i-1]] < fi[ve[i]]) {
      ri = ve[i-2] + 1;
    } else {
      break;
    }
  }
  ll ans;
  cerr << le << ' ' << ri << '\n';
  if (le > ri) {
    ans = 1LL * x * (x + 1) / 2;
  } else {
    ans = 1LL * le * (x-ri+1);
    ans += 2;
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  // cin >> TC;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}