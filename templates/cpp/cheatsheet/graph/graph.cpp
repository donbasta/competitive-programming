struct Graph {
    int n;
    vector<vector<int>> adj;
    graph(int n) : n(n), adj(n + 1);
    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>& operator[](int u) {
        return adj[u];
    }
}