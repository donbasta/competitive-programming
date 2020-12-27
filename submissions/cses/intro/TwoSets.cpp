#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll n;
  cin >> n;
  vector<bool> yes(n + 1, false);
  ll tot = n * (n + 1) / 2;
  if(tot & 1) {
    cout << "NO" << '\n';
    return;
  }
  cout << "YES" << '\n';
  ll cur = 0, now = n;
  while(cur < tot / 2) {
    if(cur + now <= tot / 2) {
      yes[now] = true;
      cur += now;
      now--;
    } else {
      yes[tot / 2 - cur] = true;
      break;
    }
  }
  vector<int> a, b;
  for(int i = 1; i <= n; i++) {
    if(yes[i]) a.push_back(i);
    else b.push_back(i); 
  }
  cout << (int)a.size() << '\n';
  for(auto& e : a) {cout << e << ' ';}
  cout << '\n';
  cout << (int)b.size() << '\n';
  for(auto& e : b) {cout << e << ' ';}
  cout << '\n';
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