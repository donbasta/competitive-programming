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

char ask(int i) {
    cout << "? " << i << endl;
    char c;
    cin >> c;
    return c;
}

void el_psy_congroo() {
    int n;
    cin >> n;

    vector<int> ans(n + 1);
    int v = 0;
    const function<void(vector<int>)> get_answer = [&](vector<int> A) {
        if (A.size() == 0) {
            return;
        }
        if (A.size() == 1) {
            ans[A[0]] = ++v;
            return;
        }
        int idx = rng() % ((int)A.size());
        char c = ask(A[idx]);
        while (c != '=') {
            c = ask(A[idx]);
        }
        vector<int> B, C;
        for (auto a : A) {
            if (a == A[idx]) {
                continue;
            }
            c = ask(a);
            assert(c != '=');
            if (c == '>') {
                C.push_back(a);
            } else {
                B.push_back(a);
            }
            ask(A[idx]);
        }
        get_answer(B);
        ans[A[idx]] = ++v;
        get_answer(C);
    };

    // 5
    // 3 2 4 1 5

    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 1);
    get_answer(indices);

    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return;
}

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}