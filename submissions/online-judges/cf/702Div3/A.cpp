#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
    cin >> n;
    vector<int> a(n);
    for (auto& e : a) { cin >> e; }
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        int p = min(a[i], a[i + 1]);
        int q = max(a[i], a[i + 1]);
        int m = 2 * p;
        while (m < q) {
            m *= 2;
            ans++;
        }
    }
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