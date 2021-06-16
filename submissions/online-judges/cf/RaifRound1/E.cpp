#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, k;
vector<ll> ar;

bool cek(ll mid) {
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    cnt += (ar[i] + mid - 1) / mid;
  }
  return (cnt <= k);
}

ll f(ll mid) {
  int cnt = 0;
  ll ret = 0;
  priority_queue<pair<ll, int>> pq;
  // multiset<ll> se;
  for(int i = 0; i < n; i++) {
    cnt += (ar[i] + mid - 1) / mid;
    if(ar[i] % mid == 0) {
      ret += ar[i] * mid;
      for(int j = 0; j < (ar[i] / mid); j++) {
        pq.emplace(mid, i);
        // se.insert(mid);
      }
    } else {
      ll sisa = ar[i] % mid;
      ret += mid * mid * (ar[i] / mid) + sisa * sisa;
      for(int j = 0; j < (ar[i] / mid); j++) {
        pq.emplace(mid, i);
        // se.insert(mid);
        // pq.push(mid);
      }
      pq.emplace(sisa, i);
      // se.insert(sisa);
      // pq.push(sisa);
    }
  }
  cerr << cnt << ' ' << (int)pq.size() << ' ' << mid << '\n';
  assert(cnt == (int)pq.size());
  assert(cnt <= k);
  while(cnt < k) {
    auto top = pq.top();
    pq.pop();
    ret -= (top.first * top.first);
    if(top.first & 1) {
      ret += (top.first * top.first + 1) / 2;
      pq.emplace(top.first / 2, top.second), pq.emplace((top.first + 1) / 2, top.second);
    } else {
      ret += (top.first * top.first) / 2;
      pq.emplace(top.first / 2, top.second), pq.emplace(top.first / 2, top.second);
    }
    cnt++;
  }
  vector<ll> ve[n];
  while(!pq.empty()) {
    auto top = pq.top();
    pq.pop();
    ve[top.second].push_back(top.first);
  }
  ll Ret = 0;
  for(int i = 0; i < n; i++) {
    ll temp = 0;
    for(auto c : ve[i]) {
      temp += c;
    }
    int sz = (int)ve[i].size();
    if(temp % sz == 0)
      Ret += (temp * sz);
    else {
      ll sisa = (temp % sz);
      Ret += sisa * sisa + sz * sz * (temp / sz);
    }
  }
  cerr << Ret;
  // cerr << mid << ' ' << ret << '\n';
  return Ret;
}

void solve() {
  cin >> n >> k;

  ar.resize(n);

  ll sum = 0;
  ll ans = 0;
  for(int i = 0; i < n; i++) {
    cin >> ar[i];
    ans += ar[i] * ar[i];
  }
  ll lo = 1, hi = 1e6;
  while(lo <= hi) {
    ll mid = (lo + hi) / 2;
    if(cek(mid)) {
      ans = min(ans, f(mid));
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
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