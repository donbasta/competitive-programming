#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

struct Point {
  ll x, y;
  Point(ll _x, ll _y) : x(_x), y(_y) {}
};

struct Line {
  ll a, b, c;
  Line(ll _a, ll _b, ll _c) : a(_a), b(_b), c(_c) {}
  Line(const Point& p, const Point& q) {
    a = p.y - q.y;
    b = q.x - p.x;
    c = -(a * p.x + b * p.y);
  }
  bool contain(const Point& p) {
    return (a * p.x + b * p.y + c == 0);
  }
};

vector<Point> ve;
int n;

bool cek(const vector<int>& vec, int a, int b, int c, int d) {
  Line l1 = Line(ve[vec[a]], ve[vec[b]]);
  Line l2 = Line(ve[vec[c]], ve[vec[d]]);
  bool ret = true;
  for(int i = 0; i < n; i++) {
    bool ok = false;
    ok |= l1.contain(ve[i]);
    ok |= l2.contain(ve[i]);
    ret &= ok;
  }
  return ret;
}

bool cek_lol(const vector<int>& vec) {
  bool ret = false;
  for(int i = 0; i < 3; i++) {
    bool temp = true;
    int ni = (i + 1) % 3;
    int nii = (ni + 1) % 3;
    Line temp1 = Line(ve[vec[i]], ve[vec[ni]]);
    int lol;
    for(int i = 0; i < n; i++) {
      if(i != vec[0] && i != vec[1] && i != vec[2]) {
        lol = i; break;
      }
    }
    Line temp2 = Line(ve[vec[nii]], ve[lol]);
    for(int i = 0; i < n; i++) {
      bool ok = false;
      ok |= temp1.contain(ve[i]);
      ok |= temp2.contain(ve[i]);
      temp &= ok;
    }
    ret |= temp;
  }
  return ret;
}

void solve() {
  cin >> n;
  
  for(int i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    ve.emplace_back(x, y);
  }
  if(n <= 4) {
    cout << "YES" << '\n';
    return;
  }
  Line fi = Line(ve[0], ve[1]);
  int cur = 2;
  while(cur < n && fi.contain(ve[cur])) { ++cur; }
  if(cur == n) {
    cout << "YES" << '\n';
    return;
  }
  int cur2 = cur + 1;
  Line fi2 = Line(ve[0], ve[cur]);
  Line fi3 = Line(ve[1], ve[cur]);
  while(cur2 < n) {
    if(fi.contain(ve[cur2])) { ++cur2; continue; }
    if(fi2.contain(ve[cur2])) { ++cur2; continue; }
    if(fi3.contain(ve[cur2])) { ++cur2; continue; }
    else break;
  } 
  if(cur2 == n) {
    bool ok = cek_lol({0, 1, cur});
    cout << (ok ? "YES" : "NO") << '\n';
    return;
  }
  vector<int> lol = {0, 1, cur, cur2};
  bool ok = false;
  ok |= cek(lol, 0, 1, 2, 3);
  ok |= cek(lol, 0, 2, 1, 3);
  ok |= cek(lol, 0, 3, 1, 2);
  cout << (ok ? "YES" : "NO") << '\n';
  return;
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