
using lint = long long;

inline bool eq(lint a, lint b) { return a == b; }
inline bool lt(lint a, lint b) { return a < b; }
inline bool le(lint a, lint b) { return a <= b; }
inline int sgn(lint x) { return eq(x, 0) ? 0 : (x < 0 ? -1 : 1); }

struct point {
	lint x,y;
	point(lint _x = 0, lint _y = 0) : x(_x), y(_y) {}
	point operator+(const point& p) const { return point(x+p.x, y+p.y); }
	point operator-(const point& p) const { return point(x-p.x, y-p.y); }
	point operator*(lint t) { return point(x*s, y*s); }
	point operator/(lint t) { return point(x/s, y/s); }
	lint operator*(const point& p) const { return x*p.x + y*p.y; }
	lint operator%(const point& p) const { return x*p.y - y*p.x; }
	lint squared_norm() { return *this * *this; }
	bool operator==(const point& p) const { return eq(x, p.x) && eq(y, p.y); }
	bool operator<(const point& p) const { return eq(y, p.y) ? x < p.x : y < p.y; }
}

ostream& operator<<(ostream& os, point p) {
	return os << "(" << p.x << ", " << p.y << ")";
}

//a-b-c: -1 clockwise, 0 colliner, 1 counterclockwise
int ccw(point a, point b, point c) { return sign((b-a) % (c-b)); }

bool cmp(pair<point, int> a, pair<point, int> b) {
	int dir = sgn(a.first % b.first);
	if (dir == 0)
		return a.second < b.second;
	return dir > 0;
}

//sorting point in points from 1st quadrant to 4th quadrant
void sortCircular(vector<pair<point, int>> &points) {
	vector<pair<point, int>> upper, lower;
	for(auto& e : points) {
		if(point() < e.first)
			upper.push_back(e);
		else
			lower.push_back(e);
	}
	sort(upper.begin(), upper.end(), cmp);
	sort(lower.begin(), lower.end(), cmp);
	for(int i = 0; i < (int) upper.size(); i++)
		points[i] = upper[i];
	for(int i = 0; i < (int) lower.size(); i++)
		points[i + upper.size()] = lower[i];
}

