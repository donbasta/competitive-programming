#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 1e9;

int ans;

void ask(int a, int b) {
  cout << a << ' ' << b << '\n';
  cout << endl;
  cin >> ans;
}

void answer(int a, int b) {
  cout << "A " << a << ' ' << b << '\n';
  exit(0);
}

void solve() {
  int tl = 0, tr = INF, td = 0, tu = INF;
  while(tl < tr || td < tu) {
    int tm1 = (tl + tr) / 2;
    int tm2 = (tu + td) / 2;
    int ntl = tl, ntr = tr, ntd = td, ntu = tu;
    ask(tl, td);
    ask(tr, td);
    if(ans) {ntl = tm1 + 1;}
    else {ntr = tm1;}
    ask(tr, tu);
    if(ans) {ntd = tm2 + 1;}
    else {ntu = tm2;}
    tl = ntl, tr = ntr, td = ntd, tu = ntu;
  }
  answer(tl, tu);
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