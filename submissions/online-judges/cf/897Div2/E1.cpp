#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for (int i = 1; i + k - 1 <= n; i += k) {
        cout << "? " << i << endl;
        int seg;
        cin >> seg;
        ans ^= seg;
    }
    int last = k * (n / k);
    if (last == n) {
        cout << "! " << ans << endl;
        return;
    }
    int b = n - last;
    assert(b % 2 == 0);
    int c = b / 2;
    int X, Y;
    cout << "? " << (last + 1 - k + c) << endl;
    cin >> X;
    cout << "? " << (last + 1 - k + c + c) << endl;
    cin >> Y;
    ans = (ans ^ X ^ Y);
    cout << "! " << ans << endl;
    return;
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