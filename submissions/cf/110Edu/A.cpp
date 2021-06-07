#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int a[4];

void solve() {
    for (int i = 0; i < 4; i++) { cin >> a[i]; }
    int j1 = max(a[0], a[1]);
    int j2 = max(a[2], a[3]);
    if (j1 < j2) swap(j1, j2);
    sort (a, a + 4);
    int k1 = a[3];
    int k2 = a[2];
    bool ok = (j1 == k1) && (j2 == k2);
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