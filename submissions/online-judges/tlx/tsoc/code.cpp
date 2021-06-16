#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1000000007;

// int j(int x, int y) {
//     // int z = y;
//     // while (x --> 0) {
//     //     z --> 0;
//     //     z %= MOD;
//     //     if(z < 0) z += MOD;
//     // }
//     // return z;
//     int z = (y - x) % MOD;
//     if(z < 0) z += MOD;
//     return z;
// }

// int i(int x, int y) {
//     // int z = y;
//     // while (x --> 0) {
//     //     int w = MOD;
//     //     w --> 0;
//     //     z = j(w, z);
//     //     z %= MOD;
//     //     if(z < 0) z += MOD;
//     // }
//     int z = (y + x) % MOD;
//     if(z < 0) z += MOD;
//     return z;
// }

// int h(int x, int y) {
//     // int z = 0;
//     // while (y --> 0)
//     //     z = i(x, z);
//     int z = (1LL * x * y) % MOD;
//     if(z < 0) z += MOD;
//     return z;
// }

int g(int x, int y, int z) {
    // int w = 0;
    // w = h(x, y);
    // w = i(h(y, y), w);
    // w = j(h(i(x, y), z), w);
    int w = (1LL * (x + y) * (y - z)) % MOD;
    if(w < 0) w += MOD;
    return w;
}

int f(int x, int y) {
    // int z = 0;
    // while (x --> 0)
    //     z = g(z, x, y);
    // return z;
    long long cur = x - y, now = x, prod = cur;
    long long ans = 0;
    while(prod != 0) {
        ans += 1LL * now * prod;
        ans %= MOD;
        now--;
        cur--;
        prod *= cur; prod %= MOD;
    }
    ans %= MOD;
    if(ans < 0) ans += MOD;
    return (int)ans;
}

int main() {
    int t, n, m;
    scanf("%d", &t);
    // n = 7, m = 7;
    // vector<pair<int, int>> ve;
    // for(int i = 1; i <= n; i++) {
    //     for(int j = 1; j <= m; j++) {
    //         ve.emplace_back(i, j);
    //     }
    // }
    while (t --> 0) {
        scanf("%d %d", &n, &m);
        printf("%d\n", f(n, m));
    }
    // for(auto i : ve) {
    //     int a = i.first, b = i.second, c = f(a, b);
    //     if(c > MOD / 2) c -= MOD;
    //     cout << a << ' ' << b << ' ' << c << '\n';
    // }
    return 0;
}
