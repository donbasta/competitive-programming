#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> col(n);
    for (int i = 0; i < n; i++) {
        cin >> col[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<ll> ret(n), sum_max(n), cnt_max(n);
    const function<map<int, int>(int, int)> dfs = [&](int v, int p) -> map<int, int> {
        map<int, int> mp;
        mp[col[v]] = 1;
        int cur_mx = 1;
        ll sum_mx = col[v];
        for (auto c : adj[v]) {
            if (c == p) continue;
            map<int, int> tmp = dfs(c, v);
            if (tmp.size() > mp.size()) {
                mp.swap(tmp);
                cur_mx = cnt_max[c];
                sum_mx = sum_max[c];
            }
            for (auto c : tmp) {
                mp[c.first] += c.second;
                if (mp[c.first] == cur_mx)
                    sum_mx += c.first;
                else if (mp[c.first] > cur_mx) {
                    cur_mx = mp[c.first];
                    sum_mx = c.first;
                }
            }
        }
        sum_max[v] = sum_mx;
        cnt_max[v] = cur_mx;
        ret[v] = sum_mx;
        return mp;
    };
    dfs(0, 0);
    for (int i = 0; i < n; i++) {
        cout << ret[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}