struct BIT {
    int n;
    vector<int> bit;
    BIT(int _n) : n(_n) {
        bit.resize(n + 1);
    }
    void upd(int pos, int val) {
        while (pos <= n) {
            bit[pos] += val;
            pos += (pos & (-pos));
        }
    }
    int get(int pos) {
        int ret = 0;
        while (pos > 0) {
            ret += bit[pos];
            pos -= (pos & (-pos));
        }
        return ret;
    }
    int get(int l, int r) {
        return get(r) - get(l - 1);
    }
};