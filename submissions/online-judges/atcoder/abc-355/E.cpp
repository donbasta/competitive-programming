#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define tc template <class
tc T1, class T2 > ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
tc T, class = decay_t<decltype(*begin(declval<T>()))>, class = enable_if_t < !is_same<T, string>::value >> ostream &operator<<(ostream &os, const T &c) {
    os << '{';
    for (auto it = c.begin(); it != c.end(); ++it) os << &", "[2 * (it == c.begin())] << *it;
    return os << '}';
}
#define PARENS ()
#define EEE(...) EEE1(EEE1(__VA_ARGS__))
#define EEE1(...) EEE2(__VA_ARGS__)
#define EEE2(...) __VA_ARGS__
#define REP(macro, ...) __VA_OPT__(EEE(REP_HELPER(macro, __VA_ARGS__)))
#define REP_HELPER(macro, a1, ...) macro(a1) __VA_OPT__(REP_AGAIN PARENS(macro, __VA_ARGS__))
#define REP_AGAIN() REP_HELPER
#define out(x) "\t[" << #x " = " << x << "]\n"
#ifdef LOCAL
#define debug(...) cerr << "Line " << __LINE__ << "\n" \
                        << REP(out, __VA_ARGS__) << "\n";
#else
#define debug(...) "itfeelsliketimeispassingsoquickly.thepassageoftimedependsentirelyonwhereyou'restanding.relativitytheory...it'ssoromantic.butit'sjustsotragictoo."
#endif

const int INF = 2e9;

void el_psy_congroo() {
    ll N, L, R;
    cin >> N >> L >> R;

    auto get = [&](int pp, int qq) -> vector<pair<ll, ll>> {
        vector<pair<ll, ll>> queries;
        function<void(ll, ll, ll, ll)> solve = [&](ll l, ll r, ll a, ll b) {
            ll mid = (l + r) >> 1;
            if (l == a && r == b) {
                queries.emplace_back(l, r);
                return;
            }
            if (b <= mid)
                solve(l, mid, a, b);
            else if (a >= mid + 1)
                solve(mid + 1, r, a, b);
            else {
                solve(l, mid, a, mid);
                solve(mid + 1, r, mid + 1, b);
            }
        };
        solve(0, (1 << N) - 1, pp, qq);
        return queries;
    };

    auto X = get(L, R);
    int sz = (int)X.size();

    auto cek = [&](ll P) -> pair<ll, ll> {
        ll a = 1, pa = 0, pb = 0;
        while (a < P) {
            a <<= 1;
            pa++;
        }
        ll tmp = P;
        while (tmp % 2 == 0) {
            tmp >>= 1;
            pb++;
        }
        if (P != (1ll << pa) - (1ll << pb)) {
            return make_pair(-1, -1);
        }
        return make_pair(pa, pb);
    };

    vector<ll> ok_kiri(sz, -1), ok_kanan(sz, -1);
    for (int i = 0; i < sz; i++) {
        int st = X[i].first;
        pair<ll, ll> T = cek(R - st + 1);
        if (T != make_pair(-1ll, -1ll)) {
            ll j = (1ll << T.first) + st - 1;
            if (sz - i > 2) {
                ok_kanan[i] = j;
            }
        }

        int en = X[i].second;
        T = cek(en - L + 1);
        if (T != make_pair(-1ll, -1ll)) {
            ll j = en - (1ll << T.first) + 1;
            if ((i + 1) > 2) {
                ok_kiri[i] = j;
            }
        }
    }

    const ll INF = 2e9;
    int mn = INF;
    pair<int, int> piv;
    for (int i = 0; i < sz; i++) {
        for (int j = i + 1; j < sz; j++) {
            int ki = (ok_kiri[i] != -1 ? 2 : (i + 1));
            int ka = (ok_kanan[j] != -1 ? 2 : (sz - j));
            if (ki + ka + (j - 1 - i) < mn) {
                mn = ki + ka + (j - 1 - i);
                piv = make_pair(i, j);
            }
        }
    }
    assert(mn < INF);

    auto query = [&](ll AA, ll BB) -> ll {
        ll sel = (BB - AA + 1);
        ll i = 0;
        while (sel % 2 == 0) {
            sel /= 2;
            i++;
        }
        ll j = AA / (BB - AA + 1);
        cout << "? " << i << ' ' << j << endl;

        ll resp;
        cin >> resp;
        return resp;
    };

    ll ans = 0;
    if (ok_kiri[piv.first] != -1) {
        ans = (ans + query(ok_kiri[piv.first], X[piv.first].second)) % 100;
        ans = (ans - query(ok_kiri[piv.first], L - 1)) % 100;
    } else {
        for (int i = 0; i <= piv.first; i++) {
            ans = (ans + query(X[i].first, X[i].second)) % 100;
        }
    }
    for (int i = piv.first + 1; i <= piv.second - 1; i++) {
        ans = (ans + query(X[i].first, X[i].second)) % 100;
    }
    if (ok_kanan[piv.second] != -1) {
        ans = (ans + query(X[piv.second].first, ok_kanan[piv.second])) % 100;
        ans = (ans - query(R + 1, ok_kanan[piv.second])) % 100;
    } else {
        for (int i = piv.second; i < sz; i++) {
            ans = (ans + query(X[i].first, X[i].second)) % 100;
        }
    }

    ans %= 100;
    if (ans < 0) ans += 100;
    cout << "! " << ans << endl;
    exit(0);
}

int main() {
    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}
