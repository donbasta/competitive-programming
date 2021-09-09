#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll W, H, x1, x2, y1, y2, w, h;

void solve() {
    cin >> W >> H;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> w >> h;
    ll w0 = x2 - x1, h0 = y2 - y1;
    if ((w0 + w > W) && (h0 + h > H)) {
        cout << -1 << '\n';
        return;
    }
    cout << fixed << setprecision(9);
    ll gu = H - y2;
    ll gd = y1;
    ll gl = x1;
    ll gr = W - x2;
    ll dy, dx;
    if ((max(gu, gd) >= h) || (max(gl, gr) >= w)) {
        cout << 0 << '\n';
        return;
    }
    ll ans = 1e10;
    if (H - h0 >= h) {
        ans = min(ans, min(h - gu, h - gd));
    }
    if (W - w0 >= w) {
        ans = min(ans, min(w - gl, w - gr));
    }
    double dans = ans;
    cout << dans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}