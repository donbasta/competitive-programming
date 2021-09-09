#include<bits/stdc++.h>
using namespace std;
 
/** START OF DESPERATE OPTIMIZATION **/
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
 
template<typename T> void in(T & x) {
    x = 0;
    register T c = getchar();
    while (((c < 48) || (c > 57)) && (c != '-')) c = getchar();
    bool neg = false;
    if (c == '-') neg = true;
    for (; c < 48 || c > 57; c = getchar());
    for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c & 15);
    if (neg) x = -x;
}
 
template<typename T> void out(T n, char CC) {
    if (n < 0) {
        putchar('-');
        n *= -1;
    }
    char snum[65];
    int i = 0;
    do {
        snum[i++] = n % 10 + '0';
        n /= 10;
    } while (n);
    i = i - 1;
    while (i >= 0) putchar(snum[i--]);
    putchar(CC);
}
/** END OF DESPERATE OPTIMIZATION **/
 
using ll = long long;
using ld = long double;
using matrix = vector<vector<int>>;
 
const int MOD = 1e9 + 7;
const int sz = 2;
 
const matrix identity = {{1, 0}, {0, 1}};
 
matrix mul(const matrix& a, const matrix& b){
    matrix d(sz, vector<ll>(sz));
    for(int i = 0; i < sz; i++) {
        for(int k = 0; k < sz; k++) {
            for(int j = 0; j < sz; j++) {
                d[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    for(int i=0;i<sz;i++){
        for (int j=0;j<sz;j++){
            d[i][j] %= MOD;
        }
    }
    return d;
}
 
matrix fpow(matrix a, ll b) {
    matrix ret = identity;
    while (b) {
        if (b & 1) ret = mul(ret, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ret;
}
 
const int N = 1e5 + 5;
 
ll inp_a[N], inp_n[N];
 
void solve(ll a, ll n) {
    n = abs(n);
    matrix magic = {{a % MOD, MOD - 1}, {1, 0}};
    ll t0 = 2;
    ll t1 = (a % MOD);
    if (t1 < 0) t1 += MOD;
    if (n == 0) {
        out(t0, '\n');
        return;
    }
    if (n == 1) {
        out(t1, '\n');
        return;
    }
    magic = fpow(magic, n - 1);
    ll ans = (magic[0][0] * t1 + magic[0][1] * t0) % MOD;
    if (ans < 0) ans += MOD;
    out(ans, '\n');
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int TC = 1;
    in(TC);
    for(int i = 1; i <= TC; i++) {
        in(inp_a[i]), in(inp_n[i]);
    }
    for (int i = 1; i <= TC; i++) {
        solve(inp_a[i], inp_n[i]);
    }
  
    return 0;
}