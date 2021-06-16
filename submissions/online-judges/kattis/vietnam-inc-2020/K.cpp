#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

inline int sgn(ll n) { return (n > 0 ? 1 : (n < 0 ? -1 : 0)); }

struct Point {
  ll x, y;
  Point(ll _x = 0, ll _y = 0) : x(_x), y(_y) {}
  Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
  Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
  ll operator%(const Point& p) const { return x * p.y - y * p.x; }
  bool operator<(const Point& p) const { return (y == p.y) ? x < p.x : y < p.y; }
};

inline int ccw(const Point& a, const Point& b, const Point& c) { return sgn((b - a) % (c - b)); }

ld dist(const Point& a, const Point& b) {
  return sqrtl((ld)(a.x-b.x)*(a.x-b.x) + (ld)(a.y-b.y)*(a.y-b.y));
}

bool ord(const Point& a, const Point& b, const Point& c) {
  return dist(a, b) + dist(a, c) == dist(b, c);
}

void sort_circular(vector<pair<Point, int>>& events) {
  vector<pair<Point, int>> upper, lower;
  for(auto& e : events) {
    if(Point() < e.first) { upper.push_back(e); }
    else { lower.push_back(e); }
  }
  auto cmp = [](pair<Point, int> l, pair<Point, int> r) {
    int dir = sgn(l.first % r.first);
    if(dir == 0) { return l.second < r.second; }
    return dir > 0;
  };
  sort(upper.begin(), upper.end(), cmp);
  sort(lower.begin(), lower.end(), cmp);
  for(int i = 0; i < (int)upper.size(); i++) { events[i] = upper[i]; }
  for(int i = 0; i < (int)lower.size(); i++) { events[i + upper.size()] = lower[i]; } 
}

void solve(int n) {

  vector<vector<int>> c2(n + 1, vector<int>(n + 1));
  vector<vector<vector<int>>> c3(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1)));
  vector<Point> ve;

  for(int i = 1; i <= n; i++) {
    ll x, y;
    cin >> x >> y;
    ve.emplace_back(x, y);
  }

  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      for(int k = 0; k < n; k++) {
        if(ccw(ve[i], ve[j], ve[k]) == 1) { c2[i][j]++; }
        else if(ccw(ve[i], ve[j], ve[k]) == -1) { c2[j][i]++; }
      }
    }
  }

  for(int i = 0; i < n; i++) {
    vector<pair<Point, int>> temp;
    for(int j = 0; j < n; j++) {
      if(j == i) continue;
      temp.emplace_back(ve[j] - ve[i], j);
    }
    sort_circular(temp);
    vector<int> pos(n);
    vector<int> sz(n), pre(n);
    int t = 0;
    for(int j = 0; j < (int)temp.size(); j++) {
      if (j > 0 && ccw(0, temp[j-1].first, temp[j].first) == 0 && !ord(0, temp[j-1].first, temp[j].first)) {
        pos[temp[j].second] = t;
      } else {
        pos[temp[j].second] = ++t;
      }
      sz[pos[temp[j].second]]++;
    }
    for (int i = 1; i < n; i++) {
      pre[i] = pre[i-1] + sz[i];
    }
    assert(pre[n-1] == n-1);
    for(int j = 0; j < n; j++) {
      for(int k = j + 1; k < n; k++) {
        if(j == i || k == i) continue;

        int nj = pos[j], nk = pos[k];
        if (nk == nj) continue;
        bool flag = 0;
        if (nj > nk) {
          swap(nj, nk);
          flag = 1;
        }
        Point pj = ve[j]-ve[i], pk = ve[k]-ve[i];
        if (flag) {
          swap(pj, pk);
        }
        int tmp = pre[nk-1] - pre[nj];
        if(ccw(0, pj, pk) == 1) { c3[i][j][k] = c3[i][k][j] = tmp; }
        else if(ccw(0, pj, pk) == -1) { c3[i][j][k] = c3[i][k][j] = n - 1 - tmp - sz[nk] - sz[nj]; }
      }
    }
  }
  ll ans1 = 0, ans2 = 0;
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      for(int k = j + 1; k < n; k++) {
        int ni = i, nj = j, nk = k;
        if(ccw(ve[ni], ve[nj], ve[nk]) == 0) {
          ans2 += (c2[ni][nj] + c2[nj][ni]);
          continue;
        }
        if(ccw(ve[ni], ve[nj], ve[nk]) == -1) swap(nj, nk);
        ll temp = n;
        temp += (c3[ni][nj][nk] + c3[nj][nk][ni] + c3[nk][ni][nj]);
        temp -= (c2[ni][nj] + c2[nj][nk] + c2[nk][ni]);
        
        ll lol = (c3[ni][nj][nk] + c3[nj][nk][ni] + c3[nk][ni][nj]) - 3LL * temp;
        ans1 += lol;
      }
    }
  }
  cout << (ans1 - ans2) / 4 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  while(1) {
    int n;
    cin >> n;
    if (!n) break;
    solve(n);
  }
  
  return 0;
}