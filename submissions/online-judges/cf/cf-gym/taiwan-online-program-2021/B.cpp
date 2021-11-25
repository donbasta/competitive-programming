#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a;
        a = a * a;
        b >>= 1;
    }
    return ret;
}

ll sum_div(ll t) {
    ll ret = 1;
    for (ll i = 2; i * i <= t; i++) {
        if (t % i == 0) {
            ll pw = 0;
            while (t % i == 0) {
                t /= i, pw++;
            }
            ret *= ((fpow(i, pw + 1) - 1) / (i - 1));
        }
    }
    if (t > 1) {
        ret *= (t + 1);
    }
    return ret;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int q;
        cin >> q;
        ll sum = sum_div(q) - q;
        string ret;
        if (sum == q) {
            ret = "perfect";
        } else if (sum < q) {
            ret = "deficient";
        } else if (sum > q) {
            ret = "abundant";
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