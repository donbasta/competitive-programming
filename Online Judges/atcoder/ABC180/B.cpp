#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;

  ll manh = 0, eu = 0, cheb = -1;
  for(int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    manh += abs(x);
    eu += (x * x);
    cheb = max(cheb, abs(x));
  }
  ld eus = sqrtl((ld)eu);
  cout << manh << '\n';
  cout << fixed << setprecision(15) << eus << '\n';
  cout << cheb << '\n';
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