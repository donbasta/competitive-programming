#include <bits/stdc++.h>
using namespace std;

const int N = 305;

inline bool eq(long long a, long long b) { return a == b; }
inline int sgn(long long x) { return eq(x, 0) ? 0 : (x < 0 ? -1 : 1); }

struct point {
	long long x,y;
	point(long long _x = 0, long long _y = 0) : x(_x), y(_y) {}
	point operator-(const point& p) const { return point(x-p.x, y-p.y); }
	long long operator%(const point& p) const { return x*p.y - y*p.x; }
	bool operator<(const point& p) const { return eq(y, p.y) ? x < p.x : y < p.y; }
};

int ccw(point a, point b, point c) { return sgn((b-a) % (c-b)); }

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

int n;
int dp[N][N][N];
int dp2[N][N];
int dp3[N];
vector<point> pt;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i++) {
		long long x, y;
		cin >> x >> y;
		pt.emplace_back(x, y);
	}

	for(int i = 0; i < n; i++) {
		vector<pair<point, int>> pts;
		for(int j = 0; j < n; j++) {
			if (i == j)
				continue;
			pts.emplace_back(pt[j] - pt[i], j);
		}
		sortCircular(pts);

		int r = 1, cur = 1;
		int sz = (int) pts.size();
		for(int j = 0; j < sz ; j++){
			cur--;
			if(pts[j].second == pts[r].second){
				r = (r + 1) % sz;
				cur++;
			}
			while(sgn(pts[r].first % pts[j].first) < 0) {
				r = (r + 1) % sz;
				cur++;
			}
			dp2[i][pts[j].second] = cur;
		}
		for(int j = 0; j < sz; j++) {
			r = (j + 1) % sz;
			cur = 0;
			while(sgn(pts[j].first % pts[r].first) > 0){
				dp[i][pts[j].second][pts[r].second] = cur;
				r = (r + 1) % sz;
				cur++;
			}
		}
	}

	// for()

	// for(int i = 0; i < n; i++){
	// 	for(int j = 0; j < n; j++){
	// 		for(int k = 0; k < n; k ++){
	// 			if(ccw(pt[i], pt[j], pt[k]) != 1){
	// 				// cerr << "lol-";
	// 				assert(dp[i][j][k] == 0);
	// 			}
	// 			else
	// 				cerr << i << " " << j <<  " " << k << " " << dp[i][j][k] << "\n";
	// 		}
	// 	}
	// }

	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			for(int k = j+1; k < n; k++) {
				int banyak1 = 0, banyak2 = 0, temp = 0;
				if(ccw(pt[i], pt[j], pt[k]) == 1){
					banyak1 += dp[j][k][i] + dp[k][i][j] + dp[i][j][k];
					banyak2 += dp2[j][i] + dp2[i][k] + dp2[k][j]; 
				} else {	
					banyak1 += dp[j][i][k] + dp[i][k][j] + dp[k][j][i];
					banyak2 += dp2[i][j] + dp2[j][k] + dp2[k][i];
				}
				// cerr << 
				temp = banyak1 + banyak2 - 2 * (n - 3);
				assert(temp >= 0 && temp <= n - 3);
				// cerr << i << " " << j << " ";
				// cerr << banyak1 << " " << banyak2 << " " << k << " " << temp << " uwu \n";
				dp3[temp]++;
			}
		}
	}

	// for(int i = 0; i<=n; i++) {
	// 	cerr << dp3[i] << " - ";
	// }
	// cerr << "\n";

	long long ans = n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 120;
	for(int i = 0; i <= n-3; i++){
		ans -= 1LL * i * dp3[i] * (n - 4) / 2;
		ans += 1LL * i * (i - 1) * dp3[i] / 2;
	}

	cout << ans << "\n";
	return 0;
}

// 7
// 0 0
// 0 5
// 5 0
// 5 5
// 1 3
// 4 3
// 3 2
