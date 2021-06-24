#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int BMAX = 30;
struct Trie {
    struct Node {
        Node *child[2];
        int cnt;
        Node () {
            child[0] = child[1] = NULL;
            cnt = 0;
        }
    };

    Node *head;

    Trie () { head = new Node(); }

    void insert (int val) { 
        Node *cur = head;
        for (int i = BMAX; i >= 0; i--) {
            int v = (val >> i) & 1;
            ++(cur -> cnt);
            if (cur -> child[v] == NULL) {
                cur -> child[v] = new Node ();
            }
            cur = cur -> child[v];
        }
        ++(cur -> cnt);
    }

    void erase (int val) {
        Node *cur = head;
        for (int i = BMAX; i >= 0; i--) {
            int v = (val >> i) & 1;
            --(cur -> cnt);
            cur = cur -> child[v];
        }
        --(cur -> cnt);
    }

    int query (int q) {
        Node *cur = head;
        int ret = 0;
        for (int i = BMAX; i >= 0; i--) {
            int v = (q >> i) & 1;
            int dig = 0;
            if (v == 1) {
                if (cur -> child[0] && cur -> child[0] -> cnt > 0) cur = cur -> child[0];
                else cur = cur -> child[1], dig = 1;
            } else if (v == 0) {
                if (cur -> child[1] && cur -> child[1] -> cnt > 0) cur = cur -> child[1], dig = 1;
                else cur = cur -> child[0];
            }
            ret += (dig) * (1 << i);
        }
        return ret;
    }
};

int q;

void solve() {
    cin >> q;
    Trie T = Trie();
    T.insert(0);
    while (q--) {
        char c;
        int x;
        cin >> c >> x;
        if (c == '+') {
            T.insert(x);
        } else if (c == '-') {
            T.erase(x);
        } else {
            int ans = T.query(x);
            cout << (ans ^ x) << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}