#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    ll n, s, k;
    cin >> n >> s >> k;
    ll tot = 0;
    for (int i = 0; i < n; i++) {
        ll p, q;
        cin >> p >> q;
        tot += p * q;
    }
    if (tot < s) tot += k;
    cout << tot << '\n';
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