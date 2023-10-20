#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    vector<int> c(n + m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    for (int i = 0; i < n; i++) c[i] = a[i];
    for (int i = n; i < m + n; i++) c[i] = b[i - n];
    sort(c.begin(), c.end());
    multiset<int> A1, A2, B1, B2;
    for (int i = 0; i < n; i++) {
        if (a[i] <= c[n - 1])
            A1.insert(a[i]);
        else
            A2.insert(a[i]);
    }
    for (int i = 0; i < m; i++) {
        if (b[i] >= c[n])
            B1.insert(b[i]);
        else
            B2.insert(b[i]);
    }
    assert(A2.size() == B2.size());
    int sz = A2.size();
    for (int i = 1; i <= min(sz, (k / 2)); i++) {
        if (A1.empty() || B2.empty() || *A1.begin() > *B2.begin()) {
            int x = *A2.rbegin(), y = *B2.begin();
            B1.insert(x), A1.insert(y);
            A2.erase(A2.find(x)), B2.erase(B2.find(y));
        }
    }
    vector<int> A, B;
    for (auto e : A1) A.push_back(e);
    for (auto e : A2) A.push_back(e);
    for (auto e : B1) B.push_back(e);
    for (auto e : B2) B.push_back(e);
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    ll ans = 0;
    for (auto e : A) ans += e;
    if (k & 1) {
        int mn = *min_element(A.begin(), A.end());
        int mx = *max_element(B.begin(), B.end());
        if (mn < mx) {
            ans += (mx - mn);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}