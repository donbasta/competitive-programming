#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    vector<int> a(3);
    int m;
    cin >> a[0] >> a[1] >> a[2] >> m;
    sort(a.begin(), a.end());
    int val = a[0] + a[1] + a[2] - m;
    int mx;
    if (a[0] + a[1] == a[2]) {
        mx = 2 * a[2];
    } else if (a[0] + a[1] < a[2]) {
        mx = 2 * (a[0] + a[1]) + 1;
    } else {
        mx = a[0] + a[1] + a[2];
    }
    bool ok = ((val >= 3) && (val <= mx));
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