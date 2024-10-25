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
    vector<pair<int, int>> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i].first;
        ar[i].second = i;
    }

    if (n == 1) {
        cout << "YES" << '\n';
        return;
    }

    vector<pair<int, int>> ans;

    function<void(vector<pair<int, int>>)> rec = [&](vector<pair<int, int>> V) {
        int sz = V.size();
        if (sz == 2) {
            ans.emplace_back(V[0].second, V[1].second);
            return;
        }
        vector<int> rem(sz - 1, -1);
        int remove = -1;
        for (auto v : V) {
            if (rem[v.first % (sz - 1)] != -1) {
                ans.emplace_back(v.second, rem[v.first % (sz - 1)]);
                remove = v.second;
                break;
            }
            rem[v.first % (sz - 1)] = v.second;
        }
        assert(remove != -1);
        vector<pair<int, int>> V1;
        for (auto v : V) {
            if (v.second == remove) continue;
            V1.push_back(v);
        }
        rec(V1);
    };

    rec(ar);

    cout << "YES" << '\n';
    reverse(ans.begin(), ans.end());
    for (auto e : ans) {
        cout << (e.first + 1) << ' ' << (e.second + 1) << '\n';
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