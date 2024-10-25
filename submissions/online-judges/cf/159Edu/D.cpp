#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

map<char, int> mx = {{'U', 0}, {'D', 0}, {'L', -1}, {'R', 1}};
map<char, int> my = {{'U', 1}, {'D', -1}, {'L', 0}, {'R', 0}};

pair<int, int> add(pair<int, int> x, pair<int, int> y) {
    return make_pair(x.first + y.first, x.second + y.second);
}

pair<int, int> sub(pair<int, int> x, pair<int, int> y) {
    return make_pair(x.first - y.first, x.second - y.second);
}

void el_psy_congroo() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int cx = 0, cy = 0;
    map<pair<int, int>, vector<int>> p1, p2;
    vector<pair<int, int>> pre(n + 2), suf(n + 2);
    pre[0] = make_pair(cx, cy);
    p1[make_pair(cx, cy)].push_back(0);
    for (int i = 1; i <= n; i++) {
        cx += mx[s[i - 1]], cy += my[s[i - 1]];
        pre[i] = make_pair(cx, cy);
        p1[make_pair(cx, cy)].push_back(i);
    }
    cx = 0, cy = 0;
    suf[n + 1] = make_pair(cx, cy);
    p2[make_pair(cx, cy)].push_back(0);
    for (int i = n; i >= 1; i--) {
        cx += mx[s[i - 1]], cy += my[s[i - 1]];
        suf[i] = make_pair(cx, cy);
        p2[make_pair(cx, cy)].push_back(i);
    }
    for (auto& e : p2) {
        reverse(e.second.begin(), e.second.end());
    }

    auto ada1 = [&](pair<int, int> pt, int i1, int i2) -> bool {
        if (!p1.count(pt)) return false;
        vector<int> tmp = p1[pt];
        int x = lower_bound(p1[pt].begin(), p1[pt].end(), i1) - p1[pt].begin();
        int y = upper_bound(p1[pt].begin(), p1[pt].end(), i2) - p1[pt].begin();
        return x < y;
    };

    auto ada2 = [&](pair<int, int> pt, int i1, int i2) -> bool {
        if (!p2.count(pt)) return false;
        int x = lower_bound(p2[pt].begin(), p2[pt].end(), i1) - p2[pt].begin();
        int y = upper_bound(p2[pt].begin(), p2[pt].end(), i2) - p2[pt].begin();
        return x < y;
    };

    while (q--) {
        int x, y, l, r;
        cin >> x >> y >> l >> r;
        pair<int, int> lmao = make_pair(x, y);
        if (ada1(make_pair(x, y), 0, l - 1)) {
            cout << "YES" << '\n';
            continue;
        }
        pair<int, int> cur = pre[l - 1];
        if (ada2(sub(add(lmao, suf[r + 1]), cur), l, r)) {
            cout << "YES" << '\n';
            continue;
        }
        cur = sub(add(cur, suf[l]), suf[r + 1]);
        if (r + 1 <= n && ada1(sub(add(lmao, pre[r]), cur), r + 1, n)) {
            cout << "YES" << '\n';
            continue;
        }
        cout << "NO" << '\n';
    }
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