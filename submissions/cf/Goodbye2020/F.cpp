#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, m;
const int mod = 1e9 + 7;
const int N = 5e5;

int p[N + 10], sz[N + 10];
bool ok[N + 10], nope[N + 10], gaboleh[N + 10];

vector<pair<int, int>> ve;
vector<int> Ans;
vector<int> udah[N + 10];

ll fpow (ll a, ll b, ll c) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % c;
        a = a * a % c;
        b >>= 1;
    }
    return ret;
}

void init () {
    for (int i = 0; i <= m; i++) {
        sz[i] = 1, p[i] = i;
    }
}

int fpar (int a) {
    return (p[a] == a ? p[a] : p[a] = fpar (p[a]));
}

bool merge (int a, int b) {
    int pa = fpar (a), pb = fpar (b);
    if (pa == pb) return false;
    if (sz[pa] > sz[pb]) swap (pa, pb);
    p[pa] = pb;
    sz[pb] += sz[pa];
    return true;
}

void solve() {
    cin >> n >> m;
    init ();
    for (int i = 0; i < n; i++) {
        int k, a, b;
        cin >> k;
        if (k == 1) {
            cin >> a;
            ve.emplace_back(a, 0);
        } else {
            cin >> a >> b;
            ve.emplace_back(a, b);
        }
    }

    for (int i = 0; i < n; i++) {
        int a = ve[i].first, b = ve[i].second;
        if (merge(a, b)) {
            Ans.emplace_back(i + 1);
        }
    }

    int ans = (int)Ans.size();
    ll Tot = fpow(2, ans, mod);

    cout << Tot << ' ' << ans << '\n';
    for (auto e : Ans) {
        cout << e << ' ';
    }
    cout << '\n';
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