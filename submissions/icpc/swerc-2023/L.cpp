#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll pos = 0, neg = 0;
    for (auto c : s) {
        if (c == '+')
            pos++;
        else
            neg++;
    }
    int q;
    cin >> q;
    while (q--) {
        ll a, b;
        cin >> a >> b;
        if (pos == neg) {
            cout << "YES" << '\n';
            continue;
        }
        if (a == b) {
            if (pos == neg) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
            continue;
        }
        ll d = __gcd(a, b);
        ll a1 = a / d;
        ll b1 = b / d;
        if (abs(pos - neg) % abs(a1 - b1) != 0) {
            cout << "NO" << '\n';
            continue;
        }
        ll x = abs(pos - neg) / abs(a1 - b1);
        ll sgn1 = (pos - neg) / abs(pos - neg);
        ll sgn2 = (b1 - a1) / abs(a1 - b1);
        if (sgn1 == sgn2) {
            bool cek1 = pos >= (b1 * x);
            bool cek2 = neg >= (a1 * x);
            if (cek1 && cek2) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        } else {
            bool cek1 = pos >= (a1 * x);
            bool cek2 = neg >= (b1 * x);
            if (cek1 && cek2) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }
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