#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int M = 1e6;

int calc(const vector<int>& ar) {
    return *max_element(ar.begin(), ar.end()) - *min_element(ar.begin(), ar.end());
}

ll combine(ll a, ll b) {
    vector<int> da, db;
    ll ca = a, cb = b;
    while (a > 0) {
        da.push_back(a % 10);
        a /= 10;
    }
    while (b > 0) {
        db.push_back(b % 10);
        b /= 10;
    }
    int xa = calc(da);
    int xb = calc(db);
    if (xa < xb) return ca;
    return cb;
}

ll f(ll a, ll b) {
    int cnt_dig = to_string(a).length();
    // cerr << "LENGTH " << cnt_dig << '\n';
    if (a == b) return a;
    vector<ll> da, db;
    while (a > 0) {
        da.push_back(a % 10);
        a /= 10;
    }
    while (da.size() < cnt_dig) da.push_back(0);
    reverse(da.begin(), da.end());
    while (b > 0) {
        db.push_back(b % 10);
        b /= 10;
    }
    while (db.size() < cnt_dig) db.push_back(0);
    reverse(db.begin(), db.end());
    // for (auto e : da) {
    //     cerr << e << ' ';
    // }
    // cerr << '\n';
    // for (auto e : db) {
    //     cerr << e << ' ';
    // }
    vector<int> pref;
    vector<int> prefAns;
    bool trailing_zero = true;
    for (int i = 0; i < cnt_dig; i++) {
        if (da[i] == db[i]) {
            if (da[i] != 0) {
                trailing_zero = false;
            }
            if ((!trailing_zero) || (da[i] != 0))
                pref.push_back(da[i]);
        } else if (da[i] < db[i]) {
            if (i == cnt_dig - 1) {
                ll mn = INF;
                for (int j = da[i]; j <= db[i]; j++) {
                    pref.push_back(j);
                    ll check = calc(pref);
                    if (check < mn) {
                        mn = check;
                        prefAns = pref;
                    }
                    pref.pop_back();
                }
            } else {
                ll mn = INF;
                for (int j = da[i]; j <= db[i]; j++) {
                    pref.push_back(j);
                    for (int k = 0; k <= 9; k++) {
                        if (j == da[i]) {
                            int ptr = i + 1;
                            while ((ptr < cnt_dig) && (k == da[ptr])) ptr++;
                            if ((ptr < cnt_dig) && (k < da[ptr])) {
                                continue;
                            }
                        }
                        if (j == db[i]) {
                            int ptr = i + 1;
                            while ((ptr < cnt_dig) && (k == db[ptr])) ptr++;
                            if ((ptr < cnt_dig) && (k > db[ptr])) {
                                break;
                            }
                        }
                        pref.push_back(k);
                        ll check = calc(pref);
                        if (check < mn) {
                            mn = check;
                            prefAns = pref;
                        }
                        pref.pop_back();
                    }
                    pref.pop_back();
                }
            }
            break;
        }
    }
    // for (auto e : prefAns) {
    //     cerr << e << ' ';
    // }
    // cerr << '\n';
    // for (auto e : pref) {
    //     cerr << e << ' ';
    // }
    int last = prefAns.back();
    while (prefAns.size() < cnt_dig) prefAns.push_back(last);
    ll ans = 0;
    ll pw = 1;
    for (int i = cnt_dig - 1; i >= 0; i--) {
        ans += 1ll * prefAns[i] * pw;
        pw = pw * 10;
    }
    return ans;
}

const ll INFF = 1e18;

void solve() {
    int n;
    cin >> n;
    while (n--) {
        ll l, r;
        cin >> l >> r;
        if (l == INFF) {
            cout << INFF << '\n';
            return;
        }
        ll pw = 1;
        while (pw - 1 < l) pw *= 10;
        ll ans;
        if (pw - 1 >= r) {
            ans = f(l, r);
        } else {
            // cerr << l << ' ' << pw - 1 << '\n';
            ans = f(l, pw - 1);
            // cerr << ans << '\n';
            while (pw <= (r / 10)) {
                ans = combine(ans, f(pw, pw * 10 - 1));
                // cerr << pw << ' ' << pw * 10 - 1 << ' ' << f(pw, pw * 10 - 1) << '\n';
                // cerr << ans << '\n';
                pw = pw * 10;
            }
            // cerr << f(pw, r) << '\n';
            ans = combine(ans, f(pw, r));
        }
        cout << ans << '\n';
    }
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