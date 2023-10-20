#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n, s, r;
    cin >> n >> s >> r;
    int hilang = s - r;
    int t = r / (n - 1);
    int u = r % (n - 1);
    vector<int> ve(n);
    for (int i = 0; i < u; i++) {
        ve[i] = t + 1;
    }
    for (int i = u; i < n - 1; i++) {
        ve[i] = t;
    }
    ve[n - 1] = hilang;
    for (auto e : ve) {
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
        el_psy_congroo();
    }

    return 0;
}