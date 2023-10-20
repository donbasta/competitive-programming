#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    vector<string> lol;

    auto buang_range = [&](int x, int y) {
        vector<string> ret;
        for (int i = 0; i < x; i++) ret.push_back(lol[i]);
        for (int i = y + 1; i < (int)lol.size(); i++) ret.push_back(lol[i]);
        lol = ret;
    };

    auto buang_dua = [&](int x, int y) {
        vector<string> ret;
        for (int i = 0; i < (int)lol.size(); i++) {
            if (i == x || i == y) continue;
            ret.push_back(lol[i]);
        }
        lol = ret;
    };

    const function<void(int)> process = [&](int l) {
        int sz = lol.size();
        if (sz <= 3) {
            return;
        }
        int mx = -1;
        for (int i = sz - 1; i >= max(3, sz - l); i--) {
            if (lol[i][0] == lol[i - 3][0]) {
                buang_range(i - 3, i);
                process(sz - i - 1);
                return;
            } else if (lol[i][1] == lol[i - 3][1]) {
                mx = max(mx, i);
            }
        }
        if (mx != -1) {
            buang_dua(mx - 3, mx);
            process(sz - mx + 1);
        }
        return;
    };

    for (int i = 0; i < 52; i++) {
        string c;
        cin >> c;
        lol.push_back(c);
        process(1);
    }
    cout << lol.size() << ' ';
    for (auto e : lol) {
        cout << e << ' ';
    }
    cout << '\n';
    return;
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