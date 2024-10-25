#include <bits/stdc++.h>
using namespace std;

// BEGINNING OF DEBUGGING TEMPLATE
template <class c>
struct rge {
    c b, e;
};
template <class c>
rge<c> range(c i, c j) { return rge<c>{i, j}; }
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
    ~debug() { cerr << endl; }
    template <class c>
    typename enable_if<sizeof dud<c>(0) != 1, debug&>::type operator<<(c i) {
        cerr << boolalpha << i;
        return *this;
    }
    template <class c>
    typename enable_if<sizeof dud<c>(0) == 1, debug&>::type operator<<(c i) {
        return *this << range(begin(i), end(i));
    }
    template <class c, class b>
    debug& operator<<(pair<b, c> d) {
        return *this << "(" << d.first << ", " << d.second << ")";
    }
    template <class c>
    debug& operator<<(rge<c> d) {
        *this << "[";
        for (auto it = d.b; it != d.e; ++it) *this << ", " + 2 * (it == d.b) << *it;
        return *this << "]";
    }
};
// #define cek(...) " [" \
//                      << "Line <" << __LINE__ << "> --> " #__VA_ARGS__ " : " << (__VA_ARGS__) << "] "

// #define watch(...) debug() << " [" \
//                            << "Line <" << __LINE__ << "> --> " #__VA_ARGS__ " : " << (__VA_ARGS__) << "] "
// #define dbg(...) FOR_EACH_MACRO(watch, __VA_ARGS__) << "\n"
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// END OF DEBUGGING TEMPLATE

const int INF = 2e9;

void el_psy_congroo() {
    int a = 3, b = 2, c = 1;
    string st = "tes";
    // debug() << cek(st);
    // watch(st);
    // watch(a, b, c, a + b + c);
    // dbg(a, b, c, a + b + c);

    debug() << imie(c, b, a) imie(b + a);

    map<int, int> mp;
    mp[0] = 7, mp[50] = 69;
    // debug() << cek(mp);

    map<int, vector<int>> ve;
    ve[0] = vector<int>{1, 2, 3};
    ve[-5] = vector<int>{4, 1};
    // debug() << cek(ve);

    // debug() << cek(c * 2) cek(min(a, b)) cek(a != b);
    // watch(c * 310), watch(ve), watch(mp);

    set<pair<int, int>> se;
    se.emplace(3, 4);
    se.emplace(-1, 69);
    se.emplace(-1, 30);
    // debug() << cek(se);
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