#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    ll n, m, k, a, b;
    cin >> n >> m >> k >> a >> b;
    ll ans = (n / (m * 3));
    ans = min(ans, b / k);
    ans = min(ans, a / (k * 2));
    cout << (ans * 3) << '\n';
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