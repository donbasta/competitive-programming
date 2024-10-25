#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define fi first
#define se second

const int N = 1e5 + 69;

ll pre[N];

struct Point {
    ll x, y;
    Point(){};
    Point(ll x, ll y) : x(x), y(y){};
};

int compareX(const void *a, const void *b) {
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->x - p2->x);
}

int compareY(const void *a, const void *b) {
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->y - p2->y);
}

ll dist(Point a, Point b) {
    ll dx = a.x - b.x;
    ll dy = a.y - b.y;
    return dx * dx + dy * dy;
}

ll sq(ll a) {
    return a * a;
}

ll stripClosest(Point strip[], int size, ll d) {
    ll mn = d;
    qsort(strip, size, sizeof(Point), compareY);
    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size && sq(strip[j].y - strip[i].y) < mn; ++j)
            if (dist(strip[i], strip[j]) < mn)
                mn = dist(strip[i], strip[j]);
    return mn;
}

ll bruteForce(Point P[], int n) {
    ll mn = 1e18;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (dist(P[i], P[j]) < mn)
                mn = dist(P[i], P[j]);
    return mn;
}

double closestUtil(Point P[], int n) {
    if (n <= 3)
        return bruteForce(P, n);

    int mid = n / 2;
    Point midPoint = P[mid];

    ll dl = closestUtil(P, mid);
    ll dr = closestUtil(P + mid, n - mid);
    ll d = min(dl, dr);

    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (sq(P[i].x - midPoint.x) < d)
            strip[j] = P[i], j++;

    return min(d, stripClosest(strip, j, d));
}

double closest(Point P[], int n) {
    qsort(P, n, sizeof(Point), compareX);
    return closestUtil(P, n);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    Point P[n];

    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        pre[i] = pre[i - 1] + x;
    }

    for (int i = 0; i < n; i++) {
        P[i] = Point(i + 1, pre[i + 1]);
    }

    ll ans = closest(P, n);
    cout << ans << " ";
}