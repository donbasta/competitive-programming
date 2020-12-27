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
#define endl "\n"

struct Point {double x,y;};

double dist(Point a, Point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	cout.tie(NULL);

	int n;
	double R;
	cin>>n>>R;
	Point t[n+5];
	for(int i=0; i<n; i++){
		cin>>t[i].x>>t[i].y;
	}
	double ans = acos(-1)*2*R;
	for(int i=0; i<n; i++){
		ans += dist(t[i],t[(i+1)%n]);
	}
	cout << fixed << setprecision(2) << ans << endl;
	
}