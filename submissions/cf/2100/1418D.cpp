#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, q, mx;
unordered_map<int, int> cnt;
set<int> se;
set<pair<int, int>> dif;

void add(int x) {
  cnt[x]++;
  if (se.empty()) {
    mx = 0;
  } else {
    if (x < *se.begin()) {
      dif.emplace(*se.begin() - x, x);
    } else if (x > *se.rbegin()) {
      dif.emplace(x - *se.rbegin(), *se.rbegin());
    } else {
      auto pos = se.lower_bound(x);
      int atas = *pos;
      int bawah = *(--pos);
      dif.erase(make_pair(atas - bawah, bawah));
      dif.emplace(atas - x, x);
      dif.emplace(x - bawah, bawah);
    }
    mx = (dif.rbegin())->first;
  }
  se.insert(x);
}

void rem(int x) {
  cnt[x]--;
  if (cnt[x] == 0) {
    se.erase(x);
    if (se.empty()) return;
    auto pos = se.lower_bound(x);
    if (pos == se.begin()) {
      dif.erase(make_pair(*pos - x, x));
    } else if (pos == se.end()) {
      int r = *se.rbegin();
      dif.erase(make_pair(x - r, r));
    } else {
      int atas = *pos;
      int bawah = *(--pos);
      dif.erase(make_pair(atas - x, x));
      dif.erase(make_pair(x - bawah, bawah));
      dif.emplace(atas - bawah, bawah);
    }
    if (dif.empty()) {
      mx = 0;
    } else {
      mx = (dif.rbegin())->first;
    }
  }
}

int getAns() {
  if (se.empty()) return 0;
  return (*se.rbegin() - *se.begin() - mx);
}

void solve() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
    se.insert(x);
  }

  for (auto it = se.begin(); it != se.end(); ++it) {
    auto nx = it;
    ++nx;
    if (nx == se.end()) break;
    dif.emplace(*nx - *it, *it);
  }
  if (dif.empty()) {
    mx = 0;
  } else {
    mx = (dif.rbegin())->first;
  }
  
  cout << getAns() << '\n';
  while (q--) {
    int t, x;
    cin >> t >> x;
    if (t) add(x);
    else rem(x);
    cout << getAns() << '\n';
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