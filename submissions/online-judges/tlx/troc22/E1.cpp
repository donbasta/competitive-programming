#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

map<ll, int> cache;

int ask(ll idx) {
    if (cache.find(idx) != cache.end()) {
        return cache[idx];
    }
    int ret;
    cout << "? " << idx << endl;
    cin >> ret;
    cache[idx] = ret;
    return ret;
}

ll n;

void solve() {
    cin >> n;
    int pl = ask(1);
    int pr = ask(n);
    ll l = 1, r = n;
    while (r - l > 1LL) {
        ll mid = (l + r) >> 1;
        int pmid = ask(mid);
        tuple<int, int, int> arr = make_tuple(pl, pmid, pr);
        if (arr == make_tuple(0, 0, 0)) {
            r = mid;
            pr = pmid;
        } else if (arr == make_tuple(0, 0, 1)) {
            r = mid;
            pr = pmid;
        } else if (arr == make_tuple(0, 1, 0)) {
            l = mid;
            pl = pmid;
        } else if (arr == make_tuple(0, 1, 1)) {
            l = mid;
            pl = pmid;
        } else if (arr == make_tuple(1, 0, 0)) {
            r = mid;
            pr = pmid;
        } else if (arr == make_tuple(1, 0, 1)) {
            r = mid;
            pr = pmid;
        } else if (arr == make_tuple(1, 1, 0)) {
            int ptemp = ask((l + mid) >> 1);
            if (ptemp == 0) {
                r = mid;
                pr = pmid;
            } else {
                l = mid;
                pl = pmid;
            }
        } else if (arr == make_tuple(1, 1, 1)) {
            r = mid;
            pr = pmid;
        }
    }
    assert(r - l == 1LL);
    ll ax = 1LL - r;
    ll bx = r - 1LL - n;
    ll r1 = r;

    // cout << r1 << " r1\n";

    pl = ask(l + 1);
    pr = ask(n);
    l = l + 1, r = n;
    while (r - l > 1LL) {
        ll mid = (l + r) >> 1;
        int pmid = ask(mid);
        tuple<int, int, int> arr = make_tuple(pl, pmid, pr);
        if (arr == make_tuple(0, 0, 0)) {
            r = mid;
            pr = pmid;
        } else if (arr == make_tuple(0, 0, 1)) {
            r = mid;
            pr = pmid;
        } else if (arr == make_tuple(0, 1, 0)) {
            l = mid;
            pl = pmid;
        } else if (arr == make_tuple(0, 1, 1)) {
            l = mid;
            pl = pmid;
        } else if (arr == make_tuple(1, 0, 0)) {
            r = mid;
            pr = pmid;
        } else if (arr == make_tuple(1, 0, 1)) {
            r = mid;
            pr = pmid;
        } else if (arr == make_tuple(1, 1, 0)) {
            int ptemp = ask((l + mid) >> 1);
            if (ptemp == 0) {
                r = mid;
                pr = pmid;
            } else {
                l = mid;
                pl = pmid;
            }
        } else if (arr == make_tuple(1, 1, 1)) {
            r = mid;
            pr = pmid;
        }
    }
    assert(r - l == 1LL);
    ll r2 = r;

    // cout << r2 << " r1\n";

    ll x = r2 - r1;
    ll a = (ax % x);
    if (a < 0) a += x;
    ll b = (bx % x);
    if (b < 0) b += x;
    ll y = (n + a + b) / x;
    x /= 2;
    cout << "! " << x << ' ' << y << ' ' << a << ' ' << b << endl;
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}