#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define foru(i,a,b) for(int i = (int) a; i < (int) b; i++)
#define ford(i,a,b) for(int i = (int) a; i > (int) b; i--)
#define fors(i,n) for(int i = 0; i < n; i++)
#define fill(a,b) memset(a, (b), sizeof(a))
#define pii pair<int, int>
#define pll pair<long long, long long>

const double EPS 1e-9;


//lattice point
struct point_i{
	int x,y;
	point_i() { x=y=0; }
	point_i(int _x, int _y) : x(_x), y(_y) {}
};

//real two-dimensional point
struct point{
	double x,y;
	point() { x=y=0.0; }
	point(double _x, double _y) : x(_x), y(_y) {}
	bool operator == (point p) const {return (fabs(x-p.x) < EPS && fabs(y-p.y) < EPS);}
	point operator + (point p) {return point(x+p.x,y+p.y);}
	point operator - (point p) {return point(x-p.x,y-p.y);}
	point operator * (double d) {return point(x*d,y*d);}
	point operator / (double d) {return point(x/d,y/d);}

	ostream& operator<<(ostream& os, pt p){
		return os << "(" << p.x << "," << p.y << ")";
	}
};

//line ax+by+c=0
struct line {
	double a,b,c;
};

//vector
struct vec {
	double x,y;
	vec(double _x, double _y) : x(_x), y(_y) {}
	vec operator * (double d) {return vec(v.x*d, v.y*d);}
};

//create vector defined by two points
vec toVec(point a, point b){
	return vec(b.x-a.x, b.y-a.y);
}

//translate a point p by a vector v
point translate(point p, vec v){
	return point(p.x+v.x, p.y+v.y);
}

//calculate dot product of two vectors
double dot(vec a, vec b){
	return (a.x*b.x + a.y*b.y);
}

//calculate squared norm ov a vector
double norm_sq(vec v){
	return dot(v,v);
}

//calculate distance from point p to line defined by points a and b
double distToLine(point p, point a, point b, point &c){
	vec ap = toVec(a,p), ab = toVec(a,b);
	double u = dot(ap,ab) / norm_sq(ab);
	c = translate(a, scale(ab,u));
	return dist(p,c);
}

//calculate angle between three points using dot product
double angle(point a, point o, point b){
	vec oa = toVec(o,a), ob = toVec(o,b);
	return acos(dot(oa,ob)/sqrt(norm_sq(oa)*norm_sq(ob)));
}

//calculate cross product of two vectors
double cross(vec a, vec b){
	return a.x*b.y-a.y*b.x;
}

//decide whether pqr is a counter clockwise turn
bool ccw(point p, point q, point r){
	return cross(toVec(p,q),toVec(p,r)) > 0;
}

//decide whether points p,q,r are collinear
bool collinear(point p, point q, point r){
	return (fabs(cross(toVec(p,q),toVec(p,r))) < EPS);
}

//construct a line determined by two points
void pointsToLine(point p1, point p2, line &l){
	if(fabs(p1.x-p2.x) < EPS) {
		l.a = 1.0; ; l.b = 0.0; l.c = -p1.x;
	} else {
		l.a = -(double) (p1.y-p2.y)/(p1.x-p2.x);
		l.b = 1.0;
		l.c = -(double) (l.a*p1.x) - p1.y; 
	}
}

//decide whether two lines are parallel
bool areParallel(line l1, line l2){
	return (fabs(l1.a-l2.a)<EPS && fabs(l1.b-l2.b)<EPS);
}

//decide whether two lines coincide
bool areSame(line l1, line l2){
	return (areParallel(l1,l2) && (fabs(l1.c-l2.c)<EPS));
}

//find the intersection of two lines if they intersect
bool areIntersect(line l1, line l2, point &p){
	if (areParallel(l1,l2)) return false;
	p.x = (l2.b*l1.c - l1.b*l2.c)/(l2.a*l1.b-l1.a*l2.b);
	if(fabs(l1.b)>EPS) p.y = -(l1.a*p.x+l1.c);
	else p.y = -(l2.a*p.x+l2.c);
	return true;
}

//find distance of two points
double dist(point p1, point p2){
	return hypot(p1.x-p2.x, p1.y-p2.y);
}

//rotate a point p wrt pivot q and angle of rotation theta
point rotate(point p, double theta, point q){
	double rad = DEG_TO_RAD(theta);
	point r = p-q;
	return q + point(r.x*cos(rad)-r.y*cos(rad), r.x*sin(rad)+r.y*cos(rad));
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	cout.tie(NULL);

	
}