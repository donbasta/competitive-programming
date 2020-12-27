#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 52;

int n;
int c[N + 10];
vector<vector<int>> ve;

bool sorted() {
  for(int i = 1; i <= n; i++) {
    if(c[i] != i) return 0;
  }
  return 1;
}

bool is_cyclic() {
  bool ok = 0;
  for(int i = 1; i <= n; i++) {
    int tmp = i;
    bool flag = 1;
    for(int j = 1; j <= n; j++) {
      flag &= (c[j] == tmp);
      tmp = (tmp % n) + 1;
    }
    ok = flag;
    if(ok) break;
  }
  return ok;
}

void change(const vector<int>& d) {
  int sz = (int)d.size();
  assert(sz == 2 || sz == 3);
  vector<int> ve(n + 1);
  if(sz == 2) {
    int st = d[0] + 1;
    int tot = 0;
    while(tot < n) {
      ve[tot++] = c[st];
      st = (st % n) + 1;
    }
    for(int i = 1; i <= n; i++) {
      c[i] = ve[i - 1];
    }
    return;
  }
  if(sz == 3) {
    for(int i = d[1] + d[2] + 1; i <= n; i++) {
      ve[i] = c[i - d[1] - d[2]];
    }
    for(int i = d[2] + 1; i <= d[1] + d[2]; i++) {
      ve[i] = c[i - d[2] + d[0]];
    }
    for(int i = 1; i <= d[2]; i++) {
      ve[i] = c[i + d[0] + d[1]];
    }
    for(int i = 1; i <= n; i++) {
      c[i] = ve[i];
    }
  }
}

void permute() {
  int last = c[n];
  int nx = (last % n) + 1;
  int border = 0, border2 = 0;
  // cerr << nx << '\n';
  for(int i = 1; i <= n; i++) {
    if(c[i] == nx) border = i;
  }
  int tmp = nx;
  for(int i = border; i <= n; i++) {
    if(c[i] != tmp) {
      border2 = i;
      break;
    }
    tmp = (tmp % n) + 1;
  }
  // cerr << border << ' ' << border2 << '\n';
  if(border == 1) {
    change({border2 - 1, n - border2 + 1});
    ve.push_back({border2 - 1, n - border2 + 1});
  } else {
    change({border - 1, border2 - border, n - border2 + 1});
    ve.push_back({border - 1, border2 - border, n - border2 + 1});
  }
}

void solve() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  if(n == 1) {
    cout << 0 << '\n';
    return;
  }
  while(!sorted()) {
    if(is_cyclic()) {
      ve.push_back({n - c[1] + 1, c[1] - 1});
      break;
    }
    permute();
    // for(int i = 1; i <= n; i++) {
    //   cerr << c[i] << ' ';
    // }
    // cerr << '\n';
  }
  assert((int)ve.size() <= n);
  cout << (int)ve.size() << '\n';
  for(auto& e : ve) {
    cout << (int)e.size() << ' ';
    for(auto& ee : e) {
      cout << ee << ' ';
    }
    cout << '\n';
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