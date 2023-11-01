#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<ll> ar(n), pre(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    sort(ar.begin(), ar.end());
    for (int i = 0; i < n; i++) {
        pre[i] = (i ? pre[i - 1] : 0ll) + ar[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, ar[i] + 1 - (i ? pre[i - 1] : 0ll));
    }
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