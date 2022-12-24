const int INF = 1e9;

int C(int i, int j);

void compute(int l, int r, int optl, int optr)
{
    if (l > r)
    {
        return;
    }

    int mid = (l + r) >> 1;
    pair<int, int> best = make_pair(INF, -1);
    for (int k = optl; k <= min(mid, optr); k++)
    {
        best = min(best, make_pair((k ? dp_before[k - 1] : 0) + C(k, mid), k));
    }

    dp_cur[mid] = best.first;
    int optm = best.second;

    compute(l, mid - 1, optl, optm);
    compute(mid + 1, r, optm, optr);
}

int solve()
{
    for (int i = 0; i < n; i++)
    {
        dp_before[i] = C(0, i);
    }
    for (int i = 1; i < n; i++)
    {
        compute(0, n - 1, 0, n - 1);
        dp_before = dp_cur;
    }
}