#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MX = 500;

int N, q;
ll p[MX + 5];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> p[i];
    }
    cin >> q;
    while (q--) {
        int n, m;
        cin >> n >> m;
        if (n < m) {
            cout << "impossible\n";
            continue;
        }
        int a = n / m;
        int b = n % m;
        ll ans = p[a] * (m - b) + p[a + 1] * (b);
        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("jacking.in", "r", stdin);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        cout << "Case " << i << ":\n";
        solve();
    }
  
    return 0;
}