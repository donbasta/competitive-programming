#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    ll n, a, b, d;
    cin >> n >> a >> b >> d;
    ll last = (n / d) * d;
    ll ans = min(b * (n / d), a * last);
    ans += min(a * (n - last), b + a * (last + d - n));
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