#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MX = 9e18;

ll v5(ll m) {
    ll pw = 5;
    ll ret = 0;
    while (pw <= m) {
        ret += m / pw;
        if (pw > MX / 5) {
            break;
        }
        pw = (pw * 5);
    }
    return ret;
}

void solve() {
    ll n;
    cin >> n;
    ll le = 0, ri = MX;
    ll ans = -1;
    while (le <= ri) {
        ll mid = (le + ri) / 2;
        ll pw = v5(mid);
        if (pw > n) {
            ri = mid - 1;
        } else if (pw == n) {
            // cerr << mid << '\n';
            ans = mid;
            break;
        } else if (pw < n) {
            le = mid + 1;
        }
    }
    if (ans == -1) {
        cout << -1 << '\n';
        return;   
    }
    ans = (ans / 5) * 5;
    for (ll i = ans; i < ans + 5; i++) {
        cout << i << ' ';
    }
    cout << '\n';
    return;
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