

typedef long long LD;
inline bool eq(LD a, LD b) { return a == b; }
inline bool lt(LD a, LD b) { return a < b; }
inline bool le(LD a, LD b) { return a <= b; }
inline int sign(LD x) { return eq(x, 0) ? 0 : (x < 0 ? -1 : 1); }
 
struct point {
  LD x, y;
  point(LD tx = 0, LD ty = 0) : x(tx), y(ty) {}
  point operator+(const point& p) const { return point(x+p.x, y+p.y); }
  point operator-(const point& p) const { return point(x-p.x, y-p.y); }
  point operator*(LD s) { return point(x*s, y*s); }
  point operator/(LD s) { return point(x/s, y/s); }
  LD operator*(const point& p) const { return x*p.x + y*p.y; } // dot
  LD operator%(const point& p) const { return x*p.y - y*p.x; } // cross
  LD norm_sq() { return *this * *this; }
  bool operator==(const point& p) const { return eq(x, p.x) && eq(y, p.y); }
  bool operator<(const point& p) const { return eq(y, p.y) ? x < p.x : y < p.y; }
};
ostream& operator<<(ostream& os, point p) {
  return os << "(" << p.x << ", " << p.y << ")";
}
// -1 : clockwise, 0 = collinear, 1 : counter-clockwise
int ccw(point a, point b, point c) { return sign((b - a) % (c - b)); }
 
void sortCircular(vector<pair<point, int>> &events) {
  vector<pair<point, int>> upper, lower;
  for (pair<point, int> & e : events) {
    if (point() < e.first)
      upper.push_back(e);
    else
      lower.push_back(e);
  }
  auto cmp = [](pair<point, int> lef, pair<point, int> rig) {
    int dir = sign(lef.first % rig.first);
    if (dir == 0)
      return lef.second < rig.second;
    return dir > 0;
  };
  sort(upper.begin(), upper.end(), cmp);
  sort(lower.begin(), lower.end(), cmp);
  for (int i = 0; i < (int)upper.size(); ++i)
    events[i] = upper[i];
  for (int i = 0; i < (int)lower.size(); ++i)
    events[i + upper.size()] = lower[i];
}