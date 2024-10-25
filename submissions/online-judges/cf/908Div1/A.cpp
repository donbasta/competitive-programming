#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n, k;
    cin >> n >> k;
    vector<int> B(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> B[i];
    }
    int cur = n;
    vector<bool> vis(n + 1);
    for (int i = 1; i <= k; i++) {
        if (B[cur] > n) {
            cout << "No" << '\n';
            return;
        }
        vis[cur] = true;
        cur = (cur - B[cur]) % n;
        if (cur < 0) cur += n;
        if (vis[cur]) {
            cout << "Yes" << '\n';
            return;
        }
    }
    cout << "Yes" << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}