#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
int n, q;

int P1, P2, P3;
const int KK = 10;
int WW[3][KK], ZZ[3][KK], RR[3][KK];
int PANGKAT[3][KK][1<<KK + 10];
int PANGKAT2[3][KK][1<<KK + 10];
 
int add(int a, int b, int mo=MOD) { return a+b-(a+b>=mo)*mo; }
int sub(int a, int b, int mo=MOD) { return a-b+(a-b<0)*mo; }
int mult(int a, int b, int mo=MOD) { return ((ll) a*b)%mo; }
int binpow(int a, int p, int mo=MOD) {
    int ans = 1;
    while (p) {
        if (p&1) ans = mult(ans,a,mo);
        p>>=1;
        a = mult(a,a,mo);
    }
    return ans;
}
int inv(int a, int mo=MOD) { return binpow(a,mo-2,mo); }
 
const int PRIME[3] = {1004535809,1007681537,1012924417};
const int gen[3] = {3,3,5};
 
inline vector<int> fft(vector<int>& a, int k, int w, int p, int ir, bool INV) {
    vector<int> prev(1<<k);
    int high = -1;
    for (int i=1;i<(1<<k);i++) {
        if (!(i&(i-1))) high+=1;
        prev[i] = prev[i^(1<<high)];
        prev[i]|=(1<<(k-1-high));
    }
    for (int& i: prev) i = a[i];
    vector<int> roots(1<<k);
    if (!INV)
        for (int i=1;i<(1<<k);i++) roots[i] = PANGKAT[ir][k][i];
    else
        for (int i=1;i<(1<<k);i++) roots[i] = PANGKAT2[ir][k][i];
    // roots[0] = 1;
    // for (int i=1;i<(1<<k);i++) roots[i] = mult(roots[i-1],w,p);
    vector<int> next(1<<k);
    for (int len=1;len<(1<<k);len*=2) {
        int rstep = (1<<k)/(len*2);
        for (int pdest=0;pdest<(1<<k);) {
            int p1 = pdest;
            for (int i=0;i<len;i++) {
                int val = mult(roots[i*rstep],prev[p1+len],p);
                next[pdest] = add(prev[p1],val,p);
                next[pdest+len] = sub(prev[p1],val,p);
                pdest+=1; p1+=1;
            }
            pdest+=len;
        }
        swap(prev,next);
    }
    return prev;
}
 
inline vector<int> multiply (vector<int>& a, vector<int> b) {
    int len = a.size()+b.size()-1;
    int k = 0;
    while ((1<<k)<=2*max(a.size(),b.size())) k+=1;
    a.resize(1<<k);
    b.resize(1<<k);
    vector<int> c[3];
    for (int r=0;r<3;r++) {
        int p = PRIME[r];
        int w = WW[r][k];
        int z = ZZ[r][k];
        vector<int> one = fft(a,k,w,p,r,0);
        vector<int> two = fft(b,k,w,p,r,0);
        c[r] = vector<int>(1<<k);
        for (int i=0;i<(1<<k);i++) c[r][i] = mult(one[i],two[i],p);
        c[r] = fft(c[r],k,z,p,r,1);
        int rem = RR[r][k];
        for (int& i: c[r]) i = mult(i,rem,p);
    }
    vector<int> res(len);
    for (int i=0;i<len;i++) {
        ll cur = (ll) mult(sub(c[1][i],c[0][i],PRIME[1]),P1,PRIME[1])*PRIME[0]+c[0][i];
        ll cur2 = mult(sub(c[2][i],cur%PRIME[2],PRIME[2]),P2,PRIME[2]);
        cur2 = add(mult(cur2%MOD,P3),cur%MOD);
        res[i] = cur2;
    }
    for (int i = n; i < res.size(); i++) {
        res[i - n] = (res[i - n] + res[i]) % MOD;
    }
    res.resize(n);
    return res;
}

inline vector<int> fpow (vector<int>& haha, int b) {
    vector<int> ret = {1};
    vector<int> a = haha;
    while (b) {
        if (b & 1) ret = multiply(ret, a);
        a = multiply(a, a);
        b >>= 1;
    }
    return ret;
}

void solve() {
    P1 = inv(PRIME[0],PRIME[1]);
    P2 = inv(mult(PRIME[0],PRIME[1],PRIME[2]),PRIME[2]);
    P3 = mult(PRIME[0],PRIME[1]);

    for (int r = 0; r < 3; r++) {
        for (int k = 0; k < KK; k++) {
            WW[r][k] = binpow(gen[r],(PRIME[r]-1)/(1<<k),PRIME[r]);
            ZZ[r][k] = inv(WW[r][k], PRIME[r]);
            RR[r][k] = inv(1<<k, PRIME[r]);
            PANGKAT[r][k][0] = 1;
            PANGKAT2[r][k][0] = 1;
            for (int j = 1; j < (1 << KK); j++) {
                PANGKAT[r][k][j] = mult(PANGKAT[r][k][j - 1], WW[r][k], PRIME[r]);
                PANGKAT2[r][k][j] = mult(PANGKAT2[r][k][j - 1], ZZ[r][k], PRIME[r]);
            }
        }
    }

    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    cin >> q;
    vector<int> poly = {1};
    vector<int> haha(n + 1);
    int pk = -1;
    haha[0] = 1;
    while (q--) {
        int k, t;
        cin >> k >> t;
        if (pk >= 0) haha[pk] = 0;
        haha[k] = 1;
        poly = multiply(poly, fpow(haha, t));
        pk = k;
    }
    poly = multiply(poly, ar);
    for (int i = 0; i < n; i++) {
        int ans = (poly[i] % MOD);
        if (ans < 0) ans += MOD;
        cout << ans << ' ';
    }
    cout << '\n';
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