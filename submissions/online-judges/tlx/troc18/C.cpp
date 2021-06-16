#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    vector<int> ar(n), ans(n);
    for (auto& e : ar) cin >> e;
    sort(ar.begin(), ar.end());
    int p = 0, q = n - 1;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            ans[p++] = ar[i];
        } else {
            ans[q--] = ar[i];
        }
    }
    for (auto& e : ans) cout << e << ' ';
    cout << '\n';
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