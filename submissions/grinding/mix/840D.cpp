#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;
const int T[] = {-1, -1, 30, 50, 60, 80};

void el_psy_congroo() {
    int n, q;
    cin >> n >> q;
    vector<int> ar(n);
    vector<vector<int>> pos(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        pos[ar[i]].push_back(i);
    }

    auto cnt = [&](int val, int a, int b) -> int {
        int pb = upper_bound(pos[val].begin(), pos[val].end(), b) - pos[val].begin();
        int pa = lower_bound(pos[val].begin(), pos[val].end(), a) - pos[val].begin();
        return pb - pa;
    };

    vector<int> cache(n + 1, -1);
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        --l, --r;
        int ret = INF;
        vector<int> hit;
        for (int i = 0; i < T[k]; i++) {
            int x = ar[(rng() % (r - l + 1)) + l];
            if (cache[x] == -1) {
                cache[x] = cnt(x, l, r);
                hit.push_back(x);
            }
            int count = cache[x];
            if (k * count > (r - l + 1)) {
                ret = min(ret, x);
            }
        }
        if (ret == INF) ret = -1;
        cout << ret << '\n';
        for (auto x : hit) cache[x] = -1;
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