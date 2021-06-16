#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ld PI = acos(-1);

int n, r, k;
ld angle, co, si, a, ans;

ld poly_without_incircle(ld ri) {
    ld rc = ri / co;
    ld area_poly = ((ld) k * rc * rc * si) / ((ld) 2);
    ld area_circ = PI * ri * ri;
    return area_poly - area_circ;
}

void solve() {
    cin >> n >> r >> k;
    ld ans = 0;
    ld rr = (ld) r;
    angle = (PI * 2) / ((ld) 2 * k);
    co = cos(angle);
    si = sin(angle * 2);
    a = poly_without_incircle(rr);
    ans = a * (pow(1 / (co * co), n) - 1) / ((1 / (co * co)) - 1);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("glorious.in", "r", stdin);

    cout << fixed << setprecision(9);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
  
    return 0;
}