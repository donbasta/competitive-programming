#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll n;
  cin >> n;
  vector<ll> ve;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ve.push_back(i);
      if(i * i != n)
        ve.push_back(n/i);
    }
  }
  sort(ve.begin(),ve.end());
  for(auto& e: ve) {
    cout << e << '\n';
  }
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