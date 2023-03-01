#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> ve(n + 1, -1);
    int cur = n;
    vector<bool> udah(m + 1);
    vector<int> ar(m);
    for (int i = 0; i < m; i++) cin >> ar[i];
    for (int i = 0; i < m; i++) {
        if (udah[ar[i] - n])
            continue;
        else {
            udah[ar[i] - n] = true;
            ve[cur] = (i + 1);
            cur--;
            if (cur == 0) break;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ve[i] << ' ';
    }
    cout << '\n';
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