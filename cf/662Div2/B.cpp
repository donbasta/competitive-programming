#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int M = 1e5;

int n, q;
set<pair<int, int>> se;
vector<int> cnt;

void solve() {
  cnt.resize(M + 1);
  cin >> n;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  for(int i = 1; i <= M; i++) {
    se.emplace(cnt[i], i);
  }
  cin >> q;
  while(q--) {
    char c;
    int now;
    cin >> c >> now;
    se.erase(se.find(make_pair(cnt[now], now)));
    if(c == '+') {
      cnt[now]++;
    } else if(c == '-') {
      cnt[now]--;
    }
    se.emplace(cnt[now], now);
    auto temp = se.rbegin();
    int mx1 = temp->first; 
    int mx2 = (++temp)->first;
    int mx3 = (++temp)->first;
    if(mx1 >= 8 || (mx1 >= 6 && mx2 >= 2) || (mx1 >= 4 && mx2 >= 2 && mx3 >= 2) || (mx1 >= 4 && mx2 >= 4)) {
      cout << "YES";
    } else {
      cout << "NO";
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