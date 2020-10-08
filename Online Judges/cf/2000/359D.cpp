#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e6;
const int MXN = 3e5;
const int INF = 1e9;

int pr[N + 5];
int cnt[N + 5];
int ar[MXN + 5];
int l[MXN + 5], r[MXN + 5];
vector<int> ve[N + 5];

void rec(int curIdx, int curDiv, const vector<pair<int, int>>& primes, vector<int>& res) {
  if(curIdx == (int)primes.size()) {
    res.push_back(curDiv);
    return;
  }
  for(int i = 0; i <= primes[curIdx].first; i++) {
    rec(curIdx + 1, curDiv, primes, res);
    curDiv *= primes[curIdx].second;
  }
}
 
vector<int> generate_divisor(int x) {
  vector<pair<int, int>> pri;
  vector<int> res;
  int temp = x;
  if(x == 1)
    return vector<int>(1, 1);
  while(temp > 1) {
    int cur = pr[temp];
    int cnt = 0;
    while(temp % cur == 0) {
      cnt++;
      temp /= cur;
    }
    pri.emplace_back(cnt, cur);
  }
  rec(0, 1, pri, res);
  return res;
}

void sieve() {
  for(int i = 2; i <= N; i++) {
    if(pr[i]) continue;
    for(int j = i; j <= N; j += i) {
      pr[j] = i;
    }
  }
}

void solve() {
  sieve();
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
    ve[ar[i]] = generate_divisor(ar[i]);
  }
  for(int i = 1; i <= n; i++) {
    int cur = INF;
    for(auto j : ve[ar[i]]) {
      if(ar[i - 1] % j == 0) { cnt[j]++; }
      else { cnt[j] = 1; }
      cur = min(cur, cnt[j]);
    }
    l[i] = cur;
  }
  fill(cnt, cnt + N + 1, 0);
  for(int i = n; i >= 1; i--) {
    int cur = INF;
    for(auto j : ve[ar[i]]) {
      if(ar[i + 1] % j == 0) { cnt[j]++; }
      else { cnt[j] = 1; }
      cur = min(cur, cnt[j]);
    }
    r[i] = cur;
  }
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    ans = max(ans, l[i] + r[i] - 1);
  }
  vector<pair<int, int>> pos;
  for(int i = 1; i <= n; i++) {
    if(l[i] + r[i] - 1 == ans) {
      pos.emplace_back(i - l[i] + 1, i + r[i] - 1);
    }
  }
  sort(pos.begin(), pos.end());
  pos.resize(unique(pos.begin(), pos.end()) - pos.begin());
  cout << (int)pos.size() << ' ' << ans - 1 << '\n';
  
  for(auto i : pos) {
    cout << i.first << '\n';
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