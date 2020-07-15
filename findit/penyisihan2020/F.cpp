#include <bits/stdc++.h>

using namespace std;

const int N = 25;
const int NMax = 14005;

int n, m;
int x, y, z;

struct st {
	int p, q, r, s;
};

st a[N];
vector<st> k;
vector<st> dp[NMax];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	cin >> x >> y >> z;
	for (int i = 1; i <= n; i++) {
		int p, q, r, s;
		cin >> p >> q >> r >> s;
		for (int j = 1; j <= m; j++) {
			if (q * j <= x && r * j <= y && s * j <= z) {
				k.push_back({p * j, q * j, r * j, s * j});
			}
		}
	}
	if (m == 1) {
		int ans = 0;
		for (auto e : k) {
			ans = max(ans, e.p);
		}
		cout << ans << '\n';
		return 0;
	}
	for (int i = 1; i < NMax; i++) {
		for (auto e : k) {
			if (i == e.p) {
				dp[i].push_back(e);
			} else if (i > e.p) {
				int j = i - e.p;
				for (auto el : dp[j]) {
					if (el.q + e.q <= x && el.r + e.r <= y && el.s + e.s <= z) {
						dp[i].push_back({0, el.q + e.q, el.r + e.r, el.s + e.s});
					}
				}
			}
		}
	}

	for (int i = NMax - 1; i >= 1; i--) {
		if (dp[i].size() > 0) {
			cout << i << '\n';
			return 0;
		}
	}
	
	cout << 0 << '\n';

	return 0;
}