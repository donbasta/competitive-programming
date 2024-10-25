#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n, k;
    cin >> n >> k;
    if (k > (n + 1) / 2) {
        cout << -1 << '\n';
        return;
    }
    vector<string> ve(n, string(n, '.'));
    for (int i = 0; i < n; i += 2) {
        ve[i][i] = 'R';
        k--;
        if (k == 0) break;
    }
    for (int i = 0; i < n; i++) {
        cout << ve[i] << '\n';
    }
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