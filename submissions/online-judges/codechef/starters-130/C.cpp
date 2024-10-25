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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<pair<int, int>> ve;
    int st = 0;
    char cur = s[0];
    for (int i = 1; i < n; i++) {
        if (s[i] != cur) {
            ve.emplace_back(st, i - 1);
            st = i;
            cur = s[i];
        }
    }
    ve.emplace_back(st, n - 1);
    int cnt = ve.size();
    vector<int> par_len(cnt), type(cnt);
    for (int i = 0; i < cnt; i++) {
        par_len[i] = (ve[i].second - ve[i].first + 1) & 1;
    }
    type[0] = s[0] - '0';
    for (int i = 1; i < cnt; i++) {
        type[i] = 1 - type[i - 1];
    }
    debug(ve, par_len, type);
    int ptr = 1;
    int last = -1;
    vector<int> ans;
    while (ptr < cnt) {
        if (par_len[ptr] == 0 && par_len[ptr - 1] == 0) {
            ptr += 2;
        } else if (par_len[ptr] == 1 && par_len[ptr - 1] == 0) {
            ptr++;
        } else if (par_len[ptr] == 0 && par_len[ptr - 1] == 1) {
            if (last == -1 || last == 0) {
                if (type[ptr] == 1) {
                    ans.push_back(ve[ptr].first);
                } else if (type[ptr] == 0) {
                    ans.push_back(ve[ptr - 1].second);
                }
                last = 1;
            } else if (last == 1) {
                if (type[ptr] == 1) {
                    ans.push_back(ve[ptr - 1].second);
                } else if (type[ptr] == 0) {
                    ans.push_back(ve[ptr].first);
                }
                last = 0;
            }
            par_len[ptr] = 1;
            ptr++;
        } else {
            if (last == -1 || last == 0) {
                if (type[ptr] == 1) {
                    ans.push_back(ve[ptr].first);
                } else if (type[ptr] == 0) {
                    ans.push_back(ve[ptr - 1].second);
                }
                last = 1;
            } else if (last == 1) {
                if (type[ptr] == 1) {
                    ans.push_back(ve[ptr - 1].second);
                } else if (type[ptr] == 0) {
                    ans.push_back(ve[ptr].first);
                }
                last = 0;
            }
            ptr += 2;
        }
    }
    cout << ans.size() << '\n';
    for (auto e : ans) {
        cout << (e + 1) << ' ';
    }
    cout << '\n';
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