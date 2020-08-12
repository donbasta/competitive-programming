#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

vector<pair<ll, ll>> pt, ch[2], Pt[2];

int cp(ll a, ll b, ll c, ll d) {
  ll lol = a * d - b * c;
  if(lol < 0) return -1;
  else if(lol == 0) return 0;
  else return 1;
}

ld dist(pair<ll, ll> a, pair<ll, ll> b) {
  ll dx = b.first - a.first;
  ll dy = b.second - a.second;
  return sqrtl(dx * dx + dy * dy);
}

void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    pt.emplace_back(x, y);
  }
  sort(pt.begin(), pt.end());
  Pt[0].push_back(pt[0]), Pt[1].push_back(pt[0]);
  ll dx = pt[n - 1].first - pt[0].first;
  ll dy = pt[n - 1].second - pt[0].second; 
  for(int i = 1; i < n - 1; i++) {
    ll xa = pt[i].first - pt[0].first;
    ll ya = pt[i].second - pt[0].second; 
    int cek = cp(dx, dy, xa, ya);
    if(cek > 0) {Pt[0].push_back(pt[i]);}
    else if(cek < 0) {Pt[1].push_back(pt[i]);}
  }
  Pt[0].push_back(pt[n - 1]), Pt[1].push_back(pt[n - 1]);
  reverse(Pt[1].begin(), Pt[1].end());
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < Pt[i].size(); j++) {
      while(ch[i].size() >= 2) {
        ll xa = ch[i].back().first - ch[i][ch[i].size() - 2].first;
        ll ya = ch[i].back().second - ch[i][ch[i].size() - 2].second;
        ll xb = Pt[i][j].first - ch[i].back().first;
        ll yb = Pt[i][j].second - ch[i].back().second;
        if(cp(xa, ya, xb, yb) >= 0) {ch[i].pop_back();}
        else break;
      }
      ch[i].push_back(Pt[i][j]);
    }
  }
  ld ans = 0;
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < ch[i].size() - 1; j++) {
      ans += dist(ch[i][j], ch[i][j + 1]);
    }
  }
  cout << fixed << setprecision(12);
  cout << ans << '\n';
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