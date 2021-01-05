#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    ll a = h[0], b = h[0];
    for (int i = 1; i < n; i++) {
        a = max (a - k + 1, h[i]);
        b = min (b + k - 1, h[i] + k - 1);
        if (a > b) {
            cout << "NO" << '\n';
            return;
        }
    }
    if (h[n - 1] < a || h[n - 1] > b) {
        cout << "NO";
    } else {
        cout << "YES";
    }
    cout << '\n';
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