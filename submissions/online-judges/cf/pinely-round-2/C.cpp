#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> ord(n + 1);
    vector<bool> ada(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> ord[i];
        ada[ord[i]] = true;
    }
    for (int i = 0; i <= n; i++) {
        if (!ada[i]) {
            ord[n] = i;
            break;
        }
    }
    int start = (n - k + 1) % (n + 1);
    if (start < 0) start += (n + 1);
    vector<int> ret;
    for (int i = 0; i < n; i++) {
        ret.push_back(ord[start]);
        start = (start + 1) % (n + 1);
    }
    for (auto e : ret) {
        cout << e << ' ';
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