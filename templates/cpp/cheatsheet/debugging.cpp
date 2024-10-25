#include <bits/stdc++.h>
using namespace std;

template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <class T, class = decay_t<decltype(*begin(declval<T>()))>,
          class = enable_if_t<!is_same<T, string>::value>>
ostream &operator<<(ostream &os, const T &c) {
    os << '{';
    for (auto it = c.begin(); it != c.end(); ++it) os << &", "[2 * (it == c.begin())] << *it;
    return os << '}';
}
#define _NTH_ARG(_1, _2, _3, _4, _5, _6, N, ...) N
#define _FE_0(_CALL, ...)
#define _FE_1(_CALL, x) _CALL(x)
#define _FE_2(_CALL, x, ...) _CALL(x) _FE_1(_CALL, __VA_ARGS__)
#define _FE_3(_CALL, x, ...) _CALL(x) _FE_2(_CALL, __VA_ARGS__)
#define _FE_4(_CALL, x, ...) _CALL(x) _FE_3(_CALL, __VA_ARGS__)
#define _FE_5(_CALL, x, ...) _CALL(x) _FE_4(_CALL, __VA_ARGS__)
#define FOR_EACH_MACRO(MACRO, ...)                                           \
    _NTH_ARG(dummy, ##__VA_ARGS__, _FE_5, _FE_4, _FE_3, _FE_2, _FE_1, _FE_0) \
    (MACRO, ##__VA_ARGS__)
#define out(x) "\t[" << #x " = " << x << "]\n"
#define LOG(...) \
    cerr << "Line " << __LINE__ << ":\n" FOR_EACH_MACRO(out, __VA_ARGS__) << "\n"

int main() {
    int x = 5;
    int y = 7;
    vector<int> z = {1, 2};
    z.push_back(x + y);
    map<int, int> mp;
    mp[3] = 4, mp[5] = 7;
    string st = "lmaopisan";
    LOG(x, y, z, mp, st);

    pair<int, int> P = make_pair(2, 3);
    cerr << P << '\n';

    // outputs: Line 38: x = 5; y = 7; z = [1, 2, 12];
}