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
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> A(n), B(m), mp(n);
    vector<set<int>> pos(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        --A[i];
        mp[A[i]] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> B[i];
        --B[i];
        B[i] = mp[B[i]];
    }
    vector<int> L(n, m);
    for (int i = m - 1; i >= 0; i--) {
        L[B[i]] = i;
        pos[B[i]].insert(i);
    }
    vector<string> ans;
    bool init_ans = true;
    for (int i = 1; i < n; i++) {
        if (L[i] < L[i - 1]) {
            init_ans = false;
            break;
        }
    }
    ans.push_back((init_ans ? "YA" : "TIDAK"));
    multiset<int> mse;
    for (int i = 1; i < n; i++) {
        mse.insert(L[i] - L[i - 1]);
    }

    for (int i = 0; i < q; i++) {
        int s, t;
        cin >> s >> t;
        --s, --t;
        t = mp[t];
        int prv_t = B[s];
        if (t == prv_t) {
            ans.push_back(ans.back());
            continue;
        }
        int aa = L[t];
        int bb = L[prv_t];

        pos[B[s]].erase(s);
        B[s] = t;
        pos[B[s]].insert(s);
        if (pos[prv_t].empty())
            L[prv_t] = m;
        else
            L[prv_t] = *pos[prv_t].begin();
        L[t] = *pos[t].begin();

        if (abs(t - prv_t) > 1) {
            if (t >= 1) {
                mse.erase(mse.find(aa - L[t - 1]));
                mse.insert(L[t] - L[t - 1]);
            }
            if (t + 1 < n) {
                mse.erase(mse.find(L[t + 1] - aa));
                mse.insert(L[t + 1] - L[t]);
            }
            if (prv_t >= 1) {
                mse.erase(mse.find(bb - L[prv_t - 1]));
                mse.insert(L[prv_t] - L[prv_t - 1]);
            }
            if (prv_t + 1 < n) {
                mse.erase(mse.find(L[prv_t + 1] - bb));
                mse.insert(L[prv_t + 1] - L[prv_t]);
            }
        } else {
            if (t > prv_t) {
                swap(t, prv_t);
                swap(aa, bb);
            }
            if (t >= 1) {
                mse.erase(mse.find(aa - L[t - 1]));
                mse.insert(L[t] - L[t - 1]);
            }
            if (prv_t + 1 < n) {
                mse.erase(mse.find(L[prv_t + 1] - bb));
                mse.insert(L[prv_t + 1] - L[prv_t]);
            }
            mse.erase(mse.find(bb - aa));
            mse.insert(L[prv_t] - L[t]);
        }
        ans.push_back(((*mse.begin() >= 0) ? "YA" : "TIDAK"));
    }
    for (auto e : ans) {
        cout << e << '\n';
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