#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

// sorting point in points from 1st quadrant to 4th quadrant
void sortCircular(vector<pair<point, int>>& points) {
    vector<pair<point, int>> upper, lower;
    for (auto& e : points) {
        if (point() < e.first)
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
    for (int i = 0; i < (int)upper.size(); i++)
        points[i] = upper[i];
    for (int i = 0; i < (int)lower.size(); i++)
        points[i + upper.size()] = lower[i];
}

void solve() {
    int n;
    cin >> n;
    vector<pair<pair<ll, ll>, int>> ve;
    for (int i = 0; i < n; i++) {
        ll x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ve.emplace_back(make_pair(x1, y1), i);
        ve.emplace_back(make_pair(x2, y2), i);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}