const int BMAX = 20;
struct Trie {
    struct Node {
        Node* child[2];
        int cnt;
        Node() {
            child[0] = child[1] = NULL;
            cnt = 0;
        }
    };

    Node* head;

    Trie() { head = new Node(); }

    void insert(int val) {
        Node* cur = head;
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
        Node* cur = head;
        for (int i = BMAX; i >= 0; i--) {
            int v = (val >> i) & 1;
            --(cur->cnt);
            cur = cur->child[v];
        }
        --(cur->cnt);
    }
};

// find min(x ^ t) and/or max(x ^ t) over all t in trie and x a query
struct Trie {
    struct Node {
        Node* child[2];
        Node() { child[0] = child[1] = nullptr; }
    };
    Node* head;
    bool empty;
    Trie() : empty(true) { head = new Node(); }
    void insert(int val) {
        empty = false;
        Node* cur = head;
        for (int i = B; i >= 0; i--) {
            int v = (val >> i) & 1;
            if (cur->child[v] == nullptr) cur->child[v] = new Node();
            cur = cur->child[v];
        }
    }
    int get_min_xor(int val) {
        Node* cur = head;
        int ret = 0;
        for (int i = B; i >= 0; i--) {
            int v = (val >> i) & 1;
            if (cur->child[v]) {
                cur = cur->child[v];
            } else {
                cur = cur->child[v ^ 1];
                ret += (1 << i);
            }
        }
        return ret;
    }
    int get_max_xor(int val) {
        Node* cur = head;
        int ret = 0;
        for (int i = B; i >= 0; i--) {
            int v = (val >> i) & 1;
            if (cur->child[v ^ 1]) {
                cur = cur->child[v ^ 1];
                ret += (1 << i);
            } else {
                cur = cur->child[v];
            }
        }
        return ret;
    }
};
