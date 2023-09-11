#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    string s;
    cin >> s;
    int cnt = 0;
    int mx_pref = 0;
    int pref = 0;
    int idx = 0;
    int n = s.length();
    while (idx < n && (s[idx] == '+' || s[idx] == '-')) {
        if (s[idx] == '+')
            cnt++;
        else
            cnt--;
        idx++;
    }
    if (idx == n) {
        cout << "YES" << '\n';
        return;
    }
    if (s[idx] == '0') {
        if (cnt <= 1) {
            cout << "NO" << '\n';
            return;
        }
        mx_pref = cnt - 1;
    } else if (s[idx] == '1') {
        mx_pref = cnt;
        pref = cnt;
    }

    int tmp = cnt;
    for (int i = idx + 1; i < n; i++) {
        if (s[i] == '-') {
            if (mx_pref == cnt) mx_pref--;
            if (pref == cnt) pref--;
            cnt--;
            tmp = min(tmp, cnt);
        } else if (s[i] == '+') {
            if (mx_pref == cnt) mx_pref++;
            cnt++;
            tmp = max(tmp, cnt);
        } else if (s[i] == '0') {
            if (cnt <= 1) {
                cout << "NO" << '\n';
                return;
            }
            if (pref == cnt) {
                cout << "NO" << '\n';
                return;
            }
            mx_pref = cnt - 1;
        } else if (s[i] == '1') {
            if (mx_pref < cnt) {
                cout << "NO" << '\n';
                return;
            }
            pref = cnt;
        }
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