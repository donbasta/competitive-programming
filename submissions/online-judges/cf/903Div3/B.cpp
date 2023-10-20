#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    vector<ll> ar(3);
    for (int i = 0; i < 3; i++) {
        cin >> ar[i];
    }
    sort(ar.begin(), ar.end());
    ll gcd = __gcd(ar[0], ar[1]);
    gcd = __gcd(gcd, ar[2]);
    for (int i = 0; i < 3; i++) {
        ar[i] /= gcd;
    }
    if (ar == vector<ll>{1, 1, 1}) {
        cout << "YES" << '\n';
        return;
    }
    if (ar == vector<ll>{1, 1, 2}) {
        cout << "YES" << '\n';
        return;
    }
    if (ar == vector<ll>{1, 2, 2}) {
        cout << "YES" << '\n';
        return;
    }
    if (ar == vector<ll>{1, 1, 3}) {
        cout << "YES" << '\n';
        return;
    }
    if (ar == vector<ll>{1, 2, 3}) {
        cout << "YES" << '\n';
        return;
    }
    if (ar == vector<ll>{1, 1, 4}) {
        cout << "YES" << '\n';
        return;
    }
    cout << "NO" << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}