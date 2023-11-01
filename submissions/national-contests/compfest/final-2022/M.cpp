#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

template <class T>
int sgn(T x) {
    return (x > 0) - (x < 0);
}
template <class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x = 0, T y = 0)
        : x(x), y(y) {
    }
    bool operator<(P p) const {
        return tie(x, y) < tie(p.x, p.y);
    }
    bool operator==(P p) const {
        return tie(x, y) == tie(p.x, p.y);
    }
    P operator+(P p) const {
        return P(x + p.x, y + p.y);
    }
    P operator-(P p) const {
        return P(x - p.x, y - p.y);
    }
    P operator*(T d) const {
        return P(x * d, y * d);
    }
    P operator/(T d) const {
        return P(x / d, y / d);
    }
    T dot(P p) const {
        return x * p.x + y * p.y;
    }
    T cross(P p) const {
        return x * p.y - y * p.x;
    }
    T cross(P a, P b) const {
        return (a - *this).cross(b - *this);
    }
    T manhattan(P p) const {
        return abs(x - p.x) + abs(y - p.y);
    }
    T dist2() const {
        return x * x + y * y;
    }
    double dist() const {
        return sqrt((double)dist2());
    }
    double angle() const {
        return atan2(y, x);
    }
    P unit() const {
        return *this / dist();
    }
    P perp() const {
        return P(-y, x);
    }
    P normal() const {
        return perp().unit();
    }
    P rotate(double a) const {
        return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
    }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")";
    }
};

typedef long long T;
typedef Point<T> P;
const T INF = numeric_limits<T>::max();

bool on_x(const P& a, const P& b) {
    return a.x < b.x;
}
bool on_y(const P& a, const P& b) {
    return a.y < b.y;
}

struct Node {
    P pt;
    T x0 = INF, x1 = -INF, y0 = INF, y1 = -INF;
    Node *first = 0, *second = 0;

    T distance(const P& p) {
        T x = (p.x < x0 ? x0 : p.x > x1 ? x1
                                        : p.x);
        T y = (p.y < y0 ? y0 : p.y > y1 ? y1
                                        : p.y);
        return (P(x, y)).manhattan(p);
    }

    Node(vector<P>&& vp)
        : pt(vp[0]) {
        for (P p : vp) {
            x0 = min(x0, p.x);
            x1 = max(x1, p.x);
            y0 = min(y0, p.y);
            y1 = max(y1, p.y);
        }
        if (vp.size() > 1) {
            sort(all(vp), x1 - x0 >= y1 - y0 ? on_x : on_y);
            int half = sz(vp) / 2;
            first = new Node({vp.begin(), vp.begin() + half});
            second = new Node({vp.begin() + half, vp.end()});
        }
    }
};

struct KDTree {
    Node* root;
    KDTree(const vector<P>& vp)
        : root(new Node({all(vp)})) {
    }

    pair<T, P> search(Node* node, const P& p) {
        if (!node->first) {
            return make_pair((p).manhattan(node->pt), node->pt);
        }

        Node *f = node->first, *s = node->second;
        T bfirst = f->distance(p), bsec = s->distance(p);
        if (bfirst > bsec)
            swap(bsec, bfirst), swap(f, s);

        auto best = search(f, p);
        if (bsec < best.first)
            best = min(best, search(s, p));
        return best;
    }

    pair<T, P> nearest(const P& p) {
        return search(root, p);
    }
};

void solve() {
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