#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<string> s(n);
    vector<int> cr(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < n; j++) {
            cr[i] += (s[i][j] == 'o');
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        vector<int> pos;
        ll tmp = 0;
        for (int j = 0; j < n; j++) {
            if (s[j][i] == 'o') {
                pos.push_back(j);
                tmp += cr[j];
            }
        }
        int r = pos.size();
        if (r == 0) continue;
        ans += (tmp - r) * (r - 1);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}