#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    set<int> se;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0 && b[i] == 0) continue;
        int ax = a[i], bx = b[i];
        int steps = 0;
        while (bx > 0) {
            int q = ax / bx;
            int r = ax % bx;
            steps++;
            if (q & 1) {
                ax = bx;
                bx = r;
            } else {
                ax = bx;
                bx = (bx - r);
            }
        }
        se.insert(steps % 3);
    }
    bool ok = (se.size() <= 1);
    cout << (ok ? "YES" : "NO") << '\n';
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