#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, k;
const int INF = 1e5;
const int N = 1e4;

int tree[4 * N + 10];

void upd(int v, int s, int e, int l, int r) {
    if (l == s && e == r) {
        
    } 
}

int get(int v, int s, int e, int l, int r) {
    if (s == l && e == r) return tree[v];
    push(v);
    int mid = (s + e) >> 1;
    if (r <= mid) return get(v << 1, s, mid, l, r);
    else if (l >= mid + 1) return get(v << 1 | 1, mid + 1, e, l, r);
    return max(get(v << 1, s, mid, l, mid), get(v << 1 | 1, mid + 1, e, mid + 1, r));
}

void solve() {
    cin >> n >> k;
    vector<int> c(n * k);
    vector<vector<int>> ve(n);
    for (int i = 0; i < n * k; i++) {
        cin >> c[i];
        --c[i];
        ve[c[i]].push_back(i);
    }
    vector<pair<int, int>> ans;
    vector<tuple<int, int, int>> pos;
    for (int i = 0; i < n; i++) {
        int mn = INF;
        for (int j = 1; j < k; j++) {
            mn = min(mn, ve[i][j] - ve[i][j - 1]);
        }
        for (int j = 1; j < k; j++) {
            if (ve[i][j] - ve[i][j - 1] == mn) {
                pos.emplace_back(ve[i][j - 1], ve[i][j], i);
            }
        }
    }
    sort (pos.begin(), pos.end());
    vector<bool> udah(n, false);
    vector<pair<int, int>> ans(n);
    int mx = 0;
    int bound = (n + k - 2) / (k - 1);
    int pr = -1;
    for (auto e : pos) {
        int a = get<0>(e), b = get<1>(e), c = get<2>(e);
        if (udah[c]) continue;
        mx = get(1, 0, n * k - 1, a, b);
        if (mx + 1 <= bound) {
            ans[c] = make_pair(a, b);
            udah[c] = true;
            upd(1, 0, n * k - 1, a, b, 1);
        }
    }
    for (auto e : ans) {
        cout << e.first + 1 << ' ' << e.second + 1 << '\n';
    }
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