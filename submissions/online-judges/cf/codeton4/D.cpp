#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;

void solve() {
    int q;
    cin >> q;
    ll le = INF, ri = INF;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            ll a, b, n;
            cin >> a >> b >> n;
            ll kiri, kanan;
            if (n >= 2) {
                kiri = (n - 2) * (a - b) + a + 1;
                kanan = (n - 1) * (a - b) + a;
            } else {
                kiri = 1, kanan = a;
            }
            if (le == INF && ri == INF) {
                cout << 1 << ' ';
                le = kiri, ri = kanan;
            } else {
                if (kiri > ri || kanan < le) {
                    cout << 0 << ' ';
                } else {
                    cout << 1 << ' ';
                    le = max(le, kiri);
                    ri = min(ri, kanan);
                }
            }
        } else if (type == 2) {
            ll a, b;
            cin >> a >> b;
            if (le == INF && ri == INF) {
                cout << -1 << ' ';
            } else {
                if (a >= ri) {
                    cout << 1 << ' ';
                } else {
                    ll kiri = (le - b + (a - b - 1)) / (a - b);
                    ll kanan = (ri - b + (a - b - 1)) / (a - b);
                    if (kiri == kanan) {
                        cout << kiri << ' ';
                    } else {
                        cout << -1 << ' ';
                    }
                }
            }
        }
    }
    cout << '\n';
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