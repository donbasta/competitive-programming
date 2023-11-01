#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<ll> ar(n), cnt(n + 1), div(n + 1), mul(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        cnt[ar[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            div[j] += cnt[i];
            mul[i] += cnt[j];
        }
    }
    vector<ll> fp(n + 1);
    for (int i = n; i >= 1; i--) {
        fp[i] = mul[i] * mul[i];
        for (int j = i * 2; j <= n; j += i) {
            fp[i] -= fp[j];
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (div[i] > 0) continue;
        ans += (fp[i] - cnt[i]) / 2;
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