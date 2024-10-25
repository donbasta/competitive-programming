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
    vector<ll> ar(n);
    for (int i = 0; i < n; i++) cin >> ar[i];
    vector<vector<int>> ch(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        --p;
        ch[p].push_back(i);
    }

    ll add = 0;
    vector<bool> is_leaf(n);
    for (int i = 0; i < n; i++) {
        if (ch[i].empty()) is_leaf[i] = true;
    }

    vector<ll> surp(n);
    function<void(int)> dfs = [&](int v) {
        for (auto c : ch[v]) {
            dfs(c);
        }
        ll cur_sum = 0;
        for (auto c : ch[v]) {
            cur_sum += ar[c];
        }
        if (cur_sum >= ar[v]) {
            surp[v] = cur_sum - ar[v];
            return;
        }
        // ar[v] > cur_sum
        ll need = ar[v] - cur_sum;
        vector<int> nodes;
        nodes.push_back(v);
        for (int d = 1; d <= n; d++) {
            vector<int> tmp;
            for (auto node : nodes) {
                for (auto c : ch[node]) tmp.push_back(c);
            }
            nodes.swap(tmp);
            int leaf = -1;
            for (auto node : nodes) {
                if (is_leaf[node]) {
                    leaf = node;
                    break;
                }
            }
            if (leaf != -1) {
                add += 1ll * d * need;
                break;
            }
            ll sum_surplus = 0;
            for (auto node : nodes) {
                sum_surplus += surp[node];
            }
            if (1ll * sum_surplus >= need) {
                for (auto node : nodes) {
                    if (need - surp[node] <= 0) {
                        add += 1ll * d * need;
                        surp[node] -= need;
                        need = 0;
                        break;
                    } else {
                        add += 1ll * d * surp[node];
                        need -= surp[node];
                        surp[node] = 0;
                    }
                }
                break;
            } else {
                for (auto node : nodes) {
                    surp[node] = 0;
                }
                need -= sum_surplus;
                add += 1ll * d * sum_surplus;
            }
        }
    };
    dfs(0);
    cout << add << '\n';
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