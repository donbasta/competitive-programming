#include <bits/stdc++.h>

using namespace std;

int bin_expo(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

long long bin_expo(long long a, long long b, long long c) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % c;
        a = a * a % c;
        b >>= 1;
    }
    return res;
}