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
    map<char, int> cnt;
    map<char, vector<int>> pos;
    int idx = 0;
    for (auto c : s) {
        cnt[c]++;
        pos[c].push_back(idx++);
    }
    if ((cnt['N'] + cnt['S']) & 1) {
        cout << "NO" << '\n';
        return;
    }
    if ((cnt['W'] + cnt['E']) & 1) {
        cout << "NO" << '\n';
        return;
    }
    if (s == "EW" || s == "WE" || s == "NS" || s == "SN") {
        cout << "NO" << '\n';
        return;
    }
    string ret(n, 'X');
    string turn = "RH";
    for (int i = 0; i < cnt['W']; i++) {
        ret[pos['W'][i]] = turn[i & 1];
    }
    for (int i = 0; i < cnt['E']; i++) {
        ret[pos['E'][i]] = turn[i & 1];
    }
    for (int i = 0; i < cnt['N']; i++) {
        ret[pos['N'][i]] = turn[(i & 1) ^ 1];
    }
    for (int i = 0; i < cnt['S']; i++) {
        ret[pos['S'][i]] = turn[(i & 1) ^ 1];
    }
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