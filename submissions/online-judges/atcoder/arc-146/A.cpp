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
    vector<string> ar(n);
    map<int, vector<string>> mp;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        mp[-(int)ar[i].length()].push_back(ar[i]);
    }
    for (auto &m : mp) {
        sort(m.second.begin(), m.second.end());
    }
    auto it = mp.begin();
    string ans = "0";

    auto cek = [&](const string &x, const string &y, const string &z) -> string {
        string ret = "0";
        ret = max(ret, x + y + z);
        ret = max(ret, x + z + y);
        ret = max(ret, y + x + z);
        ret = max(ret, y + z + x);
        ret = max(ret, z + x + y);
        ret = max(ret, z + y + x);
        return ret;
    };

    if (it->second.size() >= 3) {
        int len = it->second.size();
        ans = it->second[len - 1] + it->second[len - 2] + it->second[len - 3];
    } else if (it->second.size() == 2) {
        auto it2 = mp.begin();
        ++it2;
        ans = max(ans, cek(it2->second.back(), it->second[0], it->second[1]));
        // for (auto st : it2->second) {
        //     ans = max(ans, cek(st, it->second[0], it->second[1]));
        // }
    } else if (it->second.size() == 1) {
        auto it2 = mp.begin();
        ++it2;
        if (it2->second.size() == 1) {
            auto it3 = mp.begin();
            ++it3;
            ++it3;
            ans = max(ans, cek(it->second[0], it2->second[0], it3->second.back()));
            // for (auto st : it3->second) {
            //     ans = max(ans, cek(it->second[0], it2->second[0], st));
            // }
        } else {
            int len = it2->second.size();
            ans = max(ans, cek(it->second[0], it2->second[len - 1], it2->second[len - 2]));
        }
    } else {
        assert(false);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}