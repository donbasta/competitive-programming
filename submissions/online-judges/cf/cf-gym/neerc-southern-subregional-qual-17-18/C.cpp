#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll n, k;

void solve() {
  cin >> n >> k;
  k;
  if(n * (n - 1) / 2 < k) {
    cout << "Impossible" << '\n';
    return;
  }
  ll sum = 0;
  ll cur = -1;
  int cnt = 0, cnt2 = 0;
  vector<int> ve;
  while(sum < k) {
    if(sum + (cur + 1) <= k) {
      sum += (++cur);
      cnt++;
      ve.push_back(1);
    } else {
      ll temp = cur;
      cur = min(cur - 1, k - 1 - sum);
      ll neg = temp - cur;
      for(int i = 0; i < neg; i++) {
        ve.push_back(-1);
        cnt2++;
      }
    }
    if(cnt >= n) break;
  }
  if(sum != k) {
    cout << "Impossible" << '\n';
    return;
  }
  string ans;
  for(int i = 0; i < (int)ve.size(); i++) {
    if(ve[i] == 1) ans += '(';
    else ans += ')';
  }
  for(int i = 0; i < cnt - cnt2; i++) {
    ans += ')';
  }
  while((int)ans.length() < 2 * n) {
    ans += '(';
    ans += ')';
  }
  cout << ans << '\n';
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