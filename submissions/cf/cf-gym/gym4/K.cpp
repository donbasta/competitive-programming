#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ld dist(ld a, ld b, ld c, ld d) {
  ld dx = a - c;
  ld dy = b - d;
  return hypot(dx, dy);
}

struct Circle {
  ld x, y, r;
  Circle(ld _x, ld _y, ld _r) : x(_x), y(_y), r(_r) {}
  bool operator<(const Circle& other) {
    return r < other.r;
  }
  bool inside(const Circle& other) {
    return other.r - r > dist(x, y, other.x, other.y);
  }
};

vector<Circle> c;
vector<pair<Circle, int>> lol;
int n;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n;
  for(int i = 1; i <= n; i++) {
    ld x, y, r;
    cin >> x >> y >> r;
    c.emplace_back(x, y, r);
  }
  int edges = 0, cur = 0;
  while(edges <= 2 * n && cur < n) {
    vector<pair<Circle, int>> temp;
    int in = 1, tot = 0;
    for(auto i : lol) {
      if((i.first).inside(c[cur])){
        in++;
        continue;
      }
      tot += i.second;
      temp.push_back(i);
    }
    edges += 2 * tot;
    temp.emplace_back(c[cur], in);
    lol = temp;
    cur++;
    cerr << cur << ' ' << edges << lol.size() << '\n';
  }
  if(edges <= 2 * n) {
    cout << edges << '\n';
  } else {
    cerr << edges << '\n';
    cout << "greater" << '\n';
  }
  return 0;
}
