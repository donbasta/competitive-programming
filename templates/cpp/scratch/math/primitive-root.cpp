
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;

// int powmod (int a, int b, int p) {
//     int res = 1;
//     while (b)
//         cerr << b << '\n';
//         if (b & 1){
//           res = int (res * 1ll * a % p);
//         }
//         a = int (a * 1ll * a % p);
//         b >>= 1;
//         cerr << "konto";
//     return res;
// }

int powmod(int a, int b, int p) {
    int ret = 1;
    while (b) {
        if (b & 1) ret = (1LL * ret * a) % p;
        a = (1LL * a * a) % p;
        b >>= 1;
    }
    return ret;
}

int generator(int p) {
    vector<int> fact;
    int phi = p - 1, n = phi;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) {
            fact.push_back(i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        fact.push_back(n);

    for (int res = 2; res <= p; ++res) {
        cerr << res << '\n';
        bool ok = true;
        for (size_t i = 0; i < fact.size() && ok; ++i) {
            cerr << i << '\n';
            ok &= powmod(res, phi / fact[i], p) != 1;
        }
        if (ok) return res;
    }
    return -1;
}

int main() {
    int lol = generator(MOD);
    cout << lol << '\n';
}