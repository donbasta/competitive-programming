#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    int cnt2 = 0;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        cnt2 += (ar[i] == 2);
    }
    if (cnt2 & 1) {
        cout << -1 << '\n';
        return;
    }
    if (cnt2 == 0) {
        cout << 1 << '\n';
        return;
    }
    int target = cnt2 / 2;
    int idx = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += (ar[i] == 2);
        if (cnt == target) {
            cout << i + 1 << '\n';
            return;
        }
    }
    assert(false);
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