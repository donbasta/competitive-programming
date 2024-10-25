#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;
const int N = 1e6 + 1;
deque<int> de[N];
vector<int> adj[N];
int mx_idx[N], mx[N];

void dfs(int v, int p) {
    de[v].push_back(1);
    mx[v] = 1;
    mx_idx[v] = 0;
    for (auto c : adj[v]) {
        if (c == p) continue;
        dfs(c, v);
        if (de[c].size() > de[v].size()) {
            de[c].swap(de[v]);
            de[v].push_front(1);
            if (mx[c] > 1) {
                mx[v] = mx[c];
                mx_idx[v] = mx_idx[c] + 1;
            }
            for (int i = 1; i < de[c].size(); i++) {
                de[v][i] += de[c][i];
                if (de[v][i] > mx[v]) {
                    mx[v] = de[v][i];
                    mx_idx[v] = i;
                } else if (de[v][i] == mx[v]) {
                    mx_idx[v] = min(mx_idx[v], i);
                }
            }
        } else {
            for (int i = 0; i < de[c].size(); i++) {
                if (i == (int)de[c].size() - 1 && de[v].size() == de[c].size()) {
                    de[v].push_back(de[c][i]);
                } else {
                    de[v][i + 1] += de[c][i];
                }
                if (de[v][i + 1] > mx[v]) {
                    mx[v] = de[v][i + 1];
                    mx_idx[v] = i + 1;
                } else if (de[v][i + 1] == mx[v]) {
                    mx_idx[v] = min(mx_idx[v], i + 1);
                }
            }
        }
        de[c].clear();
    }
}

void el_psy_congroo() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(0, 0);
    for (int i = 0; i < n; i++) {
        cout << mx_idx[i] << '\n';
    }
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