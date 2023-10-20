#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<int> ar(n);
    vector<vector<int>> lmao(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        lmao[ar[i]].push_back(i);
    }
    vector<ll> cnt(n + 1);
    set<pair<int, int>> itv;
    itv.emplace(0, n - 1);
    unordered_map<int, int> mp;
    mp[n] = 1;
    const function<void(int)> erase_from = [&](int x) {
        auto itr = itv.lower_bound(make_pair(x + 1, -1));
        --itr;
        int L = itr->first, R = itr->second;
        itv.erase(itr);
        mp[R - L + 1]--;
        if (mp[R - L + 1] == 0) mp.erase(R - L + 1);
        if (itr->first == x) {
            itv.emplace(x + 1, R);
            mp[R - x]++;
        } else if (itr->second == x) {
            itv.emplace(L, x - 1);
            mp[x - L]++;
        } else {
            itv.emplace(L, x - 1);
            itv.emplace(x + 1, R);
            mp[x - L]++;
            mp[R - x]++;
        }
    };
    for (int i = 0; i < n; i++) {
        for (auto x : lmao[n - i]) {
            erase_from(x);
        }
        for (auto e : mp) {
            cnt[e.first] += e.second;
        }
    }
    ll m;
    cin >> m;
    ll mm = m;
    ll stick = 0;
    for (int i = n; i >= 1; i--) {
        if (cnt[i] * i >= m) {
            stick += (m + i - 1) / i;
            break;
        } else {
            stick += cnt[i];
            m -= (cnt[i] * i);
        }
    }
    ll ans = mm - stick;
    cout << ans << '\n';
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