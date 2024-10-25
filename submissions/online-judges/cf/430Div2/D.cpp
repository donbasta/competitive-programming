#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int B = 20;

struct Node {
    int cnt;
    Node* ch[2];
    Node() {
        ch[0] = ch[1] = nullptr;
        cnt = 0;
    }
};

struct Trie {
    Node* root;
    Trie() {
        root = new Node();
    }
    void insert(int x) {
        Node* cur = root;
        cur->cnt++;
        for (int i = B; i >= 0; i--) {
            int v = (x >> i) & 1;
            if (!cur->ch[v]) cur->ch[v] = new Node();
            cur = cur->ch[v];
            cur->cnt++;
        }
    }
    int mex(int x) {
        Node* cur = root;
        int ret = 0;
        for (int i = B; i >= 0; i--) {
            int v = (x >> i) & 1;
            int le = (cur->ch[v] ? cur->ch[v]->cnt : 0);
            if (le < (1 << i)) {
                if (!cur->ch[v]) cur->ch[v] = new Node();
                cur = cur->ch[v];
            } else {
                ret += (1 << i);
                if (!cur->ch[v ^ 1]) cur->ch[v ^ 1] = new Node();
                cur = cur->ch[v ^ 1];
            }
        }
        if (cur->cnt > 0) ret++;
        return ret;
    }
};

void el_psy_congroo() {
    int n, m;
    cin >> n >> m;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    sort(ar.begin(), ar.end());
    ar.resize(unique(ar.begin(), ar.end()) - ar.begin());
    int sz = ar.size();

    Trie tr;
    for (int i = 0; i < sz; i++) {
        tr.insert(ar[i]);
    }

    int que = 0;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        que ^= x;
        cout << tr.mex(que) << '\n';
    }
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