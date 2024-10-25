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
#define REP1(macro, ...) __VA_OPT__(EEE(REP2(macro, __VA_ARGS__)))
#define REP2(macro, x, ...) macro(x) __VA_OPT__(REP3 PARENS(macro, __VA_ARGS__))
#define REP3() REP2
#define out(x) "\t[" << #x " = " << x << "]\n"
#define debug(...) cerr << "Line " << __LINE__ << "\n" \
                        << REP1(out, __VA_ARGS__) << "\n";

const int INF = 2e9;

void el_psy_congroo() {
    int x;
    cin >> x;
    set<int> z;
    z.insert(1), z.insert(69), z.insert(-420);
    vector<pair<int, int>> y;
    vector<vector<int>> ve(x);
    for (int i = 0; i < x; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int t;
            cin >> t;
            ve[i].push_back(t);
        }
    }
    y.emplace_back(1, 2);
    debug(x, x * 2, ve, y);
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