#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    vector<int> ve(n);
    int neg = 0, pos = 0;
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
        int sgn = ve[i] / abs(ve[i]);
        if (sgn == -1) {
            neg++;
        } else {
            pos++;
        }
        ve[i] = abs(ve[i]);
    }
    int idx = 0;
    while (idx < n - 1 && ve[idx + 1] <= ve[idx]) {
        idx++;
    }
    int idx2 = n - 1;
    while (idx2 >= 1 && ve[idx2 - 1] <= ve[idx2]) {
        idx2--;
    }
    bool ok = (idx + 1 >= neg && n - idx2 >= pos);
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