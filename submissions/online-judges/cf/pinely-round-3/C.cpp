#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<ll> L(n), R(n), C(n);
    for (int i = 0; i < n; i++) {
        cin >> L[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> R[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> C[i];
    }
    sort(C.begin(), C.end());
    set<pair<ll, int>> se;
    set<pair<ll, pair<ll, ll>>> lmao;
    for (auto l : L) se.emplace(l, 0);
    for (auto r : R) se.emplace(r, 1);
    for (auto ptr = ++se.begin(); ptr != se.end(); ++ptr) {
        auto prv = ptr;
        --prv;
        if (ptr->second == 1 && prv->second == 0) {
            lmao.emplace(ptr->first - prv->first, make_pair(prv->first, ptr->first));
        }
    }
    ll ans = 0;
    int idx = n - 1;
    while (!se.empty()) {
        assert(!lmao.empty());
        auto now = *lmao.begin();
        ans += now.first * C[idx];
        idx--;
        lmao.erase(lmao.begin());
        se.erase(make_pair(now.second.first, 0));
        se.erase(make_pair(now.second.second, 1));
        auto tmp = se.lower_bound(make_pair(now.second.first, 0));
        if (tmp != se.begin()) {
            auto prv = tmp;
            --prv;
            if (tmp->second == 1 && prv->second == 0) {
                lmao.emplace(tmp->first - prv->first, make_pair(prv->first, tmp->first));
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