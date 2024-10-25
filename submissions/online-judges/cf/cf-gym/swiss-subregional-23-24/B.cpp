#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = 1e18;
const int N = 1e6;
multiset<ll> probs[N + 1];

void el_psy_congroo() {
    int n;
    cin >> n;

    vector<ll> dp1(2 * N + 5), dp2(2 * N + 5);
    for (int i = 0; i < n; i++) {
        ll t, d, b;
        cin >> t >> d >> b;
        if (t == 1) {
            probs[d].insert(b);
        } else {
            probs[d].erase(probs[d].find(b));
        }
        while (d >= 1) {
            dp1[d] = 0;
            if (!probs[d].empty()) {
                dp1[d] = max(dp1[d], max(dp1[2 * d], dp1[2 * d + 1]) + *probs[d].rbegin());
            }
            dp2[d] = max({dp1[d], dp2[2 * d], dp2[2 * d + 1]});
            d /= 2;
        }
        cout << dp2[1] << '\n';
    }
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