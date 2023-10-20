#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<bool> pr(n), su(n);
    for (int i = 0; i < n; i++) {
        bool ok = true;
        for (int j = 0; j <= i; j++) {
            if (s[j] != s[i - j]) {
                ok = false;
                break;
            }
        }
        pr[i] = ok;
    }
    for (int i = n - 1; i >= 0; i--) {
        bool ok = true;
        for (int j = i; j <= n - 1; j++) {
            if (s[j] != s[n - 1 - j + i]) {
                ok = false;
                break;
            }
        }
        su[i] = ok;
    }
    for (int i = 0; i < n - 1; i++) {
        if (pr[i] && su[i + 1]) {
            cout << s.substr(0, i + 1) << ' ' << s.substr(i + 1, n - i - 1) << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
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