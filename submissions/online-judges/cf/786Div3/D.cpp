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
    vector<int> cve = ve;
    sort(ve.begin(), ve.end());
    bool ok = true;
    for (int i = n - 1; i >= 1; i -= 2) {
        ok &= ((ve[i] == cve[i] && ve[i - 1] == cve[i - 1]) || (ve[i] == cve[i - 1] && ve[i - 1] == cve[i]));
    }
    if (n & 1) {
        ok &= (ve[0] == cve[0]);
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