#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

ll s, k;

ll F(ll a, ll b) {  // max of (s + a + 20x)(k - b - 4x) over all nonnegative integer x
    ll lmao = (k - b) * 5ll - (s + a) * 1ll;
    ll sgn = lmao / abs(lmao);
    ll A = abs(lmao) / 40;
    ll B = A + 1;
    A *= sgn, B *= sgn;
    if (A > B) swap(A, B);
    if (B < 0) return (s + a) * (k - b);
    ll fA = (s + a + A * 20) * (k - b - A * 4);
    ll fB = (s + a + B * 20) * (k - b - B * 4);
    if (A < 0) return fB;
    return max(fA, fB);
}

void solve() {
    cin >> s >> k;
    ll dig = s % 10;
    ll ans;
    if (dig == 0) {
        ans = s * k;
    } else if (dig == 5) {
        ans = max(s * k, (s + 5) * (k - 1));
    } else if (dig == 1) {
        ans = max(s * k, (s + 1) * (k - 1));
        ans = max(ans, F(3, 2));
        ans = max(ans, F(7, 3));
        ans = max(ans, F(15, 4));
        ans = max(ans, F(21, 5));
    } else if (dig == 3) {
        ans = max(s * k, (s + 3) * (k - 1));
        ans = max(ans, F(9, 2));
        ans = max(ans, F(11, 3));
        ans = max(ans, F(15, 4));
        ans = max(ans, F(23, 5));
    } else if (dig == 7) {
        ans = max(s * k, (s + 7) * (k - 1));
        ans = max(ans, F(11, 2));
        ans = max(ans, F(19, 3));
        ans = max(ans, F(25, 4));
        ans = max(ans, F(27, 5));
    } else if (dig == 9) {
        ans = max(s * k, (s + 9) * (k - 1));
        ans = max(ans, F(17, 2));
        ans = max(ans, F(23, 3));
        ans = max(ans, F(25, 4));
        ans = max(ans, F(29, 5));
    } else if (dig == 2) {
        ans = s * k;
        ans = max(ans, F(2, 1));
        ans = max(ans, F(6, 2));
        ans = max(ans, F(14, 3));
        ans = max(ans, F(20, 4));
    } else if (dig == 4) {
        ans = s * k;
        ans = max(ans, F(4, 1));
        ans = max(ans, F(12, 2));
        ans = max(ans, F(18, 3));
        ans = max(ans, F(20, 4));
    } else if (dig == 6) {
        ans = s * k;
        ans = max(ans, F(6, 1));
        ans = max(ans, F(8, 2));
        ans = max(ans, F(12, 3));
        ans = max(ans, F(20, 4));
    } else if (dig == 8) {
        ans = s * k;
        ans = max(ans, F(8, 1));
        ans = max(ans, F(14, 2));
        ans = max(ans, F(16, 3));
        ans = max(ans, F(20, 4));
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
        solve();
    }

    return 0;
}