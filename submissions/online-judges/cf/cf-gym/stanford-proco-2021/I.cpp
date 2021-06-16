#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 5e5;
ll ar[N + 10];
ll tot, n;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        tot += ar[i];
    }
    ll avg = tot / n;
    for (int i = 1; i <= n; i++) {
        ar[i] -= avg;
    }
    ll pre = 0;
    map<ll, int> mp;
    for (int i = 1; i <= n; i++) {
        pre += ar[i];
        mp[pre]++;
    }
    int ans = -1;
    for (auto el : mp) {
        ans = max(ans, el.second);
    }
    cout << n - ans << '\n';
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