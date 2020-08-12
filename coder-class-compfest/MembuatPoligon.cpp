#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

vector<pair<int, int>> pt, ch[2], Pt[2];

int cp(int a, int b, int c, int d) {
  int lol = a * d - b * c;
  if(lol < 0) return -1;
  else if(lol == 0) return 0;
  else return 1;
}

void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    pt.emplace_back(x, y);
  }
  sort(pt.begin(), pt.end());
  Pt[0].push_back(pt[0]), Pt[1].push_back(pt[0]);
  int dx = pt[n - 1].first - pt[0].first;
  int dy = pt[n - 1].second - pt[0].second; 
  for(int i = 1; i < n - 1; i++) {
    int xa = pt[i].first - pt[0].first;
    int ya = pt[i].second - pt[0].second; 
    int cek = cp(dx, dy, xa, ya);
    if(cek > 0) {Pt[0].push_back(pt[i]);}
    else if(cek < 0) {Pt[1].push_back(pt[i]);}
    else {Pt[0].push_back(pt[i]); Pt[1].push_back(pt[i]);}
  }
  Pt[0].push_back(pt[n - 1]), Pt[1].push_back(pt[n - 1]);

  if(Pt[0].size() == n) { //segaris semua
    for(int i = 0; i < n; i++) {
      cout << pt[i].first << ' ' << pt[i].second << '\n';
    }
    return;
  }

  reverse(Pt[1].begin(), Pt[1].end());
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < Pt[i].size(); j++) {
      while(ch[i].size() >= 2) {
        int xa = ch[i].back().first - ch[i][ch[i].size() - 2].first;
        int ya = ch[i].back().second - ch[i][ch[i].size() - 2].second;
        int xb = Pt[i][j].first - ch[i].back().first;
        int yb = Pt[i][j].second - ch[i].back().second;
        if(cp(xa, ya, xb, yb) > 0) {ch[i].pop_back();}
        else break;
      }
      ch[i].push_back(Pt[i][j]);
    }
  }
  for(int i)
  int ans = ch[0].size() + ch[1].size();
  cout << (ans == n + 2 ? "YA" : "TIDAK") << '\n';
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