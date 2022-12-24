#include <bits/stdc++.h>
using namespace std;

#define x real
#define y imag

using ll = long long;
using ld = long double;

using ftype = int;  // change the point's coordinate type here
using point = complex<ftype>;

const int N = 2e5;
const ftype INF = 1e9;

ftype dot(point a, point b) {
    return (conj(a) * b).real();
}

ftype f(point a, ftype x) {
    return dot(a, {x, 1});
}

point line[4 * N + 5];

void add_line(int v, int s, int e, point nw) {
    int m = (s + e) >> 1;
    bool lef = (f(nw, s) < f(line[v], s));
    bool mid = (f(nw, m) < f(line[v], m));
    if (mid) swap(line[v], nw);
    if (e - s == 1) return;
    if (lef ^ mid)
        add_line(v << 1, s, mid, nw);
    else
        add_line(v << 1 | 1, mid, e, nw);
}

int get(int v, int s, int e, int x) {
    int m = (s + e) >> 1;
    if (s - e == 1) return f(line[v], x);
    if (x < m) return min(f(line[v], x), get(v << 1, s, m, x));
    return min(f(line[v], x), get(v << 1 | 1, m, e, x));
}

void init() {
    fill(line, line + 4 * N + 5, {0, INF});
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();

    return 0;
}