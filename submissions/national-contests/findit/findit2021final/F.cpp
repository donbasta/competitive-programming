#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1e9 + 7;
const int N = 105;
 
int n, m;
 
using matrix = vector<vector<ll>>;

matrix identity;

matrix mul(const matrix& a, const matrix& b){
    int sz = (int) a.size();
    matrix d(sz, vector<ll>(sz));
    for(int i = 0; i < sz; i++) {
        for(int j = 0; j < sz; j++) {
            for(int k = 0; k < sz; k++) {
                d[i][k] = (d[i][k] + a[i][j] * b[j][k]) % mod;
            }
        }
    }
    return d;
}

matrix fpow(const matrix& a, ll b) {
    matrix ret = identity;
    while (b) {
        if (b & 1) ret = mul(ret, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ret;
}

string s;
 
void solve(){
    int len, q;
    cin >> len >> q;
    cin >> s;
    string alp = "01";

    m = 2;
    n = s.size();

    identity.resize(n);
    for (int i = 0; i < n; i++) {
        identity[i].resize(n);
        for (int j = 0; j < n; j++) {
            identity[i][j] = (i == j ? 1 : 0);
        }
    }

    matrix a(n, vector<ll>(n)), res(n, vector<ll>(n));

    for(int len = 0; len < n; len++) {
        for(int add = 0; add < m; add++) {
            string temp = s.substr(0, len);
            temp.push_back(alp[add]);
            for(int nlen = len + 1; nlen >= 0; nlen--) {
                if(nlen == 0 || temp.substr(len + 1 - nlen, nlen) == s.substr(0, nlen)){
                    if(nlen != n)
                        a[len][nlen]++;
                    break;
                }
            }
        }
    }

    // matrix pw[35];
    // pw[0] = a;

    // for (int i = 1; i < 35; i++) {
    //     pw[i] = mul(pw[i - 1], pw[i - 1]);
    // }

    vector<pair<int, int>> queries, ans;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        queries.emplace_back(x, i);
    }
    sort(queries.begin(), queries.end());

    res = fpow(a, queries[0].first);
    ans.emplace_back()



    // while (q--) {
    //     int d;
    //     cin >> d;
    //     for(int i = 0; i < n; i++) {
    //         for(int j = 0; j < n; j++) {
    //             res[i][j] = ((i == j) ? 1 : 0);
    //         }
    //     }
    //     int pang = 0;
    //     while (d > 0) {
    //         if(d & 1) { res = mul(res, pw[pang]); }
    //         pang++;
    //         d >>= 1;
    //     }

    //     ll ans = 0;
    //     for(int i = 0; i < n; i++) {
    //         ans = (ans + res[0][i]) % mod;
    //     }
    //     cout << ans << '\n';
    // }
}
 
int main(){
    int tc = 1;

    for(int t = 0; t < tc; t++){
        solve();
    }
 
    return 0;
}