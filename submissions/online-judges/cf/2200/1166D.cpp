#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll a, b, m;

void solve() {
  cin >> a >> b >> m;
  bool ok = false;
  int last = -1;
  for(int i = 0; ; i++) {
    ll pw = (1LL << i);
    ll m1 = b / pw, m2 = ceil(b / pw);
    if(m1 <= a) break;
    if(m1 >= a + 1 && m2 <= a + m) {
      last = i;
      ok = true;
      break;
    }
  }
  if(!ok) {
    cout << -1 << '\n';
    return;
  }
  vector<ll> ans;
  for(int i = 0; i <= last; i++) {
    ll pw = (1LL << i);
    ll m = b / pw;
    ans.push_back(m);
  }
  ans.push_back(a);
  int sz = (int)ans.size();
  for(int i = sz - 1; i > 0; i--) {
    ll temp = 0;
    for(int j = 0; j < i; j++)
      temp += ans[j];
    if(ans[i] - temp < 1 || ans[i] - temp > m) {
      
    }
  }

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