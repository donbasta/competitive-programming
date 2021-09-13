#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, m;

const int N = 2e5;

int par[N + 5];
int sz[N + 5];

void init() {
    for(int i = 1; i <= N; i++){
        par[i] = i;
        sz[i] = 1;
    }
}

int fpar(int a) { return (a == par[a] ? a : par[a] = fpar(par[a])); }

void merge(int a, int b) {
    a = fpar(a);
    b = fpar(b);
    if (a != b) {
        if (sz[a] < sz[b]) {
            swap(a, b);
        }
        par[b] = a;
        sz[a] += sz[b];
    }
}

void solve() {
    init();
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> ve;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        ve.emplace_back(c, make_pair(a, b));
    }
    sort(ve.begin(), ve.end());
    int done = 0;
    ll reward = 0;
    for (int i = 0; i < m; i++) {
        int a = ve[i].second.first;
        int b = ve[i].second.second;
        if ((fpar(a) == fpar(b)) && ve[i].first > 0) {
            reward += ve[i].first;
        }
        merge(a, b);
        if (sz[fpar(a)] == n) {
            done = i;
            break;
        }
    }
    for (int i = done + 1; i < m; i++) {
        if (ve[i].first < 0) continue;
        else reward += ve[i].first;
    }
    cout << reward << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}