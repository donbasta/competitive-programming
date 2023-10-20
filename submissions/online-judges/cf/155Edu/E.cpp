#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<int> par(n), dep(n), chd(n);
    for (int i = 1; i < n; i++) {
        cin >> par[i];
        --par[i];
        dep[i] = dep[par[i]] + 1;
        chd[par[i]]++;
    }
    bool ok2 = true;
    vector<set<int>> se(2);
    for (int i = 1; i < n; i++) {
        se[(dep[i] & 1)].insert(chd[i]);
    }
    for (auto x : se[0]) {
        if (se[1].count(x)) {
            ok2 = false;
            break;
        }
    }
    int mx_depth = *max_element(dep.begin(), dep.end());
    int num_col;
    if (mx_depth == 1) {
        num_col = 1;
        cout << 1 << endl;
        for (int i = 1; i < n; i++) {
            cout << 1 << ' ';
        }
        cout << endl;
    } else if (mx_depth == 2) {
        num_col = 2;
        cout << 2 << endl;
        for (int i = 1; i < n; i++) {
            cout << dep[i] << ' ';
        }
        cout << endl;
    } else {
        if (ok2) {
            num_col = 2;
            cout << 2 << endl;
            for (int i = 1; i < n; i++) {
                int col = dep[i] % 2;
                if (col == 0) col = 2;
                cout << col << ' ';
            }
            cout << endl;
        } else {
            num_col = 3;
            cout << 3 << endl;
            for (int i = 1; i < n; i++) {
                int col = dep[i] % 3;
                if (col == 0) col = 3;
                cout << col << ' ';
            }
            cout << endl;
        }
    }
    int t;
    cin >> t;
    while (t != 1) {
        if (t == -1) {
            exit(0);
        } else if (t == 0) {
            if (num_col == 1) {
                int x;
                cin >> x;
                cout << 1 << endl;
            } else if (num_col == 2) {
                int a, b;
                cin >> a >> b;
                if (a == 0) {
                    cout << 2 << endl;
                } else if (b == 0) {
                    cout << 1 << endl;
                } else {
                    if (a == 1 && b == 1) {
                        if (se[0].count(1)) {
                            cout << 2 << endl;
                        } else if (se[1].count(1)) {
                            cout << 1 << endl;
                        }
                    } else if (a == 1) {
                        cout << 1 << endl;
                    } else if (b == 1) {
                        cout << 2 << endl;
                    }
                }
            } else if (num_col == 3) {
                vector<pair<int, int>> cnt(3);
                for (int i = 0; i < 3; i++) {
                    cin >> cnt[i].first;
                    cnt[i].second = (i + 1);
                }
                sort(cnt.begin(), cnt.end());
                if (cnt[0].first == 0 && cnt[1].first == 0) {
                    cout << cnt[2].second << endl;
                } else {
                    assert(cnt[0].first == 0);
                    if (cnt[0].second == 1) {
                        cout << 2 << endl;
                    } else if (cnt[0].second == 2) {
                        cout << 3 << endl;
                    } else if (cnt[0].second == 3) {
                        cout << 1 << endl;
                    }
                }
            }
        }
        cin >> t;
    }
    return;
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