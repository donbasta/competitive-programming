#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

vector<int> base3(ll x) {
    vector<int> ret;
    while (x) {
        ret.push_back(x % 3), x /= 3;
    }
    return ret;
}

ll xor3(ll x, ll y) {
    vector<int> dx = base3(x), dy = base3(y);
    ll pw = 1, ret = 0;
    for (int i = 0; i < max(dx.size(), dy.size()); i++) {
        int ax = (i >= dx.size() ? 0 : dx[i]);
        int ay = (i >= dy.size() ? 0 : dy[i]);
        int sum = (ax + ay) % 3;
        ret += pw * sum;
        pw *= 3;
    }
    return ret;
}

pair<ll, ll> operate(pair<ll, ll> x, pair<ll, ll> y) {
    return make_pair(xor3(x.first, y.first), xor3(x.second, y.second));
}

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    vector<ll> F1(n + 1), F2(n + 1);
    vector<pair<ll, ll>> P(n + 1);
    for (int i = 1; i <= n; i++) {
        F1[i] = rng();
        F2[i] = rng();
    }
    for (int i = 1; i <= n; i++) {
        P[i] = operate(P[i - 1], make_pair(F1[ar[i - 1]], F2[ar[i - 1]]));
    }
    int l = 0;
    map<pair<ll, ll>, int> mp;
    ll ans = 0;
    mp[make_pair(0, 0)]++;
    set<pair<int, int>> freq;
    vector<int> cur_freq(n + 1);
    for (int i = 1; i <= n; i++) freq.emplace(0, i);
    for (int i = 0; i < n; i++) {
        freq.erase(make_pair(cur_freq[ar[i]], ar[i]));
        cur_freq[ar[i]]++;
        freq.emplace(cur_freq[ar[i]], ar[i]);
        while (freq.rbegin()->first > 3) {
            freq.erase(make_pair(cur_freq[ar[l]], ar[l]));
            cur_freq[ar[l]]--;
            freq.emplace(cur_freq[ar[l]], ar[l]);
            mp[P[l]]--;
            if (mp[P[l]] == 0) mp.erase(P[l]);
            l++;
        }
        if (mp.count(P[i + 1])) {
            ans += mp[P[i + 1]];
        }
        mp[P[i + 1]]++;
    }
    cout << ans << '\n';
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