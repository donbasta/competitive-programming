#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> ar(n);
    ll tmp = 0;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        tmp += ar[i];
    }
    sort(ar.begin(), ar.end());
    ll empty = m - n;
    ll need = tmp + ar[n - 1] - ar[0];
    cout << ((need <= empty) ? "YES" : "NO") << '\n';
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