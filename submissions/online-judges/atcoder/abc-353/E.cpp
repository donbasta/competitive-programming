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

inline ll C2(ll x) {
    return x * (x - 1) / 2;
}

struct Trie {
    struct Node {
        Node *child[26];
        ll cnt;
        Node() {
            for (int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
            cnt = 0;
        }
    };

    Node *head;

    Trie() { head = new Node(); }

    void insert(const string &s) {
        Node *cur = head;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            cur->cnt++;
            int nx = s[i] - 'a';
            if (cur->child[nx] == nullptr) {
                cur->child[nx] = new Node();
            }
            cur = cur->child[nx];
        }
        cur->cnt++;
    }

    ll dfs(Node *v, ll dep) {
        ll ret = dep * C2(v->cnt);
        for (int i = 0; i < 26; i++) {
            if (v->child[i] == nullptr) {
                continue;
            }
            ret -= dep * C2(v->child[i]->cnt);
            ret += dfs(v->child[i], dep + 1);
        }
        return ret;
    }
};

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<string> ve(n);
    for (int i = 0; i < n; i++) cin >> ve[i];

    Trie trie;
    for (int i = 0; i < n; i++) {
        trie.insert(ve[i]);
    }
    cout << trie.dfs(trie.head, 0) << '\n';
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