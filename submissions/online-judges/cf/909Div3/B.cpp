#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<ll> ve(n), pre(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
        pre[i] = (ve[i] + ((i > 0) ? pre[i - 1] : 0));
    }
    ll ans = 0;

    auto range_sum = [&](int a, int b) -> ll {
        return pre[b] - (a ? pre[a - 1] : 0);
    };

    auto get = [&](int k) -> ll {
        vector<ll> tmp;
        for (int i = 0; i < n / k; i++) {
            tmp.push_back(range_sum(i * k, (i + 1) * k - 1));
        }
        ll mx = *max_element(tmp.begin(), tmp.end());
        ll mn = *min_element(tmp.begin(), tmp.end());
        return mx - mn;
    };

    for (int i = 1; i * i <= n; i++) {
        if (n % i != 0) continue;
        ans = max(ans, get(i));
        if (i * i != n) ans = max(ans, get(n / i));
    }
    cout << ans << '\n';
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