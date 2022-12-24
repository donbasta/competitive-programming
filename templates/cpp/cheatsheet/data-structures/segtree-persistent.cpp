typedef struct Vertex *pvertex;
struct Vertex
{
    Vertex *l, *r;
    int sum;

    Vertex(int val) : l(NULL), r(NULL), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0)
    {
        if (l)
            sum += (l->sum);
        if (r)
            sum += (r->sum);
    }
};

pvertex build(const vector<int> &ar, int s, int e)
{
    if (tl == tr)
    {
        return new Vertex(ar[tl]);
    }
    int mid = (s + e) >> 1;
    return new Vertex(build(ar, s, mid), build(ar, mid + 1, e));
}

// sum
int get(pvertex v, int s, int e, int l, int r)
{
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return v->sum;
    int mid = (s + e) >> 1;
    return get(v->l, s, mid, l, min(r, mid)) + get(v->r, mid + 1, e, max(l, mid + 1), r);
}

// point update
pvertex update(pvertex v, int s, int e, int pos, int val)
{
    if (l == r)
        return new Vertex(val);
    int mid = (s + e) >> 1;
    if (pos <= mid)
        return new Vertex(update(v->l, s, mid, pos, val), v->r);
    else
        return new Vertex(v->l, update(v->r, mid + 1, e, pos, val));
}
