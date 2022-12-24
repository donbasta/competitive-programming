void dfs(int v, int p) {
    vis[v] = 1;
    tin[v] = low[v] = timer++;
    int ch = 0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (vis[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p != -1) {
                se.insert(v);
            }
            ++ch;
        }
    }
    if (p == -1 && ch > 1) {
        se.insert(v);
    }
}