#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(b.begin(), b.end(), greater<>());

    unordered_map<int, int> ump, ump_rev;
    vector<int> unq;
    for (auto e : a) unq.push_back(e);
    sort(unq.begin(), unq.end());
    unq.resize(unique(unq.begin(), unq.end()) - unq.begin());
    int sz = unq.size();
    for (int i = 0; i < sz; i++) {
        ump[unq[i]] = i;
        ump_rev[unq[i]] = sz - 1 - i;
    }
    vector<int> bit(sz + 1);
    const function<void(int, int)> upd = [&](int x, int v) {
        x++;
        while (x <= sz) {
            bit[x] = max(bit[x], v);
            x += x & -x;
        }
    };
    const function<int(int)> get = [&](int x) -> int {
        x++;
        int ret = 0;
        while (x > 0) {
            ret = max(ret, bit[x]);
            x -= x & -x;
        }
        return ret;
    };

    vector<int> dp(n), dp_rev(n);
    for (int i = 0; i < n; i++) {
        int prv = get(ump[a[i]] - 1);
        dp[i] = prv + 1;
        upd(ump[a[i]], dp[i]);
    }
    bit.assign(sz + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        int prv = get(ump_rev[a[i]] - 1);
        dp_rev[i] = prv + 1;
        upd(ump_rev[a[i]], dp_rev[i]);
    }

    int lis = *max_element(dp.begin(), dp.end());
    assert(lis == *max_element(dp_rev.begin(), dp_rev.end()));
    int mn_right_lis = INF;
    int mx_left_lis = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] == lis) {
            mn_right_lis = min(mn_right_lis, a[i]);
        }
        if (dp_rev[i] == lis) {
            mx_left_lis = max(mx_left_lis, a[i]);
        }
    }
    int ptr = 0;
    vector<int> ret;
    vector<int> pivots;
    for (int i = 0; i < n; i++) {
        if (dp_rev[i] == lis) {
            pivots.push_back(i);
        }
    }
    while (ptr < m && b[ptr] >= a[pivots[0]]) {
        ret.push_back(b[ptr]);
        ptr++;
    }
    int ptr_pivot = 0;
    for (int i = 0; i < n; i++) {
        ret.push_back(a[i]);
        if (i == pivots[ptr_pivot] && i != pivots.back()) {
            while (ptr < m && b[ptr] >= a[pivots[ptr_pivot + 1]]) {
                ret.push_back(b[ptr]);
                ptr++;
            }
            ptr_pivot++;
        }
    }
    while (ptr < m) ret.push_back(b[ptr++]);

    for (auto e : ret) {
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
        el_psy_congroo();
    }

    return 0;
}