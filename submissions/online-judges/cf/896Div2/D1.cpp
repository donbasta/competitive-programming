#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

pair<ll, ll> is_diff_power_of_two(ll x) {
    if (x == 0) return make_pair(0, 0);
    ll bawah = 0, atas = 0;
    while (x % 2 == 0) {
        x >>= 1, bawah++;
    }
    x += 1;
    if (__builtin_popcountll(x) > 1) {
        return make_pair(-1, -1);
    }
    while (x % 2 == 0) {
        x >>= 1, atas++;
    }
    atas += bawah;
    return make_pair(atas, bawah);
}

void solve() {
    int n;
    cin >> n;
    vector<ll> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    ll sum = accumulate(ar.begin(), ar.end(), 0ll);
    if (sum % n != 0) {
        cout << "No" << '\n';
        return;
    }
    ll avg = sum / n;
    // cerr << avg << '\n';
    vector<int> in(40), out(40), outt(40), inn(40);
    int IN = 0, OUT = 0;
    int spe = 0;
    for (int i = 0; i < n; i++) {
        ll sel = avg - ar[i];
        if (sel == 0) continue;
        pair<ll, ll> lol = is_diff_power_of_two(abs(sel));
        if (lol.first == -1) {
            cout << "No" << '\n';
            return;
        }
        ll x = lol.first, y = lol.second;  // 2^x-2^y = abs(sel)
        if (sel < 0) swap(x, y);
        out[x]++, in[y]++;
        if (x - y == 1) {
            spe++;
            outt[y]++, IN++;
        } else if (y - x == 1) {
            spe++;
            inn[x]++, OUT++;
        }
    }
    // cerr << "SPE " << spe << '\n';
    bool ok = true;
    for (int i = 0; i < 40; i++) {
        ok &= (in[i] == out[i]);
    }
    if (ok) {
        cout << "Yes" << '\n';
        return;
    }
    int tmp = 0;
    for (int i = 0; i < 32; i++) {
        // if (i <= 4) {
        //     cerr << i << ' ' << in[i] << ' ' << out[i] << ' ' << inn[i] << ' ' << outt[i] << '\n';
        //     cerr << i << ' ' << abs(in[i] + inn[i] - out[i] - outt[i]) << '\n';
        // }
        ll u;
        if (out[i] < in[i]) {
            u = min((out[i] + in[i]) / 2, out[i] + outt[i] - inn[i]);
            if (out[i] + outt[i] - inn[i] < ((out[i] + in[i]) / 2)) {
                IN -= outt[i];
            } else {
                IN -= ((out[i] + in[i]) / 2) - (out[i] - inn[i]);
            }
        } else {
            u = min((out[i] + in[i]) / 2, in[i] + inn[i] - outt[i]);
            if (in[i] + inn[i] - outt[i] < ((out[i] + in[i]) / 2)) {
                OUT -= inn[i];
            } else {
                OUT -= ((out[i] + in[i]) / 2) - (in[i] - outt[i]);
            }
        }
        tmp += (in[i] + inn[i] + out[i] + outt[i]) - 2ll * u;
    }
    // cerr << IN << ' ' << OUT << '\n';
    tmp += abs(IN - OUT);
    // cerr << "TMP " << tmp << '\n';
    if (tmp == spe * 2) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}