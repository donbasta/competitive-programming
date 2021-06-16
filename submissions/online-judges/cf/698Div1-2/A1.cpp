#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;
ll k;

void solve() {
     cin >> n >> k;
     vector<ll> ar(n);
     for (int i = 0; i < n; i++) {
        cin >> ar[i];
     }
     sort(ar.begin(), ar.end());
     ar.resize(unique(ar.begin(), ar.end()) - ar.begin());
     n = (int)ar.size();
     if (n == 1) {
        cout << ((ar[0] == k) ? "YES" : "NO") << '\n';
     }
     ll fpb = 0;
     for (int i = 1; i < n; i++) {
        fpb = __gcd(fpb, ar[i] - ar[i - 1]);
     }
     ll u = (ar[0] % fpb);
     if (u < 0) u += fpb;
     ll v = (k % fpb);
     if (v < 0) v += fpb;
     cout << ((u == v) ? "YES" : "NO") << '\n';
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