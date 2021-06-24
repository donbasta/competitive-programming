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
                if (cur -> child[0]) cur = cur -> child[0];
                else cur = cur -> child[1], dig = 1;
            } else if (v == 0) {
                if (cur -> child[1]) cur = cur -> child[1], dig = 1;
                else cur = cur -> child[0];
            }
            ret += (dig) * (1 << i);
        }
        return ret;
    }
};

int n, x;

void solve() {
    cin >> n >> x;
    int xr = 0;
    int mx = -1;
    int ans = 0;

    Trie T = Trie();
    T.insert(0);
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        xr ^= a;
        int ret = T.query(xr ^ x);
        int check = ret ^ xr ^ x;
        if (check > mx) {
            mx = check;
            ans = ret ^ xr;
        }
        T.insert(xr);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}