#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2e5;
const ll INF = 1e18;

int n, m;
ll pre[N + 5], b[N + 5], c[N + 5], T[4 * N + 5];
int ar[N + 5];

void build(int v, int s, int e) {
    if (s == e) {
        T[v] = c[s];
        return;
    }
    int mid = (s + e) >> 1;
    build(v << 1, s, mid);
    build(v << 1 | 1, mid + 1, e);
    T[v] = min(T[v << 1], T[v << 1 | 1]);
}

ll get(int v, int s, int e, int l, int r) {
    if (l > r) return INF;
    if (l == s && r == e) return T[v];
    int mid = (s + e) >> 1;
    if (r <= mid) {
        return get(v << 1, s, mid, l, r);
    } else if (l >= mid + 1) {
        return get(v << 1 | 1, mid + 1, e, l, r);
    }
    return min(get(v << 1, s, mid, l, mid), get(v << 1 | 1, mid + 1, e, mid + 1, r));
}

ll floor(ll a, ll b) {
    ll q = a / b;
    if (a % b == 0) return q;
    return (a < 0 ? q - 1 : q);
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        pre[i] = pre[i - 1] + ar[i];
    }
    ll mx = *max_element(pre + 1, pre + n + 1);
    ll sum = pre[n];
    vector<pair<ll, ll>> ve;
    if (sum > 0) {
        for (int i = 1; i <= n; i++) {
            b[i] = (i - 1) - floor (pre[i], sum) * n;
        } 
        for (int i = 1; i <= n; i++) {
            ve.emplace_back(((pre[i] % sum) + sum) % sum, b[i]);
        }
        sort(ve.begin(), ve.end());
        for (int i = 1; i <= n; i++) {
            c[i] = ve[i - 1].second;
            // cerr << c[i] << ' ';
        }
        // cerr << '\n';
        build(1, 1, n);
    }
    while (m--) {
        int q;
        cin >> q;
        if (mx < q && sum <= 0) {
            cout << -1 << ' ';
            continue;
        }
        if (mx >= q) {
            for (int i = 1; i <= n; i++) {
                if (pre[i] >= q) {
                    cout << i - 1 << ' ';
                    break;
                }
            }
            continue;
        }
        ll ans;
        if (sum == 1) {
            ans = q * n + get(1, 1, n, 1, n);
        } else {
            ll sisa = q % sum;
            ll Q = (q + sum - 1) / sum;
            if (sisa == 0) Q++;
            int u = lower_bound(ve.begin(), ve.end(), make_pair(sisa, -INF)) - ve.begin() + 1;
            ll A = get(1, 1, n, u, n);
            ll B = get(1, 1, n, 1, u - 1);
            ans = min(B + Q * n, A + (Q - 1) * n); 
        }
        cout << ans << ' ';
    }
    cout << '\n';
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