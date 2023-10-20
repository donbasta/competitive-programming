#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ld INF = 1e18;
const ld PI = acos(-1);

ld F(int x, int y, int z) {
    ld A = (ld)y * z - (ld)z + 1;
    ld B = (ld)x * y * z;
    return (A / B);
}

ld G(int x, int y, int z) {
    return (ld)1 - F(x, y, z);
}

void solve() {
    ll r, s, h;
    cin >> r >> s >> h;
    ld t = (PI * 2 * r) / ((ld)h * s);
    ld ft = floor(t);
    ld q = t - ft;
    ld mn = INF;
    vector<int> best;
    if ((t - ft) < (ft + 1 - t)) {  // round down
        for (int n = 1; n <= 250; n++) {
            for (int a = 2; a <= (500 / n); a++) {
                for (int b = 2; b <= (1000 / (a * n)); b++) {
                    ld calc = F(n, a, b);
                    if (abs(calc - q) < mn) {
                        mn = abs(calc - q);
                        best = {n, a, b};
                    }
                }
            }
        }
    } else {  // round up
        for (int n = 1; n <= 250; n++) {
            for (int a = 2; a <= (500 / n); a++) {
                for (int b = 2; b <= (1000 / (a * n)); b++) {
                    ld calc = G(n, a, b);
                    if (abs(calc - q) < mn) {
                        mn = abs(calc - q);
                        best = {n, a, b};
                    }
                }
            }
        }
    }
    int n = best[0], a = best[1], b = best[2];
    int n1 = n, n2 = n * a, n3 = n * a * b;
    cout << n1 << ' ' << n2 << ' ' << n3 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}