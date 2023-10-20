#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> ar(k);
    for (int i = 0; i < k; i++) {
        cin >> ar[i];
    }
    int cari = k;
    vector<bool> found(k + 1);
    int sz = 0;
    for (int i = 0; i < k; i++) {
        found[ar[i]] = true;
        sz++;
        if (sz + 1 > m * n - 2) {
            cout << "tidak" << '\n';
            return;
        }
        while (cari >= 1 && found[cari]) {
            found[cari] = false;
            cari--;
            sz--;
        }
    }
    cout << "ya" << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}