#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;
const int N = 2e5;
const ll INF = 1e18;

ll x, y;
ll ar[N + 5];
ll sum;

ll f(int idx) {
    return ((x - sum + y) + abs(x - ar[idx]) + abs(sum - y - ar[idx])) / 2;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        sum += ar[i];
    }
    sort(ar + 1, ar + n + 1);
    int m;
    cin >> m;
    while (m--) {
        cin >> x >> y;
        int a = lower_bound(ar + 1, ar + n + 1, x) - (ar);
        int b = lower_bound(ar + 1, ar + n + 1, sum - y) - (ar);
        int c = upper_bound(ar + 1, ar + n + 1, x) - (ar);
        int d = upper_bound(ar + 1, ar + n + 1, sum - y) - (ar);
        ll ret = INF;
        if ((a < d) || (b < c)) {
            ret = max(0LL, (x + y - sum));
        } else if (x <= sum - y) {
            if (d <= n) ret = min(ret, f(d));
            if (a > 1) ret = min(ret, f(a - 1));
        } else if (x >= sum - y) {
            if (c <= n) ret = min(ret, f(c));
            if (b > 1) ret = min(ret, f(b - 1));
        }
        cout << ret << '\n';
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