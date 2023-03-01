#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

set<string> se;

void init() {
    string lmao = "FBFFBFFBFBFFBFFBFBFF";
    for (int i = 1; i <= 10; i++) {
        for (int j = 0; j < 8; j++) {
            se.insert(lmao.substr(j, i));
        }
    }
}

void solve() {
    int k;
    cin >> k;
    string s;
    cin >> s;
    if (se.count(s)) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}