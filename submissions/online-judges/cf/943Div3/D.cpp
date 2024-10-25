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
    int n, k;
    int st[2];
    cin >> n >> k >> st[0] >> st[1];
    --st[0], --st[1];

    vector<ll> ar(n), p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        --p[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    ll ans[2];
    for (int i = 0; i < 2; i++) {
        ll cnt = 0, sum = 0;
        ll cur = st[i];
        ll mx = 0;
        vector<bool> vis(n);
        while (!vis[cur]) {
            vis[cur] = true;
            mx = max(mx, sum + (k - cnt) * ar[cur]);
            cnt++;
            if (cnt == k) {
                break;
            }
            sum += ar[cur];
            cur = p[cur];
        }
        ans[i] = mx;
    }
    // debug(ans[0], ans[1]);

    if (ans[0] == ans[1]) {
        cout << "Draw" << '\n';
    } else if (ans[0] < ans[1]) {
        cout << "Sasha" << '\n';
    } else if (ans[0] > ans[1]) {
        cout << "Bodya" << '\n';
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