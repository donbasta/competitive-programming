#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve(int tc) {
    ll x, y;
    cin >> x >> y;
    ll gcd = __gcd(x, y);
    ll lcm = (x * y) / gcd;
    ll second_lcm = (lcm * 2);
    ll second_gcd = -1;
    if (gcd > 1) {
        ll d = -1;
        for (ll i = 2; i * i <= gcd; i++) {
            if (gcd % i == 0) {
                d = i;
                break;
            }
        }
        if (d == -1) {
            d = gcd;
        }
        second_gcd = gcd / d;
    }
    cout << "Case #" << tc << ": " << second_gcd << ' ' << second_lcm << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve(i);
    }

    return 0;
}