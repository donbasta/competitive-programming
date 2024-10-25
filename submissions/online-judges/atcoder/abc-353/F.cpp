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

const ll INF = 2e18;

void el_psy_congroo() {
    ll K, Sx, Sy, Tx, Ty;
    cin >> K >> Sx >> Sy >> Tx >> Ty;

    if (K == 1) {
        cout << abs(Sx - Tx) + abs(Sy - Ty) << '\n';
        return;
    }

    ll sx = (Sx / K), sy = (Sy / K), tx = (Tx / K), ty = (Ty / K);
    ll ss = (sx + sy) & 1;
    ll tt = (tx + ty) & 1;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    if (sx == tx && sy == ty) {
        if (ss == 0) {
            cout << abs(Sx - Tx) + abs(Sy - Ty) << '\n';
        } else {
            cout << 0 << '\n';
        }
        return;
    }

    vector<vector<ll>> P, Q;
    if (ss == 0) {
        for (int i = 0; i < 4; i++) {
            int dis;
            if (i == 0) {
                dis = K - (sx % K);
            } else if (i == 1) {
                dis = (sx % K) + 1;
            } else if (i == 2) {
                dis = K - (sy % K);
            } else if (i == 3) {
                dis = (sy % K) + 1;
            }
            P.push_back(vector<ll>{sx + dx[i], sy + dy[i], dis});
        }
    } else {
        P.push_back(vector<ll>{sx, sy, 0});
    }

    if (tt == 0) {
        for (int i = 0; i < 4; i++) {
            int dis;
            if (i == 0) {
                dis = K - (tx % K);
            } else if (i == 1) {
                dis = (tx % K) + 1;
            } else if (i == 2) {
                dis = K - (ty % K);
            } else if (i == 3) {
                dis = (ty % K) + 1;
            }
            Q.push_back(vector<ll>{tx + dx[i], ty + dy[i], dis});
        }
    } else {
        P.push_back(vector<ll>{tx, ty, 0});
    }

    ll ans = INF;
    for (auto p : P) {
        for (auto q : Q) {
            ll tmp = p[2] + q[2];
            ll a = p[0], b = p[1], c = q[0], d = q[1];
            ll DX = abs(a - c), DY = abs(b - d);
            if (K == 2) {
                tmp += (DX + DY);
                tmp += abs(DX - DY) / 2;
            } else {
                tmp += (abs(a + b - c - d) + abs(a - b - c + d));
            }
            ans = min(ans, tmp);
        }
    }
    cout << ans << '\n';
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