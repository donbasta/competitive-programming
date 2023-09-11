#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, a, q;
    cin >> n >> a >> q;
    string s;
    cin >> s;
    int online = a;
    int cnt = 0;
    if (online == n) {
        cout << "YES" << '\n';
        return;
    }
    for (int i = 0; i < q; i++) {
        char cur = s[i];
        if (cur == '-')
            online--;
        else if (cur == '+')
            online++;
        if (online == n) {
            cout << "YES" << '\n';
            return;
        }
        cnt += (cur == '+');
    }
    if (cnt + a >= n) {
        cout << "MAYBE" << '\n';
        return;
    }
    cout << "NO" << '\n';
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