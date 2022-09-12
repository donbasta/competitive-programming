#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    vector<int> ve(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
    }
    int ans = 1e9;
    for (int i = 0; i < n - 1; i++) {
        int p = ve[i], q = ve[i + 1];
        ans = min(ans, max({(p + 1) / 2, (q + 1) / 2, (p + q + 2) / 3}));
    }
    for (int i = 0; i < n - 2; i++) {
        int p = ve[i], q = ve[i + 2];
        ans = min(ans, (p + q + 1) / 2);
    }
    sort(ve.begin(), ve.end());
    ans = min(ans, ((ve[0] + 1) / 2) + ((ve[1] + 1) / 2));
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}