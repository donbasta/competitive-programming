#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 500 + 5;
const int M = 5000 + 5;

int d, s;

bool udah[N][M];
pair<int, int> par[N][M];

void printAns(int D, int S) {
  if(D == 0 && S == 0) return;
  printAns(par[D][S].first, par[D][S].second);
  cout << S - par[D][S].second;
}

void solve() {
  cin >> d >> s;
  queue<pair<int, int>> Q;
  Q.emplace(0, 0);
  udah[0][0] = true;
  while(!Q.empty()) {
    auto cur = Q.front();
    Q.pop();
    int mod = cur.first, sum = cur.second;
    mod = (mod * 10) % d;
    for(int i = 0; i < 10; i++) {
      int nmod = (mod + i) % d;
      int nsum = sum + i;
      if(udah[nmod][nsum]) continue;
      if(nsum > s) continue;
      udah[nmod][nsum] = true;
      par[nmod][nsum] = cur;
      Q.emplace(nmod, nsum);
    }
  }
  if(!udah[0][s]) {
    cout << -1 << '\n';
    return;
  }
  printAns(0, s);
  cout << '\n';
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