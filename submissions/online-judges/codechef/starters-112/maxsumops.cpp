#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    ll n, k;
    cin >> n >> k;
    vector<ll> ar(n);
    int cnt_odd = 0;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        // cnt_odd += (ar[i] & 1);
    }
    ll sum = accumulate(ar.begin(), ar.end(), 0ll);
    // if (cnt_odd >= k) {
    //     cout << (sum + k) << '\n';
    //     return;
    // }
    // sum += cnt_odd;
    // k -= cnt_odd;
    // for (auto& e : ar)
    //     if (e & 1) e++;
    vector<ll> tmp(n);
    for (int i = 0; i < n; i++) {
        ll step = 0, cur = ar[i];
        while (cur > 1) {
            if (cur & 1)
                cur++;
            else
                cur /= 2;
            step++;
            if (step == k) {
                tmp[i] = cur;
                break;
            }
        }
        if (step < k) {
            if ((k - step) & 1)
                tmp[i] = 2;
            else
                tmp[i] = 1;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, sum - (ar[i]) + tmp[i]);
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