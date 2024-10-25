#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> ve;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ve.emplace_back(a, b);
    }
    sort(ve.begin(), ve.end());
    int cov = 0;
    int st = -1, en = -1;
    for (int i = 0; i < n; i++) {
        if (ve[i].first > cov + 1) {
            st = cov + 1;
            break;
        } else {
            cov = max(cov, ve[i].second);
        }
    }
    if (cov >= m) {
        cout << 0 << '\n';
        return;
    }
    if (st == -1) {
        st = cov + 1;
    }
    sort(ve.begin(), ve.end(), [&](auto x, auto y) -> bool {
        return x.second < y.second;
    });
    cov = m + 1;
    for (int i = n - 1; i >= 0; i--) {
        if (ve[i].second < cov - 1) {
            en = cov - 1;
            break;
        } else {
            cov = min(cov, ve[i].first);
        }
    }
    assert(cov > 1);
    if (en == -1) {
        en = cov - 1;
    }

    cout << (en - st + 1) << '\n';
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