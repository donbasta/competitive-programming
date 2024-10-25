#include <bits/stdc++.h>
using namespace std;

int modpow(int a, int b, int mod) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = 1LL * res * a % mod;
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return res;
}

int inv(int a, int b) {
    // b is prime
    return modpow(a, b - 2, b);
}

bool isPrime(int a) {
    if (a <= 1)
        return false;
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0)
            return false;
    }
    return true;
}

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    if (n == 1) {
        cout << "YES"
             << "\n";
        cout << 1 << "\n";
        return 0;
    }
    if (n == 4) {
        cout << "YES"
             << "\n";
        cout << 1 << "\n"
             << 3 << "\n"
             << 2 << "\n"
             << 4 << "\n";
        return 0;
    }
    if (!isPrime(n)) {
        cout << "NO"
             << "\n";
        return 0;
    }
    cout << "YES"
         << "\n";
    cout << 1 << "\n";
    for (int i = 1; i < n - 1; i++) {
        int temp = 1LL * (i + 1) * inv(i, n) % n;
        cout << temp << "\n";
    }
    cout << n << "\n";
    return 0;
}