#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = 1e15;

vector<ll> FIBO;

void init_fibo() {
    FIBO.push_back(1);
    FIBO.push_back(1);
    while (true) {
        ll x = FIBO.back() + FIBO[FIBO.size() - 2];
        FIBO.push_back(x);
        if (x > INF) break;
    }
    // cerr << FIBO.size() << '\n';
}

void el_psy_congroo() {
    int k;
    cin >> k;
    vector<ll> C(k);
    for (int i = 0; i < k; i++) {
        cin >> C[i];
    }
    ll sum = accumulate(C.begin(), C.end(), 0ll);
    ll id = lower_bound(FIBO.begin(), FIBO.end(), sum + 1) - FIBO.begin();
    if (FIBO[id] != sum + 1) {
        cout << "NO" << '\n';
        return;
    }
    int r = id - 2;
    ll mx = 0;
    for (int i = r; i >= 0; i -= 2) {
        mx += FIBO[i];
    }
    if (*max_element(C.begin(), C.end()) > mx) {
        cout << "NO" << '\n';
        return;
    }

    vector<vector<int>> zk(k), zk0(k);

    auto get_repr = [&](ll x) -> vector<int> {
        vector<int> ret;
        while (x > 0) {
            ll p = upper_bound(FIBO.begin(), FIBO.end(), x) - FIBO.begin();
            assert(p != 0);
            --p;
            ret.push_back(p);
            x -= FIBO[p];
        }
        reverse(ret.begin(), ret.end());
        return ret;
    };

    vector<bool> cant(k);
    vector<int> cnt(r + 1);
    for (int i = 0; i < k; i++) {
        zk[i] = get_repr(C[i]);
        for (auto e : zk[i]) cnt[e]++;
        zk0[i].push_back(0);
        vector<int> tmp = get_repr(C[i] - 1);
        if (!tmp.empty() && tmp[0] == 1)
            cant[i] = true;
        else {
            for (auto e : tmp) zk0[i].push_back(e);
        }
    }

    for (int i = 0; i < k; i++) {
        if (cant[i]) continue;
        for (auto e : zk[i]) cnt[e]--;
        for (auto e : zk0[i]) cnt[e]++;
        bool ok = true;
        for (int j = 0; j <= r; j++) {
            ok &= (cnt[j] == 1);
        }
        if (ok) {
            cout << "YES" << '\n';
            return;
        }
        for (auto e : zk0[i]) cnt[e]--;
        for (auto e : zk[i]) cnt[e]++;
    }
    cout << "NO" << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init_fibo();

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}