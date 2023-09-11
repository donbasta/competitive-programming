#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<ll> val = {1, 10, 100, 1000, 10000};

    ll sum = 0;
    ll mx = 0;
    vector<vector<ll>> ve(5, vector<ll>(5));
    for (int i = n - 1; i >= 0; i--) {
        ll dig = s[i] - 'A';
        ve[dig][mx]++;
        if (dig >= mx) {
            sum += val[dig];
        } else {
            sum -= val[dig];
        }
        mx = max(mx, dig);
    }
    ll ret = -INF;
    mx = 0;
    for (int i = n - 1; i >= 0; i--) {
        ll dig = s[i] - 'A';
        ve[dig][mx]--;
        for (int j = 0; j < 5; j++) {
            // change dig to j
            ll tmp = sum;
            if (dig < mx)
                tmp += val[dig];
            else
                tmp -= val[dig];
            if (j >= mx)
                tmp += val[j];
            else
                tmp -= val[j];
            for (int k = 0; k < 5; k++) {
                for (int l = 0; l < 5; l++) {
                    if (l <= k)
                        tmp -= ve[k][l] * val[k];
                    else
                        tmp += ve[k][l] * val[k];
                    if (j <= k && l <= k)
                        tmp += ve[k][l] * val[k];
                    else
                        tmp -= ve[k][l] * val[k];
                }
            }
            cout << i << ' ' << j << ' ' << tmp << '\n';
            ret = max(ret, tmp);
        }
        mx = max(mx, dig);
    }
    cout << ret << '\n';
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