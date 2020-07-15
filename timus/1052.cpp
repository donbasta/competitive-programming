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

struct line {
	double a,b,c;
};

void pointsToLine(point p1, point p2, line &l){
	if(fabs(p1.x-p2.x) < EPS) {
		l.a = 1.0; ; l.b = 0.0; l.c = -p1.x;
	} else {
		l.a = -(double) (p1.y-p2.y)/(p1.x-p2.x);
		l.b = 1.0;
		l.c = -(double) (l.a*p1.x) - p1.y; 
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	cout.tie(NULL);
	
	point
	int n;
	cin >> n;
	point t[205];
	line l;
	for(int i=1; i<=n; i++){
		cin >> t[i].x >> t[i].y;
	}
	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			
		}
	}



}