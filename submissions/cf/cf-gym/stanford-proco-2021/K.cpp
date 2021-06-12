#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, k;
string s;

const int N = 1e6;
int b[N + 5];

void solve() {
    cin >> n >> k >> s;
    for (int i = 1; i <= n; i++) {
        b[i] = b[i - 1] + (s[i - 1] == 'B');
    }
    b[n + 1] = b[n];
    int ans = -1;
    for (int i = n + 1; i >= 1; i--) {
        int cur = b[n + 1] - b[i - 1];
        if (cur > k) break;
        int id = (upper_bound(b + 1, b + i, k - cur) - b);
        id--;
        int tot = id + (n - (i - 1));
        int bl = cur + b[id];
        ans = max(ans, tot - bl);
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