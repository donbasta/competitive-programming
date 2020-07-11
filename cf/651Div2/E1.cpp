#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

set<int> se[2];
int n;
string s, t;

int main() {
ios_base::sync_with_stdio(0);
cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

cin >> n;
cin >> s >> t;

int one = 0;
for(int i = 0; i < n; i++) {
  if(s[i] == '1'){
    one++;
  }
  if(t[i] == '1') {
    one--;
  }
  if(s[i] != t[i])
    se[t[i] - '0'].insert(i);
}
if(one != 0) {
  cout << -1 << '\n';
  return 0;
}
int cnt = n, ans = 0;
vector<int> pos;
while(cnt > 0) {
  int t1 = 2e9, t0 = 2e9;
  if(!se[1].empty()){
    // cerr << "lol";
    t1 = *se[1].begin();
  }
  if(!se[0].empty()){
    // cerr << "lol";
    t0 = *se[0].begin();
  }
  int aw = min(t1, t0);
  int cur = aw;
  // cerr << "lol";
  do {
    // cerr << cur << ":D\n";
    pos.push_back(cur);
    int dig = s[cur] - '0';
    auto next = se[dig].lower_bound(cur);
    if(next == se[dig].end())
      break;
    cur = *next;
  } while(cur != aw);
  int sz = (int) pos.size();
  if(sz & 1)
    sz--;
  for(int i = 0; i < sz; i++) {
    for(int x = 0; x < 2; x++) {
      if(se[x].count(pos[i]))
        se[x].erase(pos[i]);
    }
  }
  if(sz > 1)
    ans++;
  cnt = (int) se[0].size() + (int) se[1].size();
  pos.clear();
}
cout << ans << '\n';
return 0;
}