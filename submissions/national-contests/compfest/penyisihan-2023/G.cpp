#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<ll> ar(n), d(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    auto ok = [&](ll z) -> bool {
        vector<ll> tmp = ar;
        vector<pair<pair<int, int>, pair<ll, int>>> ve;
        for (int i = 0; i < n; i++) {
            int le = max(0ll, i - d[i]);
            int ri = min(n - 1ll, i + d[i]);
            ve.emplace_back(make_pair(le, ri), make_pair(tmp[i], i));
        }
        sort(ve.begin(), ve.end());
        int ptr = 0;
        set<pair<int, pair<ll, int>>> se;  // kanan, capacity
        for (int i = 0; i < n; i++) {
            while (!se.empty() && se.begin()->first < i) se.erase(se.begin());
            while (ptr < (int)ve.size() && ve[ptr].first.first <= i) {
                se.emplace(ve[ptr].first.second, ve[ptr].second);
                ptr++;
            }
            while (tmp[i] < z) {
                if (se.empty()) break;
                if (se.size() == 1 && se.begin()->second.second == i) break;
                auto itr = se.begin();
                if (itr->second.second == i) ++itr;
                auto x = *itr;
                if (z == 5) {
                    cerr << i << " LMAO " << x.first << ' ' << x.second.first << ' ' << x.second.second << '\n';
                    cerr << i << " LMAO " << tmp[i] << '\n';
                }
                if (x.second.first <= (z - tmp[i])) {
                    se.erase(itr);
                    tmp[i] += x.second.first;
                    tmp[x.second.second] -= x.second.first;
                } else {
                    se.erase(itr);
                    se.emplace(x.first, make_pair(x.second.first - (z - tmp[i]), x.second.second));
                    tmp[x.second.second] -= (z - tmp[i]);
                    tmp[i] = z;
                }
            }
            if (z == 5) {
                cerr << i << ": \n";
                for (int j = 0; j < n; j++) {
                    cerr << j << ' ' << tmp[j] << '\n';
                }
            }
        }
        bool ok = true;
        for (int i = 0; i < n; i++) {
            ok &= (tmp[i] <= z);
        }
        return ok;
    };

    ll l = 0, r = 2e14;
    ll ans;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        // cerr << l << ' ' << r << '\n';fd
        if (ok(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}