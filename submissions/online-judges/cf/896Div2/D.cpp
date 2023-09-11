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
    vector<int> in(40), out(40);
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
        in[x]++, out[y]++;
    }
    for (int i = 0; i < 40; i++) {
        if (in[i] != out[i]) {
            cout << "No" << '\n';
            return;
        }
    }
    cout << "Yes" << '\n';
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