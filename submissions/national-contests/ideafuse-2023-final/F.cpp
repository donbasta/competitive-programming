#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n), s(m), sz(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        --p[i];
        if (i > 0) {
            adj[i].push_back(p[i]);
            adj[p[i]].push_back(i);
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> s[i];
        --s[i];
    }
    vector<int> grundy(n);
    const function<void(int, int)> dfs = [&](int v, int p) {
        set<int> se;
        sz[v] = 1;
        for (auto c : adj[v]) {
            if (c == p) continue;
            dfs(c, v);
            sz[v] += sz[c];
            se.insert(grundy[c]);
        }
        int i = 0;
        while (se.count(i)) i++;
        grundy[v] = i;
    };
    dfs(0, 0);
    vector<int> movable;
    int cnt_movable_zero = 0, cnt_leaf = 0;
    for (int i = 0; i < m; i++) {
        if (sz[s[i]] == 1) {
            cnt_leaf++;
            continue;
        }
        movable.push_back(s[i]);
        if (grundy[s[i]] == 0) {
            cnt_movable_zero++;
        }
    }

    string names[] = {"IKRO", "OSKI"};
    if (movable.empty()) {
        cout << names[1] << '\n';
        return;
    }
    int cnt_zero = cnt_leaf + cnt_movable_zero;
    if (cnt_zero >= 2) {
        cout << names[1] << '\n';
        return;
    }
    int ks = 0;
    for (auto c : movable) ks ^= grundy[c];
    string winner;
    if (ks == 0) {
        if ((cnt_zero) == 1) {
            winner = names[0];
        } else if (cnt_zero >= 2) {
            winner = names[1];
        } else if (cnt_zero == 0) {
            set<int> se;
            for (auto c : movable) se.insert(grundy[c]);
            if (se.size() == 1) {
                winner = names[1];
            } else {
                winner = names[0];
            }
        }
    } else {
        bool ada_T = false;
        for (auto c : movable) {
            if (grundy[c] == ks) ada_T = true;
        }
        if (ada_T && (cnt_zero == 0)) {
            winner = names[0];
        } else {
            if (cnt_leaf == 0) {
                if ((cnt_zero) >= 2) {
                    winner = names[1];
                } else if ((cnt_zero) == 1) {
                    // winner = names[0];
                    winner = names[1];
                    int cek = -1;
                    for (auto c : movable) {
                        if (grundy[c] == 0) {
                            cek = c;
                        }
                    }
                    assert(cek != -1);
                    for (auto c : adj[cek]) {
                        if (c == p[cek]) continue;
                        if (grundy[c] == ks) {
                            winner = names[0];
                            break;
                        }
                    }
                } else {
                    winner = names[0];
                    // set<int> tmp;
                    // for (auto c : movable) {
                    //     tmp.insert(grundy[c]);
                    // }
                    // int m_sz = movable.size();
                    // if (tmp.size() == 1 && (m_sz & 1)) {
                    //     winner = names[1];
                    // } else {
                    //     winner = names[0];
                    // }
                }
            } else {
                winner = names[1];
            }
        }
    }
    cout << winner << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}