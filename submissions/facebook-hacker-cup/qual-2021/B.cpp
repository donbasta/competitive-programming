#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 1e9;
int n;

void solve() {
    cin >> n;
    vector<string> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    vector<int> cnt(n + 5);
    set<pair<int, int>> se;
    int mn = INF;
    for (int i = 0; i < n; i++) {
        int tmp = 0;
        bool cant = false;
        int emp;
        for (int j = 0; j < n; j++) {
            if (c[i][j] == 'O') {
                cant = true;
                break;
            } else if (c[i][j] == 'X') {
                tmp++;
            } else if (c[i][j] == '.') {
                emp = j;
            }
        }
        if (cant) continue;
        else {
            if (n - tmp > 1) cnt[n - tmp]++;
            else {
                se.emplace(i, emp);
            }
            mn = min(mn, n - tmp);
        }
    }
    for (int i = 0; i < n; i++) {
        int tmp = 0;
        bool cant = false;
        int emp;
        for (int j = 0; j < n; j++) {
            if (c[j][i] == 'O') {
                cant = true;
                break;
            } else if (c[j][i] == 'X') {
                tmp++;
            } else if (c[j][i] == '.') {
                emp = j;
            }
        }
        if (cant) continue;
        else {
            if (n - tmp > 1) cnt[n - tmp]++;
            else {
                se.emplace(emp, i);
            }
            mn = min(mn, n - tmp);
        }
    }
    if (mn == INF) {
        cout << "Impossible" << '\n';
    } else if (mn > 1) {
        cout << mn << ' ' << cnt[mn] << '\n';
    } else if (mn == 1) {
        cout << mn << ' ' << se.size() << '\n';
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
  
    return 0;
}