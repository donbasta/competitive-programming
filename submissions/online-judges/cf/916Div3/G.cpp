#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;
const ll MOD = 998244353;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<ll> rn(n), col(n * 2);
    for (int i = 0; i < n; i++) {
        rn[i] = rng();
    }
    vector<ll> ks(n * 2);
    for (int i = 0; i < n * 2; i++) {
        cin >> col[i];
        --col[i];
        ks[i] = (i ? ks[i - 1] : 0) ^ rn[col[i]];
    }
    int part = count(ks.begin(), ks.end(), 0);
    map<ll, int> xors;
    vector<pair<int, int>> itv;
    ll ways = 1;
    ll cnt = 0;
    for (int i = 0; i < n * 2; i++) {
        cnt++;
        if (ks[i] == 0) {
            ll kurs = 0;
            if (!itv.empty()) {
                sort(itv.begin(), itv.end());
                int L = itv[0].first, R = itv[0].second;
                for (int i = 1; i < itv.size(); i++) {
                    if (itv[i].first > R) {
                        kurs += R - L + 1;
                        L = itv[i].first, R = itv[i].second;
                    } else {
                        R = max(R, itv[i].second);
                    }
                }
                kurs += R - L + 1;
                itv.clear();
            }
            ways = (ways * (cnt - kurs)) % MOD;
            cnt = 0;
            xors.clear();
        } else {
            if (xors.count(ks[i])) {
                int st = xors[ks[i]];
                itv.emplace_back(st + 1, i);
            }
            xors[ks[i]] = i;
        }
    }
    cout << part << ' ' << ways << '\n';
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