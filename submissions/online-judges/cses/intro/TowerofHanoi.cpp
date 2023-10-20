#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

vector<pair<int, int>> generate_moves(int n, int s, int m, int e) {
    vector<pair<int, int>> ret;
    if (n == 1) {
        ret.push_back(make_pair(s, e));
        return ret;
    }
    vector<pair<int, int>> L = generate_moves(n - 1, s, e, m);
    for (auto e : L) ret.push_back(e);
    ret.push_back(make_pair(s, e));
    vector<pair<int, int>> R = generate_moves(n - 1, m, s, e);
    for (auto e : R) ret.push_back(e);
    return ret;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> ans = generate_moves(n, 1, 2, 3);
    cout << ans.size() << '\n';
    for (auto e : ans) {
        cout << e.first << ' ' << e.second << '\n';
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