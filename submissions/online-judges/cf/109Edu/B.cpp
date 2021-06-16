#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
    cin >> n;
    vector<int> ar(n + 5);
    int l = 1;
    for (int i = 1; i <= n; i++) { cin >> ar[i]; }
    bool okl = ar[1] == 1;
    bool okr = ar[n] == n;
    while (l <= n && ar[l] == l) { l++; }

    int ans = -1;
    if (l == n + 1) ans = 0;
    else if (okl || okr) ans = 1;
    else if (ar[1] != n || ar[n] != 1) ans = 2;
    else ans = 3;

    cout << ans << '\n';
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