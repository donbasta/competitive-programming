#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int N = 1e3;
int ar[N + 5][N + 5];
 
int n, m, k, p;
 
void solve() {
    cin >> n >> m >> k >> p;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ar[i][j];
        }
    }
    vector<ll> A(k + 1), B(k + 1);
    priority_queue<ll> R, C;
    for (int i = 0; i < n; i++) {
        ll tmp = 0;
        for (int j = 0; j < m; j++) {
            tmp += ar[i][j];
        }
        R.emplace(tmp);
    }
    for (int i = 0; i < m; i++) {
        ll tmp = 0;
        for (int j = 0; j < n; j++) {
            tmp += ar[j][i];
        }
        C.emplace(tmp);
    }
    for (int i = 1; i <= k; i++) {
        A[i] = A[i - 1] + R.top();
        ll tmp = R.top();
        R.pop();
        tmp -= 1LL * p * m;
        R.push(tmp);
    }
    for (int i = 1; i <= k; i++) {
        B[i] = B[i - 1] + C.top();
        ll tmp = C.top();
        C.pop();
        tmp -= 1LL * p * n;
        C.push(tmp);
    }
    ll ans = -1e18;
    for (int i = 0; i <= k; i++) {
        ans = max(ans, A[i] + B[k - i] - 1LL * (k - i) * i * p);
    }
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