#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<ll> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    ll last = ar[n - 1];
    ll ans = 0;
    for (int i = n - 2; i >= 0; i--) {
        ll sisa = (ar[i] % last);
        if (sisa == 0) {
            ans += (ar[i] / last) - 1;
        } else {
            ll part = (ar[i] / last) + 1;
            ll tmp = ar[i] / part;
            last = tmp;
            ans += (part - 1);
        }
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