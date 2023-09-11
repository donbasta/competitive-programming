#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int x;
    cin >> x;
    vector<int> pos;
    for (int i = 30; i >= 0; i--) {
        if (x >= (1 << i)) {
            x -= (1 << i);
            pos.push_back(i);
        }
    }
    reverse(pos.begin(), pos.end());
    vector<int> res;
    for (int i = 0; i <= pos.back(); i++) {
        res.push_back(1 << i);
    }
    int tot = (1 << pos.back());
    for (int i = pos.size() - 2; i >= 0; i--) {
        tot += (1 << pos[i]);
        res.push_back(tot);
    }
    reverse(res.begin(), res.end());
    cout << res.size() << '\n';
    for (auto e : res) {
        cout << e << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}