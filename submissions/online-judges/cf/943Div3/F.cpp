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
    int n, q;
    cin >> n >> q;
    vector<int> pre(n + 1), ar(n);
    map<int, vector<int>> mp;
    mp[0].push_back(0);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        pre[i + 1] = pre[i] ^ ar[i];
        mp[pre[i + 1]].push_back(i + 1);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int xrange = pre[r] ^ pre[l - 1];
        if (xrange == 0) {
            cout << "YES" << '\n';
            continue;
        }
        int cari = xrange ^ pre[l - 1];
        if (mp.find(cari) == mp.end()) {
            cout << "NO" << '\n';
            continue;
        }
        int idx = lower_bound(mp[cari].begin(), mp[cari].end(), l) - mp[cari].begin();
        if (idx == (int)mp[cari].size() || mp[cari][idx] >= r) {
            cout << "NO" << '\n';
        } else {
            int cari2 = xrange ^ pre[r];
            if (mp.find(cari2) == mp.end()) {
                cout << "NO" << '\n';
                continue;
            }
            int idx2 = lower_bound(mp[cari2].begin(), mp[cari2].end(), r) - mp[cari2].begin() - 1;
            if (idx2 < 0 || mp[cari2][idx2] < l - 1) {
                cout << "NO" << '\n';
            } else {
                if (mp[cari][idx] >= mp[cari2][idx2] + 1) {
                    cout << "NO" << '\n';
                } else {
                    cout << "YES" << '\n';
                }
            }
        }
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