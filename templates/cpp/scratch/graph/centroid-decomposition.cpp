#include <bits/stdc++.h>
using namespace std;

vector<int> adj[N]  // storing edges information
    int sz[N]       // storing subree size
    bool dead[N]    // vertices not traversed during decomposition

    // taken from https://codeforces.com/blog/entry/58025

    void
    getSize(int v, int p) {
    sz[v] = 1;
    for (auto i : adj[v]) {
        if (i == p || dead[i])
            continue;
        getSize(i, v);
        sz[v] += sz[p];
    }
}

int getCentroid(int v, int p) {
    int t = sz[v];
    for (auto i : adj[v]) {
        if (i == p || dead[i])
            continue;
        if (sz[v] > t / 2)
            return getCentroid(i, v);
    }
    return v;
}

// precondition: array sz has been filled, e.g. using getSize
void centroidDecomposition(int root) {
    int c = getCentroid(root);
    dead[c] = true;
    for (auto i : adj[c]) {
        if (dead[i])
            continue;
        centroidDecomposition(i);
    }
    dead[c] = false;  // returning to normal so can be traversed (?)
}

// driver, may be updated soon
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
}
