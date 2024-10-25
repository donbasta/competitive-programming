#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> ar(n), F(n + 1), H(n + 1);
    for (int i = 1; i <= n; i++) {
        F[i] = rng();
        H[i] = H[i - 1] ^ F[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    ll ans = 0;
    auto solve = [&]() -> void {
        vector<int> p1, pref(n);
        for (int i = 0; i < n; i++) {
            if (ar[i] == 1) p1.push_back(i);
            pref[i] = (i ? pref[i - 1] : 0) ^ F[ar[i]];
        }

        for (int i = 0; i < p1.size(); i++) {
            ans++;
            int mx = 1;
            int R = (i < (int)p1.size() - 1 ? p1[i + 1] : n);
            for (int r = p1[i] + 1; r < R; r++) {
                mx = max(mx, ar[r]);
                if (r - mx + 1 > p1[i]) continue;
                if (r < mx - 1) continue;
                int cek = pref[r] ^ (r >= mx ? pref[r - mx] : 0);
                ans += (cek == H[mx]);
            }
        }
    };

    solve();
    reverse(ar.begin(), ar.end());
    solve();
    ans -= count(ar.begin(), ar.end(), 1);
    cout << ans << '\n';
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