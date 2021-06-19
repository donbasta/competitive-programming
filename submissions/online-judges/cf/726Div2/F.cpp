#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

bool dfs(int x, int col, vector<int>& vis, const vector<vector<int>>& adj) {
    vis[x] = col;
    bool ok = 1;
    for (auto c : adj[x]) {
        if (vis[c] != -1 && vis[c] == vis[x]) {
            return false;
        } else if (vis[c] != -1 && vis[c] != vis[x]) {
            continue;
        } else {
            ok &= dfs(c, col ^ 1, vis, adj);
        }
    }
    return ok;
}

int n, m;

void solve() {
    cin >> n >> m;
    ll V = 0, T = 0;

    vector<int> v(n), t(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        V += v[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        T += t[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if (abs(V - T) % 2 != 0) {
        cout << "NO\n";
        return;
    }

    vector<int> vis(n, -1);
    bool is_bip = dfs(0, 0, vis, adj);
    if (is_bip) {
        vector<ll> VV(2), TT(2);
        for (int i = 0; i < n; i++) {
            // cerr << i << ' ' << vis[i] << '\n';
            VV[vis[i]] += v[i], TT[vis[i]] += t[i];
        }
        bool ok = (VV[1] - VV[0]) == (TT[1] - TT[0]);
        if (!ok) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    } else {
        cout << "YES\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {

        solve();
    }
  
    return 0;
}