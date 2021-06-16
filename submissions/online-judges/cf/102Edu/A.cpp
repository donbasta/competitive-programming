#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, d;

void solve() {
    cin >> n >> d;
    vector<int> ar(n);
    for (auto& e : ar) {
        cin >> e;
    }
    sort(ar.begin(), ar.end());
    bool ok = (ar[0] + ar[1] <= d || ar[n - 1] <= d);
    cout << (ok ? "Yes" : "No");
    cout << '\n';
    return;
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