#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ld = long double;
using oset = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;

int n;
oset ose;

const int N = 1e5;
const int INF = 2e9;
int ar[N + 5];
int val[N + 5];
vector<int> adj[N + 5];

void dfs(int v, int p, int dep) {
    ose.insert(make_pair(ar[v], v));
    int child = 0;
    for (int c : adj[v]) {
        if (c == p) continue;
        child++;
        dfs(c, v, dep + 1);
    }
    if (child == 0) {
        if (dep & 1) {
            val[v] = (ose.find_by_order(dep / 2))->first;
        } else {
            val[v] = ((ose.find_by_order((dep - 1) / 2))->first + (ose.find_by_order(dep / 2))->first) / 2;
        }
    } else {
        if (dep & 1) {
            val[v] = -INF;
            for (int c : adj[v]) {
                if (c == p) continue;
                val[v] = max(val[v], val[c]);
            }
        } else {
            val[v] = INF;
            for (int c : adj[v]) {
                if (c == p) continue;
                val[v] = min(val[v], val[c]);
            }
        }
    }
    ose.erase(make_pair(ar[v], v));
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, 1);
    cout << val[1] << '\n';
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