#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve () {
    int n, q;
    cin >> n;
    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    cin >> q;
    while (q--) {
        int s, t;
        cin >> s >> t;
        ll ans = 0;
        if (t - s == 1) {
            if (h[s] == h[t]) {
                ans = 2;
            } else if (h[s] > h[t]) {
                ans = h[s] - h[t];
            } else {
                ans = 4LL * (h[t] - h[s]);
            }
        } else {
            if (h[s] == h[t]) {
                ans = 0;
            } else if (h[s] > h[t]) {
                ans = h[s] - h[t];
            } else {
                ans = 4LL * (h[t] - h[s]);
            }
        }
        cout << ans << '\n';
    }
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve ();
    }

    return 0;
}