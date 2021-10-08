using ll = long long;

inline bool eq(ll a, ll b) { return a == b; }
inline bool lt(ll a, ll b) { return a < b; }
inline bool le(ll a, ll b) { return a <= b; }
inline int sgn(ll x) { return eq(x, 0) ? 0 : (x < 0 ? -1 : 1); }

inline bool eq(LD a, LD b) { return fabs(a-b) < EPS; }
inline bool lt(LD a, LD b) { return a + EPS < b; }
inline bool le(LD a, LD b) { return a < b + EPS; }
inline int sign(LD x) { return eq(x, 0) ? 0 : (x < 0 ? -1 : 1); }

struct point {
	ll x,y;
	point(ll _x = 0, ll _y = 0) : x(_x), y(_y) {}
	point operator+(const point& p) const { return point(x + p.x, y + p.y); }
	point operator-(const point& p) const { return point(x - p.x, y - p.y); }
	point operator*(ll t) { return point(x * t, y * t); }
	point operator/(ll t) { return point(x / t, y / t); }
	ll operator*(const point& p) const { return x * p.x + y * p.y; }
	ll operator%(const point& p) const { return x * p.y - y * p.x; }
	ll squared_norm() { return (*this) * (*this); }
	bool operator==(const point& p) const { return eq(x, p.x) && eq(y, p.y); }
	bool operator<(const point& p) const { return eq(y, p.y) ? x < p.x : y < p.y; }
}


ostream& operator<<(ostream& os, point p) {
	return os << "(" << p.x << ", " << p.y << ")";
}

//a-b-c: -1 clockwise, 0 collinear, 1 counterclockwise
int ccw(point a, point b, point c) { return sign((b - a) % (c - b)); }

//sorting point in points from 1st quadrant to 4th quadrant
void sortCircular(vector<pair<point, int>> &points) {
	vector<pair<point, int>> upper, lower;
	for(auto& e : points) {
		if(point() < e.first)
			upper.push_back(e);
		else
			lower.push_back(e);
	}
	auto cmp = [](pair<point, int> a, pair<point, int> b) {
		int dir = sgn(a.first % b.first);
		if (dir == 0)
			return a.second < b.second;
		return dir > 0;
	};
	sort(upper.begin(), upper.end(), cmp);
	sort(lower.begin(), lower.end(), cmp);
	for(int i = 0; i < (int) upper.size(); i++)
		points[i] = upper[i];
	for(int i = 0; i < (int) lower.size(); i++)
		points[i + upper.size()] = lower[i];
}