#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int PI = 180000;

vector<int> ang;
int n, r;

int jarak(int i, int j) {
  int ret = ang[j] - ang[i];
  if(ret < 0) ret += PI * 2;
  return ret;
}

ll calc(int x) {
  return 1LL * (x) * (2 * n - x - 3) / 2;
}

void solve() {
  int tc = 1;
  while(1) {
    cin >> n >> r;
    if(n == 0 && r == 0) {
      return;
    }
    ang.clear();
    for(int i = 0; i < n; i++) {
      ld x;
      cin >> x;
      int ix = round(x * 1e3);
      ang.emplace_back(ix);
    }
    sort(ang.begin(), ang.end());
    int pi = 0, pj = 1;
    ll acute = 0;
    ll right = 0;
    while(pi < n) {
      while(pj != pi && jarak(pi, pj) < PI) {
        pj = (pj + 1) % n;
      }
      int jum;
      if(pj > pi) { jum = pj - pi - 1; }
      else { jum = pj - pi - 1 + n; }
      if(jarak(pi, pj) == PI) right += jum;
      acute += calc(jum);
      pi++;
    }

    ll obtuse = 1LL * n * (n - 1) * (n - 2) / 2 - acute - right;
    ll ans = 1LL * n * (n - 1) * (n - 2) / 6 - obtuse - right;
    cout << "Case " << tc << ": ";
    cout << ans << '\n';
    tc++;
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