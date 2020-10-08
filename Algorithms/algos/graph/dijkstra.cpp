

//Pre-condition:

//1. array dist is initialized with value INF (large number)
//2. par is optional, just to get the vertices of the shortest path

void dijkstra(int start) {
	using pii = pair<int, int>;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(make_pair(0, start));
	d[start] = 0;
	while(!pq.empty()) {
		int v = pq.top().second;
		int dv = pq.top().first;
		pq.pop();
		if(dv != d[v])
			continue;
		for(auto i : adj[v]) {
			int to = i.first;
			int dist = i.second;
			if(d[to] > d[v] + dist) {
				d[to] = d[v] + dist;
				par[to] = v;
				pq.push(make_pair(d[to], to));
			}
		}
	}
}