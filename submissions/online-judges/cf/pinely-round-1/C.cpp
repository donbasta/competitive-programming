#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<string> b(n);
    vector<vector<int>> from(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<vector<int>> ret(n);
    for (int i = 0; i < n; i++) {
        ret[i].push_back(i);
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            if (b[j][i] == '1') ret[i].push_back(j);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ret[i].size() << ' ';
        for (auto e : ret[i]) {
            cout << (e + 1) << ' ';
        }
        cout << '\n';
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