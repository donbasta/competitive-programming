#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int B = 60;

void el_psy_congroo() {
    int n, q;
    cin >> n >> q;
    vector<ll> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    while (q--) {
        ll k;
        cin >> k;
        ll ret = 0;
        vector<ll> cp = ar;
        for (int i = B - 1; i >= 0; i--) {
            int cnt = 0;
            ll need = 0;
            for (int j = 0; j < n; j++) {
                int cur = ((cp[j] >> i) & 1);
                cnt += cur;
                if (cur == 0) {
                    need += ((1ll << i) - (cp[j] & ((1ll << i) - 1)));
                    if (need > k) {
                        break;
                    }
                }
            }
            if (cnt == n) {
                ret ^= (1ll << i);
            } else {
                if (need <= k) {
                    k -= need;
                    for (int j = 0; j < n; j++) {
                        int cur = ((cp[j] >> i) & 1);
                        if (cur == 0) {
                            cp[j] += ((1ll << i) - (cp[j] & ((1ll << i) - 1)));
                        }
                    }
                    ret ^= (1ll << i);
                }
            }
        }
        cout << ret << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}