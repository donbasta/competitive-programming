#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<int> ve(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
    }
    vector<int> cnt(4);
    for (int i = 1; i < n; i++) {
        int dif = ve[i] - ve[i - 1];
        if (dif > 3) {
            cout << "NO" << '\n';
            return;
        }
        if (dif > 1) {
            cnt[dif]++;
        }
    }
    if ((cnt[3] == 1 && cnt[2] == 0) || (cnt[3] == 0 && cnt[2] <= 2)) {
        cout << "YES" << '\n';
        return;
    }
    cout << "NO" << '\n';
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