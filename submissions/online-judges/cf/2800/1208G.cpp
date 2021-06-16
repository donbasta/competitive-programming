#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e6;
int phi[N + 5];

void init() {
    for (int i = 1; i <= N; i++) {
        phi[i] = i;
    }
    for (int i = 2; i <= N; i++) {
        if (phi[i] == i) {
            phi[i] = i - 1;
            for (int j = 2 * i; j <= N; j += i) {
                phi[j] = (phi[j] / i) * (i - 1);
            }
        }
    }
}

int n, k;

void solve() {
    cin >> n >> k;
    if (k == 1) {
        cout << 3 << '\n';
        return;
    }
    k += 2;
    sort (phi + 1, phi + n + 1);
    ll ans = accumulate(phi + 1, phi + k + 1, 0LL);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    init();

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}