#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
    cin >> n;
    vector<ll> ar(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    vector<ll> p(n + 1), s(n + 1);
    for (int i = 1; i <= n - 1; i++) {
        if (ar[i] > ar[i + 1]) {
            p[i] = ar[i] - ar[i + 1];
        } else {
            s[i + 1] = ar[i + 1] - ar[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        p[i] += p[i - 1];
        s[i] += s[i - 1];
    }
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        ok &= ((s[i] + p[n] - p[i - 1]) <= ar[i]);
    }
    cout << (ok ? "YES" : "NO") << '\n';
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