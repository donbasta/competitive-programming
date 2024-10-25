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
    ll n;
    cin >> n;
    vector<string> st(n);
    map<string, ll> m2, m4, m6;
    set<string> suf2, suf4;
    for (int i = 0; i < n; i++) {
        cin >> st[i];
        string s2 = st[i].substr(4, 2);
        string s4 = st[i].substr(2, 4);
        m6[st[i]]++;
        m4[s4]++;
        m2[s2]++;
        suf2.insert(s2);
        suf4.insert(s4);
    }
    map<string, ll> mx2;
    for (auto s4 : suf4) {
        string s2 = s4.substr(2, 2);
        mx2[s2] = max(mx2[s2], m4[s4]);
    }

    map<string, map<string, ll>> mp;
    map<string, ll> mpp;
    multiset<ll> vals;
    for (auto e : m2) {
        vals.insert(e.second);
    }
    for (auto s2 : suf2) {
        vals.erase(vals.find(m2[s2]));
        mpp[s2] = 0;
        auto ptr = vals.rbegin();
        for (int i = 0; i < 3; i++) {
            if (ptr == vals.rend()) break;
            mpp[s2] += *ptr;
            ptr++;
        }
        for (auto ss2 : suf2) {
            if (ss2 == s2) continue;
            vals.erase(vals.find(m2[ss2]));
            mp[s2][ss2] = 0;
            auto ptr = vals.rbegin();
            for (int i = 0; i < 3; i++) {
                if (ptr == vals.rend()) break;
                mp[s2][ss2] += *ptr;
                ptr++;
            }
            vals.insert(m2[ss2]);
        }
        vals.insert(m2[s2]);
    }

    ll ans = 0;
    const ll A = 3e5, B = 4e3, C = 5e2;

    // there is a first prize winner
    for (int i = 0; i < n; i++) {
        ll w1 = m6[st[i]];
        string last2 = st[i].substr(4, 2);
        for (auto s2 : suf2) {
            if (s2 == last2) {
                continue;
            }
            ll w2 = mx2[s2];
            ll w3 = mp[last2][s2];
            ll tmp = A * w1 + B * w2 + C * w3;
            // debug(i, st[i], last2, s2, tmp);
            ans = max(ans, tmp);
        }
        ans = max(ans, A * w1 + C * mpp[last2]);
    }

    // second and third prize winner
    for (auto s4 : suf4) {
        ans = max(ans, B * m4[s4] + C * mpp[s4.substr(2, 2)]);
    }

    // only third prize winner
    int tmp = 0;
    auto ptr = vals.rbegin();
    for (int i = 0; i < 3; i++) {
        if (ptr == vals.rend()) break;
        tmp += *ptr;
        ptr++;
    }
    ans = max(ans, C * tmp);

    cout << ans << '\n';
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