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
    if (n == 1) {
        cout << 1 << '\n';
        return;
    }
    sort(ar.begin(), ar.end());
    ll fpb = 0;
    for (int i = 1; i < n; i++) {
        fpb = __gcd(fpb, ar[i] - ar[0]);
    }
    ll sisa = ar[0] % fpb;
    if (sisa < 0) sisa += fpb;
    for (int i = 0; i < n; i++) {
        ar[i] -= sisa;
        ar[i] /= fpb;
    }
    ll x = ar.back() + 1;
    ll tmp = 0;
    for (int i = 0; i < n; i++) {
        tmp += (x - ar[i]);
    }
    ll ans = tmp;
    x = ar.back() - 1;
    for (int i = n - 2; i >= 0; i--) {
        if (x != ar[i]) break;
        x--;
    }
    tmp = ar.back() - x;
    for (int i = 0; i < n - 1; i++) {
        tmp += ar.back() - ar[i];
    }
    ans = min(ans, tmp);
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