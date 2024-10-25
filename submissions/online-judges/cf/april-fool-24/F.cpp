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

int T = 8;
int dx[8] = {1, 0, -1, 1, -1, 1, 0, -1};
int dy[8] = {1, 1, 1, 0, 0, -1, -1, -1};

// int T = 4;
// int dx[4] = {1, 0, 0, -1};
// int dy[4] = {0, 1, -1, 0};

void el_psy_congroo() {
    vector<string> ve(21);
    for (int i = 0; i < 21; i++) cin >> ve[i];
    int cnt = 0;

    vector<vector<bool>> vis(21, vector<bool>(21));
    const function<void(int, int)> ff = [&](int p, int q) {
        for (int i = 0; i < T; i++) {
            int np = p + dx[i], nq = q + dy[i];
            if (np < 0 || np >= 21 || nq < 0 || nq >= 21) continue;
            // if (ve[np][nq] == '0') continue;
            if (ve[np][nq] == '1') continue;
            if (vis[np][nq]) continue;
            vis[np][nq] = true;
            ff(np, nq);
        }
    };

    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            // if (ve[i][j] == '0') continue;
            if (ve[i][j] == '1') continue;
            if (vis[i][j]) continue;
            cnt++;
            vis[i][j] = true;
            ff(i, j);
        }
    }
    cout << cnt << '\n';
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