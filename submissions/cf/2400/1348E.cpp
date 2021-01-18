#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 500;
const ll INF = 1e18;

int n, k;
ll a[N + 5], b[N + 5];
ll dp[N + 5][N + 5];
ll sum;

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            dp[i][j] = -INF;
        }
    }
    for (int i = 0; i < k; i++) {
        if (i > a[0]) break;
        int bb = (k - ((a[0] - i) % k)) % k;
        if (bb <= b[0]) {
            dp[0][i] = (a[0] + b[0] - i - ((b[0] - bb) % k)) / k;
        }
    }
    sum = a[0] + b[0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (j > a[i]) break;
            int jj = (a[i] + b[i] - j) % k;
            if (jj > b[i]) continue;
            for (int l = 0; l < k; l++) {
                int ll = ((sum - l) % k);
                if (ll < 0) ll += k;
                dp[i][(j + l) % k] = max(dp[i][(j + l) % k], ((a[i] + b[i] - j - jj) / k) + dp[i - 1][l] + ((j + l) >= k) + ((jj + ll) >= k));
            }
        }
        sum += (a[i] + b[i]);
    }
    cout << *max_element(dp[n - 1], dp[n - 1] + k) << '\n';
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