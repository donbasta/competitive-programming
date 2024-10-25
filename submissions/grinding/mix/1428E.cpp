#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n, k;
    cin >> n >> k;
    vector<ll> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ar[i] * ar[i];
    }

    auto cost = [&](int part, int idx) -> ll {
        int res = ar[idx] % part;
        ll q = ar[idx] / part;
        ll ret = q * q * (part - res) + (q + 1) * (q + 1) * (res);
        return ret;
    };

    int piece = n;
    priority_queue<tuple<ll, int, int>> pq;  // cost, idx, part
    for (int i = 0; i < n; i++) {
        if (ar[i] > 1) {
            pq.emplace(cost(1, i) - cost(2, i), i, 1);
        }
    }
    while (piece < k) {
        auto x = pq.top();
        pq.pop();
        int idx = get<1>(x), cur_piece = get<2>(x);
        piece++;
        sum -= get<0>(x);
        if (cur_piece + 2 <= ar[idx]) {
            pq.emplace(cost(cur_piece + 1, idx) - cost(cur_piece + 2, idx), idx, cur_piece + 1);
        }
    }
    cout << sum << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    // cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}