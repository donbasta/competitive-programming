#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    ll area = 0;
    map<ll, multiset<ll>> H, W, CH, CW;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        area += a[i] * b[i];
        H[a[i]].insert(b[i]);
        W[b[i]].insert(a[i]);
    }
    ll mxa = *max_element(a.begin(), a.end());
    ll mxb = *max_element(b.begin(), b.end());
    vector<pair<ll, ll>> ret;

    const function<bool(ll, ll, int)> check = [&](ll h, ll w, int orient) -> bool {
        if (h == 0 || w == 0) return true;
        if (orient == 0) {
            if (!CH.count(h)) return false;
            ll tmp = 0;
            for (auto p : CH[h]) {
                tmp += p;
                CW[p].erase(CW[p].find(h));
                if (CW[p].empty()) {
                    CW.erase(p);
                }
            }
            CH.erase(h);
            if (tmp > w) return false;
            return check(h, w - tmp, 1);
        } else if (orient == 1) {
            if (!CW.count(w)) return false;
            ll tmp = 0;
            for (auto p : CW[w]) {
                tmp += p;
                CH[p].erase(CH[p].find(w));
                if (CH[p].empty()) {
                    CH.erase(p);
                }
            }
            CW.erase(w);
            if (tmp > h) return false;
            return check(h - tmp, w, 0);
        }
        return false;
    };

    if (area % mxa == 0) {
        ll candidate_w = area / mxa;
        CH = H, CW = W;
        if (check(mxa, candidate_w, 0)) {
            ret.emplace_back(mxa, candidate_w);
        }
    }
    if (area % mxb == 0) {
        ll candidate_h = area / mxb;
        CH = H, CW = W;
        if (candidate_h != mxa && check(candidate_h, mxb, 1)) {
            ret.emplace_back(candidate_h, mxb);
        }
    }
    cout << ret.size() << '\n';
    for (auto e : ret) {
        cout << e.first << ' ' << e.second << '\n';
    }
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