#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n, t;
  cin >> n >> t;
  vector<int> ve, ar(n), p(n);
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
    if (ar[i] * 2 < t) p[i] = 0;
    else if (ar[i] * 2 > t) p[i] = 1;
    else ve.push_back(i);
  }
  int sz = (int)ve.size();
  for (int i = 0; i < sz / 2; i++) {
    p[ve[i]] = 1;
  }
  for (int i = 0; i < n; i++) {
    cout << p[i] << ' ';
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