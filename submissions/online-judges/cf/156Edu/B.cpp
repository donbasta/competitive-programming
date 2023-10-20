#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    ll px, py, ax, ay, bx, by;
    cin >> px >> py >> ax >> ay >> bx >> by;

    ll oa = (ax * ax + ay * ay);
    ll ob = (bx * bx + by * by);
    ll pa = ((px - ax) * (px - ax) + (py - ay) * (py - ay));
    ll pb = ((px - bx) * (px - bx) + (py - by) * (py - by));

    ld A = sqrtl(max(oa, pa));
    ld B = sqrtl(max(ob, pb));

    ll lmao = max(min(oa, ob), min(pa, pb));
    ll jar = ((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
    ld P = sqrtl(lmao), Q = sqrtl(jar);
    if (P * 2 < Q) P = Q / 2;

    ld ret = min(A, B);
    ret = min(ret, P);
    cout << fixed << setprecision(10) << ret << '\n';
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