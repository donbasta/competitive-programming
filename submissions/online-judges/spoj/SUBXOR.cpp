#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int BMAX = 20;
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

    int query (int xr, int k) {
        Node *cur = head;
        int ret = 0;
        for (int i = BMAX; i >= 0; i--) {
            if (cur == NULL) break;
            int v1 = (xr >> i) & 1;
            int v2 = (k >> i) & 1;
            if (v1 == 1 && v2 == 1) {
                if (cur -> child[1]) ret += (cur -> child[1] -> cnt);
                cur = cur -> child[0];
            } else if (v1 == 1 && v2 == 0) {
                cur = cur -> child[1];
            } else if (v1 == 0 && v2 == 1) {
                if (cur -> child[0]) ret += (cur -> child[0] -> cnt);
                cur = cur -> child[1];
            } else if (v1 == 0 && v2 == 0) {
                cur = cur -> child[0];
            }
        }
        return ret;
    }
};

int n, k;

void solve() {
    cin >> n >> k;
    Trie T = Trie();
    int xr = 0;
    T.insert(0);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        xr ^= a;
        ans += T.query(xr, k);
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