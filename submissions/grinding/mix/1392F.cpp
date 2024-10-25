#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    ll n;
    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        sum += x;
    }
    ll temp = sum - n * (n + 1) / 2;
    ll md = temp % n;
    if (md < 0) md += n;
    ll c = (n - md) % n;
    assert((c + temp) % n == 0);
    ll a = (c + temp) / n;
    a++;
    for (int i = 1; i <= n; i++) {
        cout << a << ' ';
        if (i != n - c) a++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}