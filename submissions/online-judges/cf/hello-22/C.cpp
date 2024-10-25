#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

int ask(int x) {
    cout << "? " << x << endl;
    int ret;
    cin >> ret;
    return ret;
}

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> ans(n), P(n + 1);
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        int init = ask(i);
        vis[init] = true;
        int prv = init;
        int x = ask(i);
        while (x != init) {
            vis[x] = true;
            P[prv] = x;
            prv = x;
            x = ask(i);
        }
        P[prv] = x;
    }
    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << P[i] << ' ';
    }
    cout << endl;
}

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}