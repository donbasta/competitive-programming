#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    if (s[0] != 0) {
        cout << 0 << endl;
        int x;
        cin >> x;
        assert(x == -1);
        return;
    } else {
        int idx = 0;
        while (idx < n && s[idx] == idx) idx++;
        int alice = idx, bob;
        cout << alice << endl;
        for (int i = 0; i <= n; i++) {
            cin >> bob;
            if (bob == -1) {
                return;
            } else if (bob == -2) {
                exit(0);
            }
            alice = bob;
            cout << alice << endl;
        }
    }
}

int main() {
    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}