typedef long double LD;
const LD EPS = 1e-9, PI = acos(-1);
inline bool eq(LD a, LD b) { return fabs(a-b) < EPS; }
inline bool lt(LD a, LD b) { return a + EPS < b; }
inline bool le(LD a, LD b) { return a < b + EPS; }
inline int sign(LD x) { return eq(x, 0) ? 0 : (x < 0 ? -1 : 1); }

struct point {
  LD x, y;
  point(LD x = 0, LD y = 0) : x(x), y(y) {}
  point operator+(const point& p) const { return point(x+p.x, y+p.y); }
  point operator-(const point& p) const { return point(x-p.x, y-p.y); }
  point operator*(LD s) { return point(x*s, y*s); }
  point operator/(LD s) { return point(x/s, y/s); }
  LD operator*(const point& p) const { return x*p.x + y*p.y; } // dot
  LD operator%(const point& p) const { return x*p.y - y*p.x; } // cross
  LD norm_sq() { return *this * *this; }
  LD norm() { return sqrt(*this * *this); }
  point rotate(LD cs, LD sn) { return point(x*cs-y*sn, x*sn+y*cs); }
  point rotate(LD angle) { return rotate(cos(angle), sin(angle)); }
  bool operator==(const point& p) const { return eq(x, p.x) && eq(y, p.y); }
  bool operator<(const point& p) const { return eq(y, p.y) ? x < p.x : y < p.y; }
};
int ccw(point a, point b, point c) { return sign((b - a) % (c - b)); }
LD dist(point a, point b) { return (b-a).norm(); }
LD dist2(point a, point b) { return (b-a).norm_sq(); }
LD angle(point a, point o, point b) {
  point oa = a-o, ob = b-o;
  return acos(oa*ob/(oa.norm()*ob.norm()));
}
point bisector(point a, point b) { return a * b.norm() + b * a.norm(); }

//LINE 

struct line {
  point a, ab; // p(t) = a + ab * t
  line(point ta, point tb) {
    if (tb < ta) swap(ta, tb);
    a = ta; ab = tb-ta;
  }
  point b() { return a + ab; }
  bool isLine() { return !(ab == point()); } // minor
  operator bool() { return !(ab == point()); } // minor
  // Line
  bool onLine(point p) {
    if (ab == point()) return a == p;
    return eq(ab % (p-a), 0);
  }
  LD distLine(point p) {
    if (ab == point()) return dist(a, p);
    return fabs((p-a) % ab)/ab.norm();
  }
  point projection(point p) {
    if (ab == point()) return a;
    return a + ab * ((p-a) * ab / ab.norm_sq());
  }
  point reflection(point p) {
    return projection(p) * 2.0 - p;
  }
  // Segment
  bool onSegment(point p) {
    if (ab == point()) return a == p;
    point pa = a-p, pb = b()-p;
    return eq(pa % pb, 0) && le(pa * pb, 0);
  }
  LD distSegment(point p) {
    if (le((p-a) * ab, 0)) return dist(a, p);
    if (le(0, (p-b()) * ab)) return dist(b(), p);
    return distLine(p);
  }
  point closestSegment(point p) {
    if (le((p-a) * ab, 0)) return a;
    if (le(0, (p-b()) * ab)) return b();
    return projection(p);
  }
  bool areParallel(line l) {
    return eq(ab % l.ab, 0);
  }
  bool areSame(line l) {
    return areParallel(l) && onLine(l.a) && l.onLine(a);
  }
};
bool areIntersect(line l1, line l2, point & res) {
  if (l1.areParallel(l2)) return 0;
  LD ls = (l2.a  - l1.a) % l2.ab, rs = l1.ab % l2.ab;
  res = l1.a + l1.ab * ls/rs;
  return 1;
}

