#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;

struct Fraction {
    ll a, b;
    Fraction(ll _a, ll _b) {
        ll gcd = __gcd(abs(_a), abs(_b));
        a = _a / gcd, b = _b / gcd;
    }
    bool operator<(const Fraction &frac) const { return a * frac.b < frac.a * b; }
    bool operator==(const Fraction &frac) const { return a * frac.b == frac.a * b; }
};

int cross(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
    ll x1 = b.first - a.first, y1 = b.second - a.second;
    ll x2 = c.first - b.first, y2 = c.second - b.second;
    ll cr = x1 * y2 - y1 * x2;
    if (cr > 0)
        return 1;
    else if (cr < 0)
        return -1;
    return 0;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    vector<pair<ll, ll>> hull;
    hull.emplace_back(ar[n - 1], n - 1);
    hull.emplace_back(ar[n - 2], n - 2);
    Fraction max_grad = Fraction(ar[n - 1] - ar[n - 2], 1);
    for (int i = n - 3; i >= 0; i--) {
        max_grad = max(max_grad, Fraction(hull.back().first - ar[i], hull.back().second - i));
        while (hull.size() >= 2 && (cross(hull[hull.size() - 2], hull.back(), make_pair(ar[i], i)) <= 0)) {
            hull.pop_back();
        }
        hull.emplace_back(ar[i], i);
    }
    map<Fraction, int> cnt;
    ll x = max_grad.a, y = max_grad.b;
    cerr << x << ' ' << y << '\n';
    for (int i = 0; i < n; i++) {
        cnt[Fraction(ar[i] - x * i, y)]++;
    }
    ll ans = 0;
    for (auto e : cnt) {
        ans += 1ll * (e.second) * (e.second - 1) / 2;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}