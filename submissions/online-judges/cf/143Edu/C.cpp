#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n + 1), b(n + 1), c(n + 1);
    vector<ll> pre(n + 1), ans(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) {
        pre[i] = (pre[i - 1] + b[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] < b[i]) {
            ans[i] += a[i];
            continue;
        }
        int l = i, r = n, bat = i;
        while (l <= r) {
            int mid = (l + r) >> 1;
            ll cek = pre[mid] - pre[i - 1];
            if (cek > a[i]) {
                r = mid - 1;
            } else {
                bat = mid;
                l = mid + 1;
            }
        }
        ll lul = pre[bat] - pre[i - 1];
        c[i]++;
        if (bat + 1 <= n) c[bat + 1]--;
        if (lul < a[i]) {
            if (bat + 1 <= n) {
                ans[bat + 1] += (a[i] - lul);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        c[i] += c[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        ans[i] += c[i] * b[i];
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
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