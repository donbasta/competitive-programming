#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<int> on, off;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1')
            on.insert(n - i - 1);
        else
            off.insert(n - i - 1);
    }
    if (on.empty()) {
        for (int i = 0; i < n; i++) {
            cout << 0 << ' ';
        }
        cout << '\n';
        return;
    }
    ll cur = 0;
    for (int i = 1; i <= n; i++) {
        if (*on.begin() >= i) {
            cout << cur << ' ';
        } else {
            auto ptr = off.lower_bound(i);
            if (ptr == off.end()) {
                cout << -1 << ' ';
            } else {
                int x = *on.begin();
                int y = *ptr;
                on.erase(x);
                off.erase(y);
                on.insert(y);
                off.insert(x);
                cur += (y - x);
                cout << cur << ' ';
            }
        }
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
        el_psy_congroo();
    }

    return 0;
}