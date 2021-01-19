#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;
const int N = 2e5;

int n;
// ll ar[N + 5];

void solve() {
    cin >> n;
    vector<ll> pre(n + 1);
    vector<ll> mn(n + 5), ar(n + 5);
    vector<bool> ok(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        pre[i] = ar[i] + (i == 1 ? 0 : pre[i - 2]);
    }
    mn[n + 1] = mn[n] = INF;
    for (int i = n - 1; i >= 1; i--) {
        mn[i] = min (mn[i + 2], pre[i + 1] - pre[i]);
    }
    ok[0] = ok[1] = true;
    for (int i = 2; i <= n; i++) {
        ok[i] = (ok[i - 1] && (pre[i] >= pre[i - 1]));
    }
    if (ok[n] && (pre[n] == pre[n - 1])) {
        cout << "YES\n";
        return;
    }
    bool ans = false;
    for (int i = 1; i < n; i++) {
        ll dif = ar[i] - ar[i + 1];
        bool cek = (pre[i] - pre[i - 1] >= dif);
        if (ok[i - 1] && (mn[i] + 2LL * dif >= 0) && (mn[i + 1] >= 2LL * dif) && cek) {
            ll lul = -(2LL * dif);
            if ((n % 2) == (i % 2)) lul = -lul;
            if (pre[n] - pre[n - 1] == lul) {
                ans = true;
                break;
            }
        }
    }
    cout << (ans ? "YES" : "NO") << '\n';
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