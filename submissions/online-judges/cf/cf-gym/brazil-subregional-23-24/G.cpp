#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

int ccw(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
    ll dx1 = b.first - a.first;
    ll dy1 = b.second - a.second;
    ll dx2 = c.first - b.first;
    ll dy2 = c.second - b.second;
    ll cr = dx1 * dy2 - dy1 * dx2;
    if (cr < 0)
        return -1;
    else if (cr > 0)
        return 1;
    return 0;
}

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<pair<pair<ll, ll>, int>> pt(n);
    for (int i = 0; i < n; i++) {
        cin >> pt[i].first.first >> pt[i].first.second;
        pt[i].second = i;
    }
    if (n <= 3) {
        for (int i = 1; i <= n; i++) {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }
    sort(pt.begin(), pt.end());
    vector<pair<ll, ll>> hull;
    vector<int> idx;
    set<int> vert;
    {
        idx.push_back(pt[0].second);
        idx.push_back(pt[1].second);
        hull.push_back(pt[0].first);
        hull.push_back(pt[1].first);
        for (int i = 2; i < n; i++) {
            while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), pt[i].first) == 1) {
                idx.pop_back();
                hull.pop_back();
            }
            hull.push_back(pt[i].first);
            idx.push_back(pt[i].second);
        }
        for (auto c : idx) vert.insert(c);
    }
    idx.clear(), hull.clear();
    {
        idx.push_back(pt[0].second);
        idx.push_back(pt[1].second);
        hull.push_back(pt[0].first);
        hull.push_back(pt[1].first);
        for (int i = 2; i < n; i++) {
            while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), pt[i].first) == -1) {
                idx.pop_back();
                hull.pop_back();
            }
            hull.push_back(pt[i].first);
            idx.push_back(pt[i].second);
        }
        for (auto c : idx) vert.insert(c);
    }
    for (auto c : vert) {
        cout << (c + 1) << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}