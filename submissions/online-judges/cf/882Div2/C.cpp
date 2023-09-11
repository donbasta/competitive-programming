#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

const int BMAX = 10;
struct Node {
    Node *child[2];
    int cnt;
    Node() {
        child[0] = child[1] = NULL;
        cnt = 0;
    }
};
struct Trie {
    Node *head;

    Trie() { head = new Node(); }

    void insert(int val) {
        Node *cur = head;
        for (int i = BMAX; i >= 0; i--) {
            int v = (val >> i) & 1;
            ++(cur->cnt);
            if (cur->child[v] == NULL) {
                cur->child[v] = new Node();
            }
            cur = cur->child[v];
        }
        ++(cur->cnt);
    }

    void erase(int val) {
        Node *cur = head;
        for (int i = BMAX; i >= 0; i--) {
            int v = (val >> i) & 1;
            --(cur->cnt);
            cur = cur->child[v];
        }
        --(cur->cnt);
    }
};

void solve() {
    int n;
    cin >> n;
    int cur = 0;
    vector<int> ve;

    Trie tr = Trie();
    tr.insert(0);
    ve.push_back(0);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cur ^= x;
        ve.push_back(cur);
        tr.insert(cur);
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        int T = ve[i];
        Node *curNode = tr.head;
        int tmp = 0;
        for (int i = BMAX; i >= 0; i--) {
            int v = (T >> i) & 1;
            if (curNode->child[v ^ 1]) {
                curNode = curNode->child[v ^ 1];
                tmp += (1 << i);
            } else {
                curNode = curNode->child[v];
            }
        }
        ans = max(ans, tmp);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}