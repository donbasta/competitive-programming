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
    char trump;
    cin >> trump;
    map<char, vector<int>> mp;
    for (int i = 0; i < 2 * n; i++) {
        string card;
        cin >> card;
        mp[card[1]].push_back(card[0] - '0');
    }
    int cnt_trumps = mp[trump].size();
    int odd = 0;
    for (auto c : mp) {
        if (c.first == trump) continue;
        if (c.second.size() & 1) {
            odd++;
        }
    }
    if (odd > cnt_trumps) {
        cout << "IMPOSSIBLE" << '\n';
        return;
    }
    vector<string> extras;
    vector<pair<string, string>> games;
    for (auto &c : mp) {
        sort(c.second.begin(), c.second.end());
    }
    for (auto c : mp) {
        if (c.first == trump) continue;
        int sz = c.second.size();
        for (int i = 0; i + 1 < sz; i += 2) {
            string p = to_string(c.second[i]) + c.first;
            string q = to_string(c.second[i + 1]) + c.first;
            games.emplace_back(p, q);
        }
        if (c.second.size() & 1) {
            extras.emplace_back(to_string(c.second.back()) + c.first);
        }
    }
    int sz = extras.size();
    for (int i = 0; i < sz; i++) {
        string p = extras[i];
        string q = to_string(mp[trump][i]) + trump;
        games.emplace_back(p, q);
    }
    for (int i = sz; i + 1 < (int)mp[trump].size(); i += 2) {
        string p = to_string(mp[trump][i]) + trump;
        string q = to_string(mp[trump][i + 1]) + trump;
        games.emplace_back(p, q);
    }
    for (auto g : games) {
        cout << g.first << ' ' << g.second << '\n';
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