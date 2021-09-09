#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

struct pt { double x, y; };

inline bool cmp(pt a, pt b) { return a.x < b.x || (a.x == b.x && a.y < b.y); }
inline bool cw(pt a, pt b, pt c) { return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0; }
inline bool ccw(pt a, pt b, pt c) { return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0; }

void convex_hull(vector<pt>& a) {
    if (a.size() == 1) return;

    sort(a.begin(), a.end(), &cmp);
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1), down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
}

int n;

void solve() {
    cin >> n;
    vector<pt> ve(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i].x >> ve[i].y;
    }
    convex_hull(ve);
    ld ans = 0;
    int sz = (int)ve.size();
    for (int i = 0; i < sz; i++) {
        int ii = (i + 1) % sz;
        ans += hypot(ve[i].x - ve[ii].x, ve[i].y - ve[ii].y);
    }
    cout << fixed << setprecision(9) << ans << '\n';
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