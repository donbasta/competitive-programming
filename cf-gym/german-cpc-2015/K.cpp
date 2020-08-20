#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll p, pp;

bool isPrime(ll x) {
  if(x == 1) return false;
  for(ll i = 2; i * i <= x; i++) {
    if(x % i == 0) return false;
  }
  return true;
}

void solve() {
  string s;
  cin >> s;
  p = stoll(s);
  reverse(s.begin(), s.end());
  string ss;
  for(auto& c : s) {
    if (c == '3' || c == '4' || c == '7') {
      cout << "no" << '\n';
      return;
    }
    if(c == '0' || c == '2' || c == '5' || c == '8' || c == '1') {
      ss.push_back(c);
    }
    if(c == '6') {
      ss.push_back('9');
    }
    if(c == '9') {
      ss.push_back('6');
    }
  }
  pp = stoll(ss);
  bool ok = true;
  cerr << p << ' ' << pp << '\n';
  ok &= (isPrime(p));
  ok &= (isPrime(pp));
  cout << (ok ? "yes" : "no") << '\n';
  return;
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