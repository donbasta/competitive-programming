#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    vector<string> s(3);
    cin >> s[0] >> s[1] >> s[2];
    for (int i = 0; i < 3; i++) {
        char cur = s[i][0];
        if (cur == '.') continue;
        int lmao = 0;
        for (int j = 1; j < 3; j++) {
            lmao += (cur == s[i][j]);
        }
        if (lmao == 2) {
            cout << cur << '\n';
            return;
        }
    }
    for (int i = 0; i < 3; i++) {
        char cur = s[0][i];
        if (cur == '.') continue;
        int lmao = 0;
        for (int j = 1; j < 3; j++) {
            lmao += (cur == s[j][i]);
        }
        if (lmao == 2) {
            cout << cur << '\n';
            return;
        }
    }
    char cur = s[0][0];
    if ((cur != '.') && (cur == s[1][1]) && (cur == s[2][2])) {
        cout << cur << '\n';
        return;
    }
    cur = s[0][2];
    if ((cur != '.') && (cur == s[1][1]) && (cur == s[2][0])) {
        cout << cur << '\n';
        return;
    }
    cout << "DRAW" << '\n';
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