#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2000;

int par[N + 5];
int sz[N + 5];

void init(int x) {
    for (int i = 0; i < x; i++) { par[i] = i, sz[i] = 1; }
}

int fpar(int x) {
    return x == par[x] ? x : par[x] = fpar(par[x]);
}

void merge(int x, int y) {
    x = fpar(x), y = fpar(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);
    sz[x] += y;
    par[y] = x;
}

int w, n;

void solve() {
    cin >> w >> n;
    vector<tuple<int, int, int>> sensors(n); //x, y, radius
    for (auto& [x, y, r] : sensors) {
        cin >> x >> y >> r;
    }
    vector<tuple<ld, int, int>> edges; //dis, id, id
    const int L = n, R = n + 1;
    for (int i = 0; i < n; i++) {
        auto [x, y, r] = sensors[i];
        ld dl = x - r;
        if (dl < 0) dl = 0;
        ld dr = w - x - r;
        if (dr < 0) dr = 0;
        edges.emplace_back(dl, i, L);
        edges.emplace_back(dr, i, R);
    }
    init(n + 2);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            auto [x1, y1, r1] = sensors[i];
            auto [x2, y2, r2] = sensors[j];
            ld dist = hypot(x1 - x2, y1 - y2) - r1 - r2;
            if (dist < 0) dist = 0;
            edges.emplace_back(dist, i, j);
        }
    }
    edges.emplace_back(w, L, R);
    cout << fixed << setprecision(9);
    sort(edges.begin(), edges.end());
    for (auto [dist, i, j] : edges) {
        // cerr << dist << ' ' << i << ' ' << j << '\n';
        merge(i, j);
        if (fpar(L) == fpar(R)) {
            cout << dist / 2 << '\n';
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}