#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  ll sum = 0;
  ll mn = 1e18;
  ll mx = -1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    mx = max(mx, a[i]);
  }
  ll bat = mx * (n-1);
  ll need = sum % (n-1);
  if (need != 0) {
    need = (n-1) - need;
  }
  ll sumNew = sum + need;
  ll ans = max(sumNew, bat);
  ll ret = ans - sum;
  cout << ret << '\n';
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