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
    vector<int> need(n);
    for (int i = 0; i < n; i++) {
        need[i] = (s[i] - '0');
    }
    vector<int> ar(n, -1), in(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        --ar[i];
        in[ar[i]]++;
        if (ar[ar[i]] == i) continue;
        adj[i].push_back(ar[i]);
        adj[ar[i]].push_back(i);
    }

    vector<bool> is_cyc(n);
    vector<bool> vis(n), proc(n);
    vector<int> K;
    vector<int> cur_ver;

    const function<void(int)> dfs = [&](int v) -> void {
        cur_ver.push_back(v);
        proc[v] = true;
        for (auto c : adj[v]) {
            if (proc[c]) continue;
            dfs(c);
        }
    };

    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (proc[i]) continue;

        vector<int> cycle;
        cur_ver.clear();

        int cur = i;
        while (!vis[cur]) {
            vis[cur] = true;
            cur = ar[cur];
        }
        while (!is_cyc[cur]) {
            cycle.push_back(cur);
            is_cyc[cur] = true;
            cur = ar[cur];
        }

        dfs(i);
        queue<int> Q;
        for (auto x : cur_ver) {
            if (in[x] == 0) Q.push(x);
        }

        int ret = 0;
        vector<int> P;
        while (!Q.empty()) {
            auto now = Q.front();
            Q.pop();
            ret += need[now];
            if (need[now] == 1) {
                P.push_back(now);
            }
            need[ar[now]] ^= need[now];
            --in[ar[now]];
            if ((!is_cyc[ar[now]]) && (in[ar[now]] == 0)) {
                Q.push(ar[now]);
            }
        }
        int cek = 0;
        for (auto e : cycle) cek += need[e];
        if (cek & 1) {
            cout << -1 << '\n';
            return;
        }
        int sz = cycle.size();
        int tmp = 0;
        int last = 0;
        vector<int> R[2];
        R[0].push_back(cycle[0]);
        for (int i = 1; i < sz; i++) {
            last = last ^ need[cycle[i]];
            R[last].push_back(cycle[i]);
            tmp += last;
        }
        assert((last == need[cycle[0]]));
        int choose = -1;
        if (tmp < sz - tmp) {
            choose = 1;
        } else {
            choose = 0;
        }
        ret += min(tmp, sz - tmp);
        ans += ret;
        for (auto e : P) {
            K.push_back(e);
        }
        for (auto e : R[choose]) {
            K.push_back(e);
        }
    }

    cout << ans << '\n';
    for (auto e : K) {
        cout << (e + 1) << ' ';
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