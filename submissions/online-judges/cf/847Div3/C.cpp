#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<vector<int>> ve(n, vector<int>(n - 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            cin >> ve[i][j];
        }
    }
    vector<int> p(n);
    for (int i = 0; i < n - 1; i++) {
        if (n == (2 * i + 2)) continue;
        unordered_map<int, int> cnt;
        for (int j = 0; j < n; j++) {
            cnt[ve[j][i]]++;
        }
        for (auto e : cnt) {
            if (e.second == n - i - 1) {
                p[i] = e.first;
            }
            if (e.second == i + 1) {
                p[i + 1] = e.first;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << p[i] << ' ';
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