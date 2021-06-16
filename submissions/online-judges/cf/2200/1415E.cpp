#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, k;
ll ans;

void solve() {
    cin >> n >> k;
    vector<ll> c(n), sisa;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    sort(c.begin(), c.end(), greater<>());
    ll sum = 0;
    bool udah = 0;
    int sz = -1;
    for (int i = 0; i < n; i++) {
        if (!udah) {
            sum += c[i];
            sz = i;
            if (sum < 0) {
                udah = 1;
            }
        } else {
            sisa.emplace_back(c[i]);
        }
    }
    for (int i = 0; i <= sz; i++) {
        ans += 1LL * (sz - i) * c[i];
    }
    reverse(sisa.begin(), sisa.end());
    ll koef = 0;
    int cnt = 0;
    for (int i = 0; i < (int)sisa.size(); i++) {
        ans += koef * sisa[i];
        cnt++;
        if (cnt == k) {
            cnt = 0;
            koef++;
        }
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