#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 8e3;

int n;
ld p;
ld f[N + 5];

ld C(int a) {
    return (ld)(a * (a - 1) / 2);
}

ld F(int a, int b) {
    ld ret = ((ld)a) / C(b);
    return ret;
}

ld G(int a, int b) {
    return C(a) / C(b);
}

ld H(int a, int b) {
    return ((ld)(a * (b - a))) / C(b);
}

void solve() {
    cin >> n >> p;
    ld q = (ld)1.0 - p;
    fill(f, f + n + 1, 0);
    f[1] = 1.0;
    f[2] = 1.0;
    for (int i = 3; i <= n; i++) {
        ld bdp[n + 1];
        fill(bdp, bdp + n + 1, 0);
        for (int j = 1; j <= i; j++) {
            ld temp = p * F(i - j, i) + q * F(j - 1, i);
            ld temp1 = ((ld)1.0 + f[j]) * (G(i - j, i) + H(j, i) * q);
            ld temp2 = ((ld)1.0 + f[j - 1]) * (G(j - 1, i) + H(j - 1, i) * p);
            bdp[j] = temp + temp1 + temp2;
        }
        for (int j = 1; j <= n; j++) {
            f[j] = bdp[j];
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << '\n'
             << f[i];
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(10);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}