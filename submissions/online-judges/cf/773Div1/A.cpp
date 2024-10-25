#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;
const int B = 30;

void el_psy_congroo() {
    ll n, x;
    cin >> n >> x;
    vector<ll> ar(n);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        ll cur = ar[i];
        int pw = 0;
        while (cur % x == 0) {
            pw++, cur /= x;
        }
        if (!mp.count(cur)) mp[cur].resize(B);
        mp[cur][pw]++;
    }
    ll ans = 0;
    for (auto e : mp) {
        ll base = e.first;
        for (int i = B - 1; i >= 0; i--) {
            if (e.second[i] == 0) continue;
            if (i == 0)
                ans += e.second[i];
            else {
                if (e.second[i] > e.second[i - 1]) {
                    ans += e.second[i] - e.second[i - 1];
                    e.second[i - 1] = 0;
                } else {
                    e.second[i - 1] -= e.second[i];
                }
            }
        }
    }
    cout << ans << '\n';
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