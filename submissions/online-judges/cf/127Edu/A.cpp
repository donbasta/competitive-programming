#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int len = 1;
    char cur = s[0];
    for (int i = 1; i < n; i++) {
        if (s[i] == cur) {
            len++;
        } else {
            if (len == 1) {
                cout << "NO" << '\n';
                return;
            }
            cur = s[i];
            len = 1;
        }
    }
    if (len == 1) {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
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