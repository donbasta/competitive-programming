#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    ll n, k;
    cin >> n >> k;
    vector<ll> ar(n), br(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        br[i] = ar[i] - k;
    }
    if (*min_element(ar.begin(), ar.end()) == *max_element(ar.begin(), ar.end())) {
        cout << 0 << '\n';
        return;
    }
    ll fpb = 0;
    int pos = 0, neg = 0;
    for (int i = 0; i < n; i++) {
        if (br[i] == 0) {
            cout << -1 << '\n';
            return;
        }
        if (br[i] > 0) pos++;
        if (br[i] < 0) neg++;
        fpb = __gcd(fpb, br[i]);
    }
    if (neg > 0 && pos > 0) {
        cout << -1 << '\n';
        return;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (br[i] / fpb) - 1;
    }
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