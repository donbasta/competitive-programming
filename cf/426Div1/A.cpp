#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll cubeRoot(ll x) {
  ll lo = 1, hi = 1e6, ans = -1;
  while(lo <= hi) {
    ll mid = (lo + hi) >> 1;
    // cerr << lo << ' ' << hi << ' ' << mid << ":(";
    ll cubeMid = mid * mid * mid;
    if(cubeMid > x) {
      hi = mid - 1;
    } else if(cubeMid < x) {
      lo = mid + 1;
    } else if(cubeMid == x) {
      ans = mid;
      break;
    }
  }
  return ans;
}

void solve() {
  ll a, b;
  cin >> a >> b;
  ll mul = a * b;
  ll cubeRootMul = cubeRoot(mul);
  // cerr << cubeRootMul << ":D\n";
  if(cubeRootMul == -1) {
    cout << "No" << '\n';
  } else {
    bool ok = true;
    ok &= (a % cubeRootMul == 0);
    ok &= (b % cubeRootMul == 0);
    // cout << "Yes" << '\n';
    cout << (ok ? "Yes" : "No") << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tc = 1;
  cin >> tc;
  while(tc--) {
    solve();
  }
  
  return 0;
}