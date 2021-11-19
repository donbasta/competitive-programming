#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ld PI = acos(-1);

void solve () {
    ld r, R, h;
    cin >> r >> R >> h;
    ld theta1 = (PI - atan(h / (R - r))) / ld(2);
    ld ret1 = r * tan(theta1);
    ld theta2 = ((PI / ld(2)) - (atan((R - r) / h))) / ld(2);
    ld ret2 = R * tan(theta2);
    ld ans = max(ret1, ret2);
    ans = min(ans, h / ld(2));
    cout << fixed << setprecision(12) << ans << '\n';
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