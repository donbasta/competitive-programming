#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct Tree {
    int n;
    vector<vector<int>> adj;

    Tree() {}
    Tree(int n) : n(n) {
        adj.assign(n + 1, vector<int>());
    }
    void add_edge(int a, int b){
        adj[a].pb(b);
        adj[b].pb(a);
    }
    pii dfs_furthest(int node, int p, int dist){
        pii ret = {dist, node};
        for (auto& x : adj[node]){
            if (x == p) continue;
            ret = max(ret, dfs_furthest(x, node, dist + 1));
        }
        return ret;
    }
    bool dfs_build(int node, int p, int target, vector<int>& path){
        if (node == target){
            path.pb(node);
            return 1;
        }
        bool ret = 0;
        for (auto& x : adj[node]){
            if (x == p) continue;
            if (dfs_build(x, node, target, path)){
                ret = 1;
                break;
            }
        }
        if (ret) path.pb(node);
        return ret;
    }
    vector<int> find_diameter(){
        auto a = dfs_furthest(1, 1, 0);
        auto b = dfs_furthest(a.se, a.se, 0);
        vector<int> ret;
        dfs_build(a.se, a.se, b.se, ret);
        return ret;
    }
};

int q;

void solve(){
    vector<Tree> g(2);
    for (int id=0;id<2;id++){
        int n;
        cin >> n;
        g[id] = Tree(n);
        for (int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            g[id].add_edge(a, b);
        }
    }
    auto da = g[0].find_diameter();
    auto db = g[1].find_diameter();
    int diam_a = (int)da.size() - 1;
    int diam_b = (int)db.size() - 1;
    cout << (diam_a + 1) / 2 + (diam_b + 1) / 2 + 1 << el;
    cout << da[da.size() / 2] << " " << db[db.size() / 2] << el; 
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}