struct SparseTable {
    const int K = 25;
    vector<vector<int>> table(K + 1);
    int n;
    SparseTable(int n) : n(n) {
        for (auto& v : table) v.resize(n + 5);
    }
    void build(const vector<int>& ar) {
        for (int i = 1; i <= K; i++) {
            for (int j = 0; (j + (1 << i)) <= n; j++) {
                table[i][j] = min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    int get(int l, int r) {
        int ret = 0;
        for (int i = K; i >= 0; i--) {
            if ((1 << i) <= r - l + 1) {
                ret = min(ret, table[i][l]);
                l += (1 << i);
            }
        }
        return ret;
    }
};

struct SparseTableRMQ {
    const int K = 25;
    vector<vector<int>> table(K + 1);
    int n;
    SparseTable(int n) : n(n) {
        for (auto& v : table) v.resize(n + 5);
    }
    void build(const vector<int>& ar) {
        for (int i = 1; i <= K; i++) {
            for (int j = 0; (j + (1 << i)) <= n; j++) {
                table[i][j] = min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    int logg(int x) {
        return bit_width(x) - 1;
    }
    int get(int l, int r) {
        int i = logg(r - l + 1);
        return min(st[i][l], st[i][r - (1 << i) + 1]);
    }
};