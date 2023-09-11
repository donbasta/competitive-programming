#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    string s;
    cin >> s;
    if (s == "()") {
        cout << "NO" << '\n';
        return;
    }
    int n = s.length();
    for (int i = 0; i < n - 1; i++) {
        if (s.substr(i, 2) == ")(") {
            cout << "YES" << '\n';
            for (int x = 0; x < n; x++) cout << '(';
            for (int x = 0; x < n; x++) cout << ')';
            cout << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) {
        cout << "()";
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
        solve();
    }

    return 0;
}