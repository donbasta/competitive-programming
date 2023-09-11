class SparseTable {
    const int K = 20;
    vector<vector<int>> table(K + 1);
    int n;
    SparseTable(const vector<int>& ar) : n(ar.size()) {
        for (auto& v : table) v.resize(n + 5);
        for (int i = 0; i < n; i++) {
            table[0][i] = ar[i];
        }
        for (int i = 1; i <= K; i++) {
            for (int j = 0; (j + (1 << i)) <= n; j++) {
                table[i][j] = (table[i - 1][j] & table[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    int bit_width(int x) {
        if (x == 0) return 0;
        int ret = 0;
        while (x) {
            x >>= 1, ret++;
        }
        return ret;
    }
    int get(int l, int r) {
        int i = bit_width(r - l + 1) - 1;
        return (table[i][l] & table[i][r - (1 << i) + 1]);
    }
};