#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e5 + 69;

int r, c, n;
vector<pair<int, int>> sisi[5];
int cnt[N], lol[N];
stack<int> st;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> r >> c >> n;
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < 2; j++) {
      int x, y;
      cin >> x >> y;
      if(y == 0 && x < r) {
        sisi[1].emplace_back(x, i);
      } else if(x == r && y < c) {
        sisi[2].emplace_back(y, i);
      } else if(y == c && x > 0) {
        sisi[3].emplace_back(x, i);
      } else if(x == 0 && y > 0) {
        sisi[4].emplace_back(y, i);
      }
    }
  }
  for(int i = 1; i <= 4; i++) {
    if(i <= 2) {
      sort(sisi[i].begin(), sisi[i].end());
    } else {
      sort(sisi[i].begin(), sisi[i].end());
      reverse(sisi[i].begin(), sisi[i].end());
    }
  }
  for(int i = 1; i <= 4; i++) {
    for(auto j : sisi[i]) {
      cnt[j.second]++;
    }
  }
  bool ok = true;
  for(int i = 1; i <= 4; i++) {
    for(auto j : sisi[i]) {
      if(cnt[j.second] < 2)
        continue;
      if(lol[j.second] == 0) {
        st.push(j.second);
        lol[j.second] = 1;
      } else {
        if(!st.empty() && st.top() != j.second) {
          ok = false;
          break;
        } else {
          st.pop();
        }
      }
    }
    if(!ok)
      break;
  }
  cout << (ok ? "YES" : "NO") << '\n';
  return 0;
}