#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    string s;
    cin >> s;
    int n = s.length();
    if (s[0] == '0') {
        cout << -1 << '\n';
        return;
    }
    int st = 1;
    while (st < n && s[st] == '0') st++;
    if (st == n) {
        cout << -1 << '\n';
        return;
    }
    int a = stoi(s.substr(0, st));
    int b = stoi(s.substr(st, n - st));
    if (a >= b) {
        cout << -1 << '\n';
        return;
    }
    cout << a << ' ' << b << '\n';
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