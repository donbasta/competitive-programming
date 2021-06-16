#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using iss = istringstream;

const int N = 80;
const int INF = 2e9;
int ar[N * N];
vector<pair<int, int>> adj[N * N];

void io() {
    freopen("p083_matrix.txt", "r", stdin);
    // freopen("output.out", "w", stdout);
}

int dijkstra() {
    vector<int> d(N * N, INF);
    set<pair<int, int>> se;
    d[0] = ar[0];
    se.emplace(d[0], 0);
    while (!se.empty()) {
        int v = se.begin()->second;
        se.erase(se.begin());
        for (auto e : adj[v]) {
            int to = e.first;
            int len = e.second;
            if (d[v] + len < d[to]) {
                se.erase(make_pair(d[to], to));
                d[to] = d[v] + len;
                se.emplace(d[to], to);
            }
        }
    }
    return d[N * N - 1];
}

void solve() {

    string input;
    int i = 0;
    while (getline(cin, input)) {
        iss ss(input);
        string tmp;
        while (getline(ss, tmp, ',')) {
            ar[i++] = stoi(tmp);
        }
    }

    for (int i = 0; i < N * N; i++) {
        if (i % N != 0) {
            adj[i].emplace_back(i - 1, ar[i - 1]);
        }
        if (i % N != (N - 1)) {
            adj[i].emplace_back(i + 1, ar[i + 1]);
        }
        if (i >= N) {
            adj[i].emplace_back(i - N, ar[i - N]);
        }
        if (i + N < (N * N)) {
            adj[i].emplace_back(i + N, ar[i + N]);
        }
    }

    cout << dijkstra() << '\n';

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    io();

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}