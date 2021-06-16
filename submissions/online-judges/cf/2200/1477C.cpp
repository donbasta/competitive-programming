#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define pll pair<ll, ll>
#define x first
#define y second

int n;
vector<pll> points;

inline ll dist(pll a, pll b) {
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll xx, yy;
        cin >> xx >> yy;
        points.emplace_back(xx, yy);
    }
    vector<int> p(n, -1);
    vector<bool> udah(n, false);
    p[0] = 0;
    udah[0] = true;
    int now = 0;
    for (int i = 1; i < n; i++) {
        ll tmp = -1;
        ll idx = -1;
        for (int j = 0; j < n; j++) {
            if (udah[j]) continue;
            ll cur = dist(points[now], points[j]);
            if (cur > tmp) {
                tmp = cur;
                idx = j;
            }
        }
        udah[idx] = true;
        p[i] = idx;
        now = idx;
    }
    for (auto& e : p) {
        cout << e + 1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}