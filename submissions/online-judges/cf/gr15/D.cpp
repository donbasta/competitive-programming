#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> ve;
    for (int i = 0; i < (1 << n); i++) {
        int tmp = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) tmp += a[j];
        }
        ve.emplace_back(tmp);
    }
    int sz = (int) ve.size();
    bool ok = false;
    for (int i = 0; i < sz; i++) {
        for (int j = i + 1; j < sz; j++) {
            if (ve[i] == ve[j]) {
                ok = true;
                break;
            }
        }
        if (ok) break;
    }
    if (!ok) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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