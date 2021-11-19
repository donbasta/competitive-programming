#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve () {
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n - 1; i++) {
        if ((s[i] == s[i + 1]) && (s[i] == 'a')) {
            cout << 2 << '\n';
            return;
        }
    }
    for (int i = 0; i < n - 2; i++) {
        if ((s[i] == s[i + 2]) && (s[i] == 'a')) {
            cout << 3 << '\n';
            return;
        }
    }
    for (int i = 0; i < n - 3; i++) {
        if ((s[i] == s[i + 3]) && (s[i] == 'a') && (s[i + 1] != s[i + 2])) {
            cout << 4 << '\n';
            return;
        }
    }
    for (int i = 0; i < n - 6; i++) {
        if ((s[i] == s[i + 3]) && (s[i + 3] == s[i + 6]) && (s[i] == 'a')) {
            if ((s[i + 1] != s[i + 4])) {
                cout << 7 << '\n';
                return;
            }
        }
    }
    cout << -1 << '\n';
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve ();
    }

    return 0;
}