#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;

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
 
inline vector<int> fft(vector<int>& a, int k, int w, int p) {
    vector<int> prev(1<<k);
    int high = -1;
    for (int i=1;i<(1<<k);i++) {
        if (!(i&(i-1))) high+=1;
        prev[i] = prev[i^(1<<high)];
        prev[i]|=(1<<(k-1-high));
    }
    for (int& i: prev) i = a[i];
    vector<int> roots(1<<k);
    roots[0] = 1;
    for (int i=1;i<(1<<k);i++) roots[i] = mult(roots[i-1],w,p);
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
        int w = binpow(gen[r],(p-1)/(1<<k),p);
        vector<int> one = fft(a,k,w,p);
        vector<int> two = fft(b,k,w,p);
        c[r] = vector<int>(1<<k);
        for (int i=0;i<(1<<k);i++) c[r][i] = mult(one[i],two[i],p);
        c[r] = fft(c[r],k,inv(w,p),p);
        int rem = inv(1<<k,p);
        for (int& i: c[r]) i = mult(i,rem,p);
    }
    vector<int> res(len);
    for (int i=0;i<len;i++) {
        ll cur = (ll) mult(sub(c[1][i],c[0][i],PRIME[1]),inv(PRIME[0],PRIME[1]),PRIME[1])*PRIME[0]+c[0][i];
        ll cur2 = mult(sub(c[2][i],cur%PRIME[2],PRIME[2]),inv(mult(PRIME[0],PRIME[1],PRIME[2]),PRIME[2]),PRIME[2]);
        cur2 = add(mult(cur2%MOD,mult(PRIME[0],PRIME[1])),cur%MOD);
        res[i] = cur2;
    }
    return res;
}

int N, Q; 

void solve() {
    cin >> N;
    vector<int> c(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> c[i];
    }
    ll B = 0;
    vector<int> b(N);
    for (int i = 1; i <= N - 1; i++) {
        cin >> b[i];
        B += 1LL * b[i] * (N - i);
    }

    vector<vector<int>> poly(N);
    for (int i = 0; i < N; i++) {
        poly[i].assign(c[i] + 1, 1);
    }

    vector<int> res = vector<int>(1, 1);
    for (int i = 0; i < N; i++) {
        res = multiply(res, poly[i]);
    }

    // reverse(res.begin(), res.end());

    // while (res.back() == 0) {
    //     res.pop_back();
    // }

    int mx = (int) res.size();
    // cerr << mx << "res: \n";
    // for (auto& e : res) {
    //     cerr << e << ' ';
    // }
    // cerr << '\n';

    vector<ll> ans(mx + 1);
    for (int i = mx - 1; i >= 0; i--) {
        ans[i] = (ans[i + 1] + res[i]) % MOD;
    }

    cin >> Q;
    while (Q--) {
        ll x;
        cin >> x;
        ll thre = 1LL * N * x + B;
        // cerr << thre << ' ' << x << '\n';
        if (thre > mx) {
            cout << 0 <<  '\n';
        } else {
            cout << ans[max(thre, 0LL)] << '\n';
        }
    }
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