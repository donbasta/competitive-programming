#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<pair<int, int>> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i].first;
        c[i].second = i;
    }
    sort(c.begin(), c.end());
    int cur = n - 1;
    int nw = n - 1;
    ll ans = 0;

    vector<bool> ada(n);

    int comp = 0;
    auto add = [&](int x) -> void {
        bool no_left = ((x == 0) || ((x > 0) && !ada[x - 1]));
        bool no_right = ((x == n - 1) || ((x < n - 1) && !ada[x + 1]));
        if (no_left && no_right) comp++;
        if (!no_left && !no_right) comp--;
        ada[x] = true;
    };

    while (cur >= 0) {
        while (nw >= 1 && (c[nw].first == c[nw - 1].first)) {
            add(c[nw].second);
            nw--;
        }
        add(c[nw].second);
        int nx = (nw == 0 ? 0 : c[nw - 1].first);
        ans += 1ll * comp * (c[cur].first - nx);
        cur = nw - 1;
        nw = cur;
    }
    cout << (ans - 1) << '\n';
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