#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fir first
#define sec second
#define pb push_back
#define endl "\n"

const int cnst = 2e5 + 5;
bool mutipletestcase = 0;
// bool debug = false;

void solve() {
    int n, m;
    cin >> n >> m;

    bool light[n + 5];

    for (int i = 1; i <= n; i++) cin >> light[i];

    vector<int> vec[m + 5];
    vector<int> pos[n + 5];

    for (int i = 1; i <= m; i++) {
        int a;
        cin >> a;

        for (int j = 0; j < a; j++) {
            int b;
            cin >> b;
            vec[i].pb(b);
            pos[b].pb(i);
        }
    }

    queue<int> q;
    bool vis[m + 5];
    memset(vis, 0, sizeof(vis));

    for (int i = 1; i <= n; i++)
        if (!light[i]) q.push(i);

    while (!q.empty()) {
        int a = q.front();
        q.pop();
        if (light[a]) continue;

        if (!vis[pos[a][1]]) {
            vis[pos[a][1]] = 1;
            for (auto v : vec[pos[a][1]]) {
                light[v] ^= 1;
                if (!light[v]) q.push(v);
            }
            light[a] = 1;
        } else if (!vis[pos[a][0]]) {
            vis[pos[a][0]] = 1;
            for (auto v : vec[pos[a][0]]) {
                light[v] ^= 1;
                if (!light[v]) q.push(v);
            }
            light[a] = 1;
        } else {
            cout << "NO" << endl;
            return;
        }
    }

    // bool ans = 1;
    // for(int i = 1; i<=n; i++) ans &= light[i];

    // cout << (ans ? "YES" : "NO") << endl;
    cout << "YES" << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    if (mutipletestcase) cin >> t;
    while (t--) solve();
}