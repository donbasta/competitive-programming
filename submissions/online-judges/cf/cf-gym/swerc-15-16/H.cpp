#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int M = 63;
const ll MX = LLONG_MAX;

ll get(ll a) {
    unordered_map<ll, bool> udah;
    ll ans = 0;
    if (a == MX) {
        udah[a] = true;
        ans++;
        a--;
    }
    for (int i = 1; i <= 62; i++) {
        for (int j = 1; j <= 62; j++) {
            ll base = (1LL << i) - 1;
            ll cur = base;
            int id = 0;
            int len = i;
            while (cur <= a) {
                assert(cur > 0);
                if (!udah[cur]) {
                    ans++;
                }
                udah[cur] = true;
                if (id % 2 == 0) {
                    len += j;
                    if (len <= M) {
                        cur <<= j;    
                    }
                } else {
                    len += i;
                    if (len <= M) {
                        cur = (cur << i) + base;
                    }
                }
                if (len > M) {
                    break;
                }
                id++;
            }
        }
    }
    return ans;
}

void solve() {
    ll X, Y;
    cin >> X >> Y;
    ll YY = get(Y);
    ll XX = (X ? get(X - 1) : 0);
    cout << YY - XX << '\n';
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