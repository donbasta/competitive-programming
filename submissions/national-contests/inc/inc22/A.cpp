#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    sort(ar.begin(), ar.end());

    int cnt = 0;
    int mx = -1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ar[j] - ar[i] > m) break;
            for (int k = j + 1; k < n; k++) {
                if (ar[k] - ar[i] > m) break;
                cnt++;
                mx = max(mx, ar[i] + ar[j] + ar[k]);
            }
        }
    }
    if (cnt == 0) {
        cout << -1 << '\n';
        return;
    }
    cout << cnt << ' ' << mx << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}