#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int K = 20;

struct SparseTable {
    vector<vector<pair<int, int>>> table;
    int n;
    SparseTable(const vector<int>& ar) : n(ar.size()) {
        table.resize(K + 1);
        for (auto& v : table) v.resize(n + 5);
        for (int i = 0; i < n; i++) {
            table[0][i] = make_pair(ar[i], i);
        }
        for (int i = 1; i <= K; i++) {
            for (int j = 0; (j + (1 << i)) <= n; j++) {
                auto x = table[i - 1][j];
                auto y = table[i - 1][j + (1 << (i - 1))];
                table[i][j] = max(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    int bit_width(int x) {
        if (x == 0) return 0;
        int ret = 0;
        while (x) {
            x >>= 1, ret++;
        }
        return ret;
    }
    pair<int, int> get(int l, int r) {
        if (r < l) return make_pair(-1, -1);
        int i = bit_width(r - l + 1) - 1;
        return max(table[i][l], table[i][r - (1 << i) + 1]);
    }
};

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    SparseTable st(ar);

    ll ans = 0;
    const function<void(int, int)> solve = [&](int l, int r) {
        if (r - l <= 1) return;
        ans += min(ar[l], ar[r]);
        if (r - l == 2) return;
        pair<int, int> x = st.get(l, r);
        pair<int, int> y = st.get(l, x.second - 1);
        pair<int, int> yy = st.get(l, x.second - 2);
        pair<int, int> z = st.get(x.second + 1, r);
        pair<int, int> zz = st.get(x.second + 2, r);

        int ki = y.second, ka = z.second;
        if (y.second == x.second - 1) {
                }

        solve(l, p);
        solve(p, q);
        solve(q, r);
    };

    solve(0, n - 1);
    cout << ans << '\n';
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