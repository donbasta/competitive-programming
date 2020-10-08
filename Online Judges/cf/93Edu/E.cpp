#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  set<int> se, ye;
  auto posBound = se.end();
  int cnt = 0, cntY = 0, bound = -1;
  int smY = INF;
  ll sum = 0;
  for(int i = 0; i < n; i++) {
    int tp, d;
    cin >> tp >> d;
    if(tp == 1) {
      if(d < 0) {
        d = -d;
        if(d == *ye.begin()) {
          ye.erase(ye.find(d));
          if(!ye.empty())
            se.erase(se.find(*ye.begin()));
          ++posBound;
          sum -= d;
        }
        ye.erase(se.find(d));
        if(bound >= d) {
          sum -= bound;
          sum -= d;
          bound = *(++posBound);
        } else if(bound < d) {
          sum -= 2 * d;
        }
        if(posBound == se.end()) bound = INF;
        smY = *ye.begin();
        cnt--;
        cntY--;
      } else if(d > 0) {
        if(se.empty()) {
          ye.insert(d);
          smY = d;
          sum += d;
          bound = d;
        } else {
          if(ye.empty()) {
            ye.insert(d);
            --posBound;
            sum += *posBound;
          } else {
            int nd;
            if(d < *ye.begin()){
              nd = *ye.begin();
              sum -= nd;
              sum += d;
            } else {
              nd = d;
            }
            ye.insert(d);
            se.insert(nd);
            if(nd > bound) {
              sum += 2 * nd;
            } else {
              bound = *(--posBound);
              sum += (nd + bound);
            }
          }
        }
        cnt++;
        cntY++;
      }
    } else if(tp == 0) {
      if(d < 0) {
        d = -d;
        se.erase(se.find(d));
        if(d > bound) {
          bound = *(--posBound);
          sum -= 2 * d;
        } else {
          sum -= d;
        }
        if(posBound == se.end()) bound = INF;
        cnt--;
      } else if(d > 0) {
        if(se.empty()) {
          se.insert(d);
          sum += d;
        }
        se.insert(d);
        if(d > bound) {
          if(cnt != cntY) sum -= bound;
          sum += 2 * d;
          bound = *(++posBound);
        } else {
          sum += d;
        }
        cnt++;
      }
    }
    cout << sum << '\n';
    cerr << i << ' ' << bound << '\n';
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