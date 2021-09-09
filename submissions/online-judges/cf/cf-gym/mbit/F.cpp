#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll mod = 1e9 + 7;
const int N = 1e6;

set<int> se;
vector<int> ve, sz;
map<int, bool> vis;
map<int, int> nx;

int n, k;
ll f[N + 5];

void init_fibo() {
    f[1] = 2, f[2] = 3;
    for (int i = 3; i <= N; i++) {
        f[i] = (f[i - 1] + f[i - 2]) % mod;
    }
}

void solve() {
    init_fibo();

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;
        ve.emplace_back(id);
        se.insert(id);
    }
    for (auto e : ve) {
        if (se.count(e + k)) {
            nx[e] = e + k;
        }
    }
    sort(ve.begin(), ve.end());
    for (int i = 0; i < n; i++) {
        if (vis[ve[i]]) continue;
        int cnt = 1;
        int now = ve[i];
        while (nx.find(now) != nx.end()) {
            cnt++;
            vis[now] = true;
            now = nx[now];
        }
        vis[now] = true;
        sz.emplace_back(cnt);
    }

    // for (int i = 0; i < n; i++) {
    //     cerr << ve[i] << ' ' << nx[ve[i]] << '\n';
    // }

    ll ans = 1;
    for (auto e : sz) {
        ans = (ans * f[e]) % mod;
    }
    ans = (ans - 1) % mod;
    if (ans < 0) ans += mod;
    cout << ans << '\n';
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