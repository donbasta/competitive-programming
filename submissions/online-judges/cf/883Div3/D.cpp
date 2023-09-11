#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, d, h;
    cin >> n >> d >> h;
    vector<int> ve(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
    }
    ld base = (ld)(h) * (d) / (ld)(2);
    ld area = base;
    for (int i = 1; i < n; i++) {
        if (ve[i] >= ve[i - 1] + h) {
            area += base;
        } else {
            int h_small = ve[i - 1] + h - ve[i];
            ld ratio = (ld)(h_small) / (ld)(h);
            area += (base) * (1.0 - ratio * ratio);
        }
    }
    cout << fixed << setprecision(9) << area << '\n';
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