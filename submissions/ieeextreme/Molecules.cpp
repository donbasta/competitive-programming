#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int INF = 1e9;

int q;
int c, h, o;

vector<vector<int>> candidate;

void init() {
  for (int i = 0; i < 24; i++) {
    for (int j = 0; j < 24; j++) {
      for (int k = 0; k < 24; k++) {
        bool ok = 1;
        ok &= ((i+j+k) % 3 == 0);
        ok &= ((j + 2*k) % 4 == 0);
        ok &= ((4*i + j + 6*k) % 8 == 0);
        if (ok) {
          candidate.push_back({i,j,k});
        }
      }
    }
  }
}

bool cek_valid(int c, int h, int o){
    int x = (-4 * c + h + 2 * o);
    if ((x % 4) || x < 0) return 0;
    x /= 4;
    int y = o - c - x;
    if (y < 0) return 0;
    int z = c - y;
    if ((z % 6) || z < 0) return 0;
    return 1;
}

const int BAT = 100;

void solve(){
  cin >> c >> h >> o;
  if (cek_valid(c, h, o)){
    cout << 0 << el;
    return;
  }
  
  for (int ubah=1;;ubah++){
    for (int i=-ubah;i<=ubah;i++){
      int sisa = ubah - abs(i);
      for (int j=-sisa;j<=sisa;j++){
        int sisa2 = sisa - abs(j);
        int k = sisa2;
        
        if (cek_valid(c + i, h + j, o + k)){
          cout << ubah << el;
          return;
        }
        if (cek_valid(c + i, h + j, o - k)){
          cout << ubah << el;
          return;
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  init();
  cerr << candidate.size() << '\n';

  int TC = 1;
  cin >> TC;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}