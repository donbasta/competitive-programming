#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

struct BIT {
    vector<int> tree;
    int n;
    BIT(int n) : n(n) {
        tree.resize(n + 1);
    }
    void upd(int x, int val) {
        x++;
        while (x <= n) {
            tree[x] += val;
            x += x & -x;
        }
    }
    int get(int y, int x) {
        int ret = 0;
        for (x++; x; x -= x & -x) ret += tree[x];
        for (; y; y -= y & -y) ret -= tree[y];
        return ret;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    int mx = 1;
    while (mx <= n) mx <<= 1;
    vector<vector<int>> mex_range(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        BIT tmp(n + 1);
        for (int j = i; j < n; j++) {
            int cur = tmp.get(ar[j], ar[j]);
            if (cur == 0) tmp.upd(ar[j], 1);
            int l = 0, r = n;
            int cur_mex = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                int sum = tmp.get(0, mid);
                if (sum == mid + 1) {
                    l = mid + 1;
                } else {
                    cur_mex = mid;
                    r = mid - 1;
                }
            }
            mex_range[i][j] = cur_mex;
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = i; j < n; j++) {
    //         cerr << i << ' ' << j << ' ' << mex_range[i][j] << '\n';
    //     }
    // }
    vector<pair<pair<int, int>, int>> itv;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            itv.emplace_back(make_pair(i, j), mex_range[i][j]);
        }
    }
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