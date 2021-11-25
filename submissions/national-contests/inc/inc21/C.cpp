#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

vector<int> magic = {0, 3, 11, 19, 29, 45, 71, 97, 123, 149, 175, 313, 407};

void solve() {
    set<int> gs;
    for (auto e : magic) {
        gs.insert(e);
    }

    int n;
    cin >> n;
    vector<int> to(n + 1), a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        to[a[i]] = b[i];
    }
    vector<bool> vis(n + 1);
    vector<int> cyc;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        int len = 1;
        int cur = i;
        vis[cur] = true;
        cur = to[cur];
        while (cur != i) {
            vis[cur] = true;
            len++;
            cur = to[cur];
        }
        cyc.emplace_back(len);
    }
    int xr = 0;
    for (auto e : cyc) {
        int now;
        if (e == 1) {
            now = 1;
        } else {
            now = (gs.count(e - 2) ? 1 : 0);
        }
        xr ^= now;
    }
    cout << (xr ? "First" : "Second") << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}