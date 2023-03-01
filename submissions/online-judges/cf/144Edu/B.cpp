#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    string a, b;
    cin >> a >> b;
    set<string> a2;
    for (int i = 0; i < a.length() - 1; i++) {
        a2.insert(a.substr(i, 2));
    }
    for (int i = 0; i < b.length() - 1; i++) {
        if (a2.count(b.substr(i, 2))) {
            cout << "YES" << '\n';
            cout << '*' << b.substr(i, 2) << '*' << '\n';
            return;
        }
    }
    if (a[0] == b[0]) {
        cout << "YES" << '\n';
        cout << a[0] << '*' << '\n';
    } else if (a.back() == b.back()) {
        cout << "YES" << '\n';
        cout << '*' << a.back() << '\n';
    } else {
        cout << "NO" << '\n';
    }
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