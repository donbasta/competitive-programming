#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

struct Trie {
    bool isLeaf;
    unordered_map<int, Trie*> map;
};

Trie* getNewTrieNode() {
    Trie* node = new Trie;
    node->isLeaf = false;

    return node;
}

void insert(Trie*& head, vector<int> ve) {
    if (head == nullptr) head = getNewTrieNode();

    Trie* curr = head;
    int idx = 0;
    while (idx < ve.size()) {
        if (curr->map.find(ve[idx]) == curr->map.end())
            curr->map[ve[idx]] = getNewTrieNode();
        curr = curr->map[ve[idx]];
        idx++;
    }
    curr->isLeaf = true;
}

int getLongestPrefix(Trie* head, vector<int> ve) {
    if (head == nullptr) return 0;

    Trie* curr = head;
    int idx = 0;
    while (idx < ve.size()) {
        curr = curr->map[ve[idx]];
        if (curr == nullptr) return idx;
        idx++;
    }

    return idx;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ve(n, vector<int>(m));
    vector<vector<int>> inv(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ve[i][j];
            --ve[i][j];
            inv[i][ve[i][j]] = j;
        }
    }

    Trie* head = nullptr;

    for (int i = 0; i < n; i++) {
        insert(head, inv[i]);
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = getLongestPrefix(head, ve[i]);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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