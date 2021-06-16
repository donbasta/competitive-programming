#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using point = pair<ll, ll>;

#define x first
#define y second

int n;
vector<point> p;
ll d_area, border;

ll dobelArea(point a, point b, point c) {
    return (a.x * b.y + b.x * c.y + c.x * a.y) - (a.y * b.x + b.y * c.x + c.y * a.x);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        p.emplace_back(x, y);
    }
    for (int i = 1; i < n - 1; i++) {
        int j = (i + 1);
        d_area += dobelArea(p[0], p[i], p[j]);
    }
    border = n;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        ll t = __gcd(p[i].x - p[j].x, p[i].y - p[j].y);
        t = abs(t);
        t--;
        border += t; 
    }
    d_area = abs(d_area);
    ll ins = (d_area + 2 - border) / 2;
    cout << ins << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}