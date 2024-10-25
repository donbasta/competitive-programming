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
    vector<ll> cp = ar;
    sort(cp.begin(), cp.end());
    vector<ll> suf(n);
    suf[n - 1] = cp[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = (suf[i + 1] + cp[i]);
    }
    for (int i = 0; i < n; i++) {
        int x = upper_bound(cp.begin(), cp.end(), ar[i]) - cp.begin();
        ll ans;
        if (x == n) {
            ans = 0;
        } else {
            ans = suf[x];
        }
        cout << ans << ' ';
    }
    cout << '\n';
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