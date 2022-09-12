int bfs (int s, int t, vector<int>& par) {
    fill(par.begin(), par.end(), -1);
    par[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int nxt : adj[cur]) {
            if (par[nxt] == -1 && cap[cur][nxt]) {
                par[nxt] = cur;
                int new_flow = min(flow, cap[cur][nxt]);
                if (nxt == t) {
                    return new_flow;
                }
                q.emplace(nxt, new_flow);
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> par(n);
    int new_flow;

    while (new_flow = bfs(s, t, par)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prv = par[cur];
            cap[prv][cur] -= new_flow;
            cap[cur][prv] += new_flow;
            cur = prv;
        }
    }

    return flow;
}
