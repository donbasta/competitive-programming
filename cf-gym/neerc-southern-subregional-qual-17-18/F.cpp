#include<bits/stdc++.h>

#define fi first
#define se second

using namespace std;
using ll = long long;
using ld = long double;
using piii = pair<pair<int, int>, int>;

const int N = 100;

piii ca[N + 5];
int n, k, m, a;
int pre[N + 5], ans[N + 5];

bool comp(piii A, piii B) {
  if(A.fi.fi == B.fi.fi) {
    return A.fi.se < B.fi.se;
  }
  return A.fi.fi > B.fi.fi;
}

void solve() {
  cin >> n >> k >> m >> a;
  for(int i = 1; i <= n; i++) {
    ca[i].se = i;
  }
  for(int i = 1; i <= a; i++) {
    int x;
    cin >> x;
    ca[x].fi.fi++;
    ca[x].fi.se = i;
  }
  sort(ca + 1, ca + 1 + n, comp);
  for(int i = 1; i <= n; i++) {
    cerr << ca[i].fi.fi << ' ' << ca[i].fi.se << ' ' << ca[i].se << '\n';
  }
  for(int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + ca[i].fi.fi;
  }
  pre[n + 1] = pre[n];
  for(int i = 1; i <= n; i++) {
    int pos;
    for(int j = 1; j <= n; j++) {
      if(ca[j].se == i) {
        pos = j; break;
      }
    }
    int curPt = ca[pos].fi.fi;
    int who = ca[pos].se;
    if(k == n && curPt > 0) {ans[who] = 1; continue;}
    if(k == n && curPt + m - a > 0) {ans[who] = 2; continue;}
    if(k == n && curPt + m - a == 0) {ans[who] = 3; continue;}
    bool ok1 = (curPt > 0) && (pos <= k);
    if(pos <= k) {
      int mx = (curPt + 1) * (k + 1 - pos) - (pre[k + 1] - pre[pos]);
      ok1 &= (mx > m - a);
    }
    if(ok1) {ans[who] = 1; continue;}
    if(pos <= k && curPt + m - a > 0) {ans[who] = 2; continue;}
    if(pos <= k && curPt + m - a == 0) {ans[who] = 3; continue;}
    assert(pos > k);
    int maxPosPt = curPt + m - a;
    bool ok2 = false;
    for(int j = 1; j <= k; j++) {
      if(ca[j].fi.fi < maxPosPt) ok2 = true;
    }
    if(ok2 && maxPosPt > 0) {ans[who] = 2; continue;}
    ans[who] = 3;
  }
  for(int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
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