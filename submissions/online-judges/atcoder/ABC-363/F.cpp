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
    if (n == 1) {
        cout << 1 << '\n';
        return;
    }

    vector<ll> divs;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i != 0) continue;
        divs.emplace_back(i);
        if (i * i != n) divs.emplace_back(n / i);
    }
    sort(divs.begin(), divs.end());

    const int M = 1e6;
    ll A[M + 1];
    vector<pair<ll, ll>> E;
    for (ll i = 1; i <= M; i++) {
        string tmp = to_string(i);
        if (count(tmp.begin(), tmp.end(), '0') > 0) continue;
        reverse(tmp.begin(), tmp.end());
        A[i] = i * stoll(tmp);
        if (n % A[i] == 0) {
            E.emplace_back(A[i], i);
        }
    }
    sort(E.begin(), E.end());

    map<ll, bool> ok;
    map<ll, pair<ll, ll>> prv;

    auto is_palindrome = [&](const string &S) -> bool {
        int len = S.length();
        for (int i = 0; i < len / 2; i++) {
            if (S[i] != S[len - 1 - i]) return false;
        }
        return true;
    };

    for (auto d : divs) {
        string sd = to_string(d);
        if (is_palindrome(sd) && count(sd.begin(), sd.end(), '0') == 0) {
            ok[d] = true;
            continue;
        }
        for (auto e : E) {
            if (e.first > d) continue;
            if (d % e.first != 0) continue;
            if (!ok[d / e.first]) continue;
            ok[d] = true;
            prv[d] = e;
            break;
        }
    }

    if (!ok[n]) {
        cout << -1 << '\n';
        return;
    }
    vector<string> K;
    string mid;
    while (n > 1) {
        if (is_palindrome(to_string(n))) {
            mid = to_string(n);
            break;
        }
        K.emplace_back(to_string(prv[n].second));
        n /= prv[n].first;
    }
    string ret;
    for (auto k : K) {
        ret += k;
        ret.push_back('*');
    }
    if (!mid.empty()) {
        ret += mid;
        ret.push_back('*');
    }
    reverse(K.begin(), K.end());
    for (auto k : K) {
        reverse(k.begin(), k.end());
        ret += k;
        ret.push_back('*');
    }
    ret.pop_back();
    assert(ret.length() <= 1000);
    cout << ret << '\n';
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