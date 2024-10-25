#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

ull modmul(ull a, ull b, ull M) {
    ll ret = a * b - M * ull(1.L / M * a * b);
    return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
    ull ans = 1;
    for (; e; b = modmul(b, b, mod), e /= 2)
        if (e & 1) ans = modmul(ans, b, mod);
    return ans;
}
bool isPrime(ull n) {
    if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
    ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
        s = __builtin_ctzll(n - 1), d = n >> s;
    for (ull a : A) {  // ^ count trailing zeroes
        ull p = modpow(a % n, d, n), i = s;
        while (p != 1 && p != n - 1 && a % n && i--)
            p = modmul(p, p, n);
        if (p != n - 1 && i != s) return 0;
    }
    return 1;
}
ull pollard(ull n) {
    auto f = [n](ull x) { return modmul(x, x, n) + 1; };
    ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
    while (t++ % 40 || __gcd(prd, n) == 1) {
        if (x == y) x = ++i, y = f(x);
        if ((q = modmul(prd, max(x, y) - min(x, y), n))) prd = q;
        x = f(x), y = f(f(y));
    }
    return __gcd(prd, n);
}
vector<ull> factor(ull n) {
    if (n == 1) return {};
    if (isPrime(n)) return {n};
    ull x = pollard(n);
    auto l = factor(x), r = factor(n / x);
    l.insert(l.end(), r.begin(), r.end());
    return l;
}

void rec(int idx, const vector<ull>& P, const vector<int>& E, vector<ull>& divs, ull cur) {
    if (idx == P.size()) {
        divs.push_back(cur);
        return;
    }
    rec(idx + 1, P, E, divs, cur);
    for (int i = 1; i <= E[idx]; i++) {
        cur *= P[idx];
        rec(idx + 1, P, E, divs, cur);
    }
}

void el_psy_congroo() {
    ull p;
    cin >> p;
    ull q = p * 2 - 2;
    vector<ull> primes = factor(q);
    sort(primes.begin(), primes.end());
    primes.resize(unique(primes.begin(), primes.end()) - primes.begin());
    vector<int> exp;
    for (auto pr : primes) {
        int pw = 0;
        ull cq = q;
        while (cq % pr == 0) {
            pw++, cq /= pr;
        }
        exp.push_back(pw);
    }
    vector<ull> divs;
    rec(0, primes, exp, divs, 1);
    sort(divs.begin(), divs.end());
    vector<ull> ans;
    for (int i = 1; i < divs.size(); i++) {
        if (divs[i] > 2 && divs[i] == divs[i - 1] + 1) {
            if ((p - 1) % (divs[i - 1]) == 0) {
                ans.push_back(divs[i] - 2);
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto e : ans) {
        cout << e << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}