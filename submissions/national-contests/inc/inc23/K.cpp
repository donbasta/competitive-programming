#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    ll n, d;
    cin >> n >> d;
    vector<ll> cc(n);
    for (int i = 0; i < n; i++) {
        cin >> cc[i];
    }
    if (n == 1) {
        cout << (d * d * cc[0]) << '\n';
        return;
    }
    ll lo = 1, hi = 1e12;
    ll piv = -1;
    while (lo <= hi) {
        ll mid = (lo + hi) >> 1;
        ll cnt = 0;
        for (int i = 0; i < n; i++) {
            ll tmp = mid / cc[i];
            if (tmp == 0) {
                continue;
            }
            if (tmp % 2 == 0) tmp--;
            ll x = (tmp + 1) / 2;
            cnt += x;
        }
        if (cnt >= d) {
            piv = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    ll jwb = 0;
    ll cur_size = 0;
    vector<ll> sisa;
    for (int i = 0; i < n; i++) {
        ll tmp = piv / cc[i];
        if (tmp == 0) continue;
        if (tmp % 2 == 0) tmp--;
        tmp = (tmp + 1) / 2;
        jwb += (tmp - 1) * (tmp - 1) * cc[i];
        cur_size += (tmp - 1);
        sisa.emplace_back((tmp * 2 - 1) * cc[i]);
    }
    sort(sisa.begin(), sisa.end());
    int idx = 0;
    while (cur_size < d) {
        jwb += sisa[idx++];
        cur_size++;
    }

    cout << jwb << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}