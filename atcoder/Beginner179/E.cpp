#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int M = 1e5;

ll n, m, x;
int ar[M + 5], pos[M + 5];
ll aw[M + 5], pre[M + 5];

void solve() {
  cin >> n >> x >> m;
  ll cur = x;
  int now = 0;
  while(pos[cur] == 0) {
    pos[cur] = ++now;
    ar[now] = cur;
    cur = (cur * cur) % m;
  }
  int st = pos[cur];
  for(int i = st; i <= now; i++) {
    pre[i - st + 1] = pre[i - st] + ar[i];
  }
  for(int i = 1; i < st; i++) {
    aw[i] = aw[i - 1] + ar[i];
  }
  if(n < st) {
    cout << aw[n] << '\n';
    return;
  }
  ll ans = aw[st - 1];
  n -= (st - 1);
  ll mul = (n / (now - st + 1)), sisa = n % (now - st + 1);
  ans += (mul * pre[now - st + 1]) + pre[sisa];
  cout << ans << '\n';
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