//CIRCLE AND TRIANGLE
vector<point> interCircle(point o1, LD r1, point o2, LD r2) {
  LD d2 = (o1 - o2).norm_sq();
  LD d = sqrt(d2);
  if (d < fabs(r1-r2)) return {};
  if (d > r1+r2) return {};
  point u = (o1+o2) * 0.5 + (o1-o2)*((r2*r2-r1*r1)/(2*d2));
  LD A = sqrt((r1+r2+d) * (r1-r2+d) * (r1+r2-d) * (-r1+r2+d));
  point v = point(o1.y-o2.y, -o1.x+o2.x) * (A / (2*d2));
  return {u+v, u-v};
}
// Heron's formula
LD heron(LD a, LD b, LD c) {
  LD s = (a + b + c) * 0.5;
  return sqrt(s * (s - a)) * sqrt((s-b) * (s-c));
}
// area by cross
LD areaTriangle(point a, point b, point c) {
  return fabs((a-b) % (c-b)) * 0.5;
}
LD rInCircle(double ab, double bc, double ca) {
  return heron(ab, bc, ca) / (0.5 * (ab + bc + ca));
}
LD rInCircle(point a, point b, point c) {
  return rInCircle(dist(a, b), dist(b, c), dist(c, a));
}

LD rCircumCircle(double ab, double bc, double ca) {// = BC / 2 sin(<ABC)
  return ab * bc * ca / (4.0 * heron(ab, bc, ca));
}
LD rCircumCircle(point a, point b, point c) {
  return rCircumCircle(dist(a, b), dist(b, c), dist(c, a));
}

point inCenter(point &A, point &B, point &C) { // 内心
  LD a = (B-C).norm(), b = (C-A).norm(), c = (A-B).norm();
  return (A * a + B * b + C * c) / (a + b + c);
}
point circumCenter(point &a, point &b, point &c) { // 外心
  point bb = b - a, cc = c - a;
  LD db = (bb).norm_sq(), dc = (cc).norm_sq(), d= 2*(bb % cc);
  return a-point(bb.y*dc-cc.y*db, cc.x*db-bb.x*dc) / d;
}
point othroCenter(point &a, point &b, point &c) { // 垂心
  point ba = b - a, ca = c - a, bc = b - c;
  LD y = ba.y * ca.y * bc.y,
    A = ca.x * ba.y - ba.x * ca.y,
    x0= (y+ca.x*ba.y*b.x-ba.x*ca.y*c.x) / A,
    y0= -ba.x * (x0 - c.x) / ba.y + ca.y;
  return point(x0, y0);
}

point perp(const point& p) {
  return point(p.y, -p.x);
}
vector<pair<point, point> > tangent2Circle(point o1, double r1, point o2, double r2){
  vector<pair<point, point> > ret;
  LD d_sq = (o1 - o2).norm_sq();
  if( d_sq < EPS ) return ret;
  LD d = sqrt( d_sq );
  point v = ( o2 - o1 ) / d;
  for( int sign1 = 1 ; sign1 >= -1 ; sign1 -= 2 ){
    LD c = ( r1 - sign1 * r2 ) / d;
    if( c * c > 1 ) continue;
    LD h = sqrt(max( (LD)0.0 , 1.0 - c * c ) );
    for( int sign2 = 1 ; sign2 >= -1 ; sign2 -= 2 ){
      point n;
      n.x = v.x * c - sign2 * h * v.y;
      n.y = v.y * c + sign2 * h * v.x;
      point p1 = o1 + n * r1;
      point p2 = o2 + n * ( r2 * sign1 );
      if( fabs( p1.x - p2.x ) < EPS and
          fabs( p1.y - p2.y ) < EPS )
        p2 = p1 + perp( o2 - o1 );
      ret.push_back( { p1 , p2 } );
    }
  }
  return ret;
}

Geometry:The Great-Circle Distance(SPHERES)
double gcDistance(double plat, double plong, double qlat, double, qlong ,double radius) {
  plat *= PI/180; plong *= PI/180;
  qlat *= PI/180; qlong *= PI/180;
  return radius * acos(
                   cos(plat)*cos(plong)*cos(qlat)*cos(qlong) +
                   cos(plat)*sin(plong)*cos(qlat)*sin(qlong) +
                   sin(plat)*sin(qlat));
}
Geometry: Polygon
// (Polygon)
double area(const vector< point > & P) {
  double result = 0.0;
  for(int i = 0; i+1 < (int)P.size(); ++i) {
    result += P[i] % P[i+1]; // cross(P[i], P[i+1]);
  }
  return fabs(result)/2.0;
}

// check if point p inside (CONVEX/CONCAVE) polygon vp
// 0 on boundary, -1 inside, 1 outside
int pointVsPolygon(point p, const vector< point >& vp) {
  int wn = 0, n = (int)vp.size() - 1;
  for(int i = 0; i < n; i++) {
    int cs = ccw(vp[i+1], vp[i], p);
    if(cs == 0 && (vp[i+1]-p) * (vp[i]-p) <= 0)
      return 0; // between(vp[i], p, vp[i+1])
    if(vp[i].y <= p.y) {
      if(vp[i+1].y > p.y && cs > 0)
        wn++;
    }
    else {
      if(vp[i+1].y <= p.y && cs < 0)
        wn--;
    }
  }
  return wn == 0 ? 1 : -1;
}

// line segment p-q intersect with line A-B
point lineIntersectSeg(point p, point q, point A, point B) {
  double a = B.y - A.y;
  double b = A.x - B.x;
  double c = B.x * A.y - A.x * B.y;
  double u = fabs(a * p.x + b * p.y + c);
  double v = fabs(a * q.x + b * q.y + c);
  return point((p.x*v + q.x*u)/(u+v), (p.y*v + q.y*u)/(u+v));
}
// cuts polygon Q along the line formed by point a-> point b
// (note: the last point must be the same as the first point)
vector<point> cutPolygon(point a, point b, vector<point> Q) {
  vector<point> P;
  for(int i = 0; i<(int)Q.size(); i++) {
    double left1 = (b - a) % (Q[i] - a), left2 = 0.0;
    if(i != (int)Q.size()-1) left2 = (b - a) % (Q[i+1] - a);
    if(left1 > -EPS) P.push_back(Q[i]);
    if(left1 * left2 < -EPS)
        P.push_back(lineIntersectSeg(Q[i], Q[i+1], a, b));
    }

    if(P.empty()) return P;
    if(!(P.front() == P.back()))
        P.push_back(P.front());y
    return P;
}

Geometry: Convex hull
// Graham’s Scan Algorithm
// need implement operator<,-,cross,ccw on Point’s library
double dist2(point a, point b) {// norm_sq(b - a)
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
point pivot;
bool angle_cmp(point a, point b) {
  if(ccw(pivot, a, b) == 0)
    return dist2(a, pivot) < dist2(b, pivot);
  return ccw(pivot, a, b) > 0;
}

// hasil convexHull tidak siklik(P[0] != P.back())
void convexHull(vector<point> & P) {
  int i, j, n = (int) P.size();
  if(n < 3) {
    return;
  }
  int PO = 0;
  for(i = 1; i < n; i++) {
    if(P[i] < P[PO]) {
      PO = i;
    }
  }
  swap(P[0], P[PO]);
  pivot = P[0];
  sort(++P.begin(), P.end(), angle_cmp);
  // if point on boundary is included then uncomment this:
  // int k = (int)P.size()-1; while (k-1 > 0 && ccw(P[0], P[k-1], P.back()) == 0) k--;
  // reverse(P.begin() + k, P.end());
  vector<point> S;
  S.push_back(P[0]);
  S.push_back(P[1]);
  i = 2;
  while(i < n) {
    j = (int) S.size() - 1;
    // if point on boundary is included then ccw >= 0
    if(j < 1 || ccw(S[j-1], S[j], P[i]) > 0) S.push_back(P[i++]);
    else S.pop_back();
  }
  P = S;
}
Convex Hull Trick Dynamic
const ll is_query = -(1LL<<62);
struct Line {
    ll m, b;
    mutable function<const Line*()> succ;
    bool operator<(const Line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m; // min: reverse it
        const Line* s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x; // min: reverse it
    }
};
struct HullDynamic : public multiset<Line> { // will maintain upper hull for maximum
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b; // min: reverse it
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b; // min: reverse it
        return (x->b - y->b)*(z->m - y->m) >= (y->b - z->b)*(y->m - x->m); // beware overflow!
    }
    void insert_line(ll m, ll b) {
        auto y = insert({ m, b });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    ll eval(ll x) {
        auto l = *lower_bound((Line) { x, is_query });
        return l.m * x + l.b;
    }
};
