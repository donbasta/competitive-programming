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
    string s;
    cin >> s;
    int n = s.length();
    vector<int> len(n + 1, INF), prv(n + 1, n);
    len[n] = 0;
    len[n - 1] = 1;

    for (int i = n - 2; i >= 0; i--) {
        len[i] = min(len[i], len[i + 1] + 1);
        string l2 = s.substr(i, 2);
        if ((l2 == "II") || (l2 == "IV") || (l2 == "VI")) {
            len[i] = min(len[i], len[i + 2] + 1);
        }
        if (i <= n - 3) {
            string l3 = s.substr(i, 3);
            if ((l3 == "III") || (l3 == "VII")) {
                len[i] = min(len[i], len[i + 3] + 1);
            }
        }
        if (i <= n - 4) {
            if (s.substr(i, 4) == "VIII") {
                len[i] = min(len[i], len[i + 4] + 1);
            }
        }
        if (len[i] == len[i + 1] + 1)
            prv[i] = i + 1;
        else if (i <= n - 2 && len[i] == len[i + 2] + 1)
            prv[i] = i + 2;
        else if (i <= n - 3 && len[i] == len[i + 3] + 1)
            prv[i] = i + 3;
        else if (i <= n - 4 && len[i] == len[i + 4] + 1)
            prv[i] = i + 4;
    }
    string ret;

    map<string, char> mp;
    mp["I"] = '1', mp["II"] = '2', mp["III"] = '3', mp["IV"] = '4', mp["V"] = '5';
    mp["VI"] = '6', mp["VII"] = '7', mp["VIII"] = '8';

    int cur = 0;
    while (cur < n) {
        int pr = prv[cur];
        ret.push_back(mp[s.substr(cur, pr - cur)]);
        cur = pr;
    }
    // reverse(ret.begin(), ret.end());
    cout << ret << '\n';
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