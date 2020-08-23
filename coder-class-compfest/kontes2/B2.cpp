#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
// #define ll __int128
// #define pll pair<ll, ll>

// using ll = __int128_t;
using ll = long long;
// using ld = long double;
using pll = pair<ll, ll>;

int cp(ll a, ll b, ll c, ll d) {
  ll lol = a * d - b * c;
  if(lol < 0) return -1;
  else if(lol == 0) return 0;
  else return 1;
}

ll dobelSignedArea(pll a, pll b, pll c) {
  return a.fi * b.se - a.se * b.fi + b.fi * c.se - b.se * c.fi + c.fi * a.se - c.se * a.fi;
}

ll dobleAreaPolygon(const vector<pll>& V) {
  int sz = (int)V.size();
  ll ret = 0;
  for(int i = 0; i < sz; i++) {
    int ni = (i + 1) % sz;
    ret += dobelSignedArea(V[i], V[ni], V[0]);
  }
  return abs(ret);
}

vector<pair<ll, ll>> pt, ch[2], Pt[2];
ll AREA;

bool inside(pll x, const vector<pll>& V) {
  int sz = (int)V.size();
  ll cek = 0;
  for(int i = 0; i < sz; i++) {
    int ni = (i + 1) % sz;
    ll temp = abs(dobelSignedArea(V[i], V[ni], x));
    if(cek > AREA - temp) return false;
    cek += temp;
  }
  return (cek == AREA);
}

void init() {
  pt.clear();
  Pt[0].clear();
  Pt[1].clear();
  ch[0].clear();
  ch[1].clear();
}

void solve() {
  int n, m;
  cin >> n >> m;
  init();
  set<pll> se;
  for(int i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    se.emplace(x, y);
  }
  for(auto i : se) {
    pt.emplace_back(i);
  }
  n = (int)pt.size();
  if(n == 1) {
    while(m--) {
      ll x, y;
      cin >> x >> y;
      if((x == pt[0].first) && (y == pt[0].second)) {
        cout << "YA";
      } else {
        cout << "TIDAK";
      }
      cout << '\n';
    }
    return;
  }
  if(n == 2) {
    while(m--) {
      ll x, y;
      cin >> x >> y;
      vector<pll> lol = pt;
      if(dobelSignedArea(make_pair(x, y), lol[0], lol[1]) == 0) {
        // ll mnx = min(lol[0].first, lol[1].first), mxx = max(lol[0].first, lol[1].first);
        // ll mny = min(lol[0].second, lol[1].second), mxy = max(lol[0].second, lol[1].second);
        // if((x >= mnx) && (x <= mxx) && (y >= mny) && (y <= mxy)) {
        //   cout << "YA";
        // } else {
        //   cout << "TIDAK";
        // }
        cout << "YA";
      } else {
        cout << "TIDAK";
      }
    }
    return;
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
  vector<pll> lol;
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < ch[i].size() - 1; j++) {
      lol.emplace_back(ch[i][j].first, ch[i][j].second);
    }
  }
  // assert((int)lol.size() >= 3);
  AREA = dobleAreaPolygon(lol);
  while(m--) {
    ll x, y;
    cin >> x >> y;
    if((int)lol.size() == 1) {
      if((x == lol[0].first) && (y == lol[0].second)) {
        cout << "YA";
      } else {
        cout << "TIDAK";
      }
    } else if((int)lol.size() == 2) {
      if(dobelSignedArea(make_pair(x, y), lol[0], lol[1]) == 0) {
        // ll mnx = min(lol[0].first, lol[1].first), mxx = max(lol[0].first, lol[1].first);
        // ll mny = min(lol[0].second, lol[1].second), mxy = max(lol[0].second, lol[1].second);
        // if((x >= mnx) && (x <= mxx) && (y >= mny) && (y <= mxy)) {
        //   cout << "YA";
        // } else {
        //   cout << "TIDAK";
        // }
        cout << "YA";
      } else {
        cout << "TIDAK";
      }
    } else {
      if(inside(make_pair(x, y), lol)) {
        cout << "YA";
      } else {
        cout << "TIDAK";
      }
    }
    cout << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  cin >> TC;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}