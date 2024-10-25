#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll N = 1e5 + 69;

struct point {
    ll x, y, p;
    point(ll _x = 0, ll _y = 0, ll _p = 0) : x(_x), y(_y), p(_p) {}
} pt[N];

__int128 dot(point a, point b) {
    return a.x * b.x + a.y * b.y;
}
__int128 sqr2(__int128 a) {
    if (a < 0)
        return -a * a;
    return a * a;
}

ll n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        pt[i] = point(x, y, i + 1);
    }
    sort(pt, pt + n, [](const point &a, const point &b) {
        return atan2(a.x, a.y) < atan2(b.x, b.y);
    });

    int j = 0;
    pt[n] = pt[0];
    for (int i = 0; i < n; i++) {
        if (sqr2(dot(pt[j], pt[j + 1])) * (dot(pt[i], pt[i]) * dot(pt[i + 1], pt[i + 1])) < sqr2(dot(pt[i], pt[i + 1])) * (dot(pt[j], pt[j]) * dot(pt[j + 1], pt[j + 1])))
            j = i;
    }

    cout << pt[j].p << " " << pt[j + 1].p << "\n";
    return 0;
}