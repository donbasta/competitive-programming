#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int L = 20;

int n, m, q;
vector<int> adj[N];
// int tin[N], low[N], timer = 0;
bool visited[N], cut[N];

int tin[N], low[N], comp[N];
int timer, compNum;
vector<int> st;

void dfs_scc(int node, int p){
    st.push_back(node);
    tin[node] = low[node] = ++timer;
    for (auto x : adj[node]){
        if (x == p) continue;
        if (tin[x]){
            low[node] = min(low[node], tin[x]); 
        } else {
            dfs_scc(x, node);
            low[node] = min(low[node], low[x]);
        }
    }
    if (low[node] == tin[node]){
        compNum++;
        while (st.back() != node){
            comp[st.back()] = compNum;
            st.pop_back();
        }
        comp[st.back()] = compNum;
        st.pop_back();
    }
}
void tarjan(){
    for (int i=1;i<=n;i++){
        tin[i] = low[i] = comp[i] = 0;
    }
    timer = compNum = 0;
    st.clear();
    for (int i=1;i<=n;i++){
        if (tin[i] == 0){
            dfs_scc(i, i);
        }
    }
}

void dfs(int u, int p = -1) {
    visited[u] = true;
    tin[u] = low[u] = timer++;
    int children = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (visited[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (tin[u] <= low[v] && u != p)
                cut[u] = 1;
            ++children;
        }
    }
    if (p == u && children > 1){
        cut[u] = 1;
    }
}

void CUT() {
    timer = 0;
    for (int i = 1; i <= n; i++) {
        tin[i] = low[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        dfs(i, i);
    }
}

int ask(int u, int v) {
    int ret = 0;

    return ret;
}

using pii = pair<int, int>;

const int M = 3e3 + 10;
const int INF = 1e9;

int dist[M][M];

void dijkstra(){
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (i != j) dist[i][j] = INF;
        }
    }

    for (int sc=1;sc<=n;sc++){
        set<pii> setdah;
        setdah.insert({0, sc});

        while (!setdah.empty()){
            auto tp = *setdah.begin();
            setdah.erase(tp);

            int node = tp.second;
            int cur = tp.first;
            for (auto x : adj[node]){
                int tam = 0;
                if (node != sc && cut[node] && comp[node] != comp[x]){
                    tam = 1;
                }
                if (dist[sc][x] > cur + tam){
                    setdah.erase({dist[sc][x], x});
                    dist[sc][x] = cur + tam;
                    setdah.insert({dist[sc][x], x});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = make_pair(u, v);
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    // debug() << imie(edges);
    CUT();
    tarjan();
    dijkstra();

    cin >> q;
    while (q--){
        int a, b;
        cin >> a >> b;
        
        if (dist[a][b] >= INF){
            cout << 2 << '\n';
            continue;
        }

        if (comp[a] == comp[b]){
            cout << 2 << '\n';
            continue;
        }

        int ans = dist[a][b] + 2;
        cout << ans << '\n';

    }

    for(int i = 1; i <= n; i++) {
        cerr << i << ' ' << comp[i] << '\n';
    }


    return 0;
}