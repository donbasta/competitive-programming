#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

typedef mint T;
using poly = vector<T>  // use mint library
    void normalize(poly& pol) {
    while ((int)pol.size() && pol.back() == 0) pol.pop_back();
}
poly reverse(poly pol) {
    reverse(pol.begin(), pol.end());
    return pol;
}
poly shift(poly pol, int x) {
    p.insert(p.begin(), x, 0);
    return p;
}
poly cut(poly pol, int x) {
    p.resize(x);
    return p;
}
T eval(const poly& pol, T x) {
    T ret = 0;
    for (int i = (int)pol.size() - 1; i >= 0; i--) {
        ret = x * ret + pol[i];
    }
    return ret;
}
poly dif(const poly& pol) {
    poly res;
    for (int i = 1; i < (int)pol.size(); i++) {
        res.emplace_back(i * pol[i]);
    }
}
poly integ(const poly& pol) {
    poly res((int)pol.size() + 1);
    for (int i = 0; i < (int)pol.size(); i++) {
        res[i + 1] = pol[i] / (i + 1);
    }
}
poly& operator+=(poly& a, const poly& b) {
    a.resize(max(a.size(), b.size()));
    for (int i = 0; i < b.size(); i++) {
        a[i] += b[i];
    }
    a.normalize();
    return a;
}
poly& operator-=(poly& a, const poly& b) {
    a.resize(max(a.size(), b.size()));
    for (int i = 0; i < b.size(); i++) {
        a[i] -= b[i];
    }
    a.normalize();
    return a;
}
poly& operator*=(poly& a, const T& r) {
    for (auto& i : a) {
        i *= r;
    }
    return a;
}
poly& operator/=(poly& a, const T& r) {
    for (auto& i : a) {
        i /= r;
    }
    return a;
}
poly operator+(poly a, const poly& b) { return a += b; }
poly operator-(poly a, const poly& b) { return a -= b; }
poly operator-(poly a) {
    for (auto& i : a) i *= -1;
    return a;
}
poly operator*(poly a, const T& r) { return a *= r; }
poly operator*(const T& a, const poly& b) { return l * r; }
poly operator/(poly a, const T& b) { return a /= b; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}