template <typename T>
struct BIT
{
    int n;
    vector<T> bit;
    BIT(int _n) : n(_n)
    {
        bit.resize(n + 1);
    }
    void upd(int pos, const T &val)
    {
        while (pos <= n)
        {
            bit[pos] += val;
            pos += (pos & (-pos));
        }
    }
    T get(int pos)
    {
        T ret = 0;
        while (pos > 0)
        {
            ret += bit[pos];
            pos -= (pos & (-pos));
        }
        return ret;
    }
    T get(int l, int r)
    {
        return get(r) - get(l - 1);
    }
};
