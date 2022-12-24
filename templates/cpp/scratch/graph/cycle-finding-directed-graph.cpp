#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

// Adjacency list for each node
vector<int> adj[N + 5];

// Check whether a node is already visited or not
bool vis[N + 5];

// 0 if not visited, 1 if in stack, 2 if already left
int cur[N + 5];

// Global variable stating if the graph is acyclic or not
bool adaCycle;

void dfs(int node) {
    vis[node] = true;
    cur[node] = 1;
    for (auto i : adj[node]) {
        if (cur[i] == 1) {
            adaCycle = true;
        }
        if (!vis[i]) {
            dfs(i);
        }
    }
    cur[node] = 2;
}
