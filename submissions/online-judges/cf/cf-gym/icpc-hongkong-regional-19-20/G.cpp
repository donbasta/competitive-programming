#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e5;
int par[N + 5];
int val[N + 5];

int cnt, k, mn;

void mul2() {
    val[cnt + 1] = 1;
    val[cnt + 2] = 1;
    val[cnt + 3] = 2;
    val[cnt + 4] = mn + 3;
    par[cnt + 1] = cnt + 3;
    par[cnt + 2] = cnt + 3;
    par[cnt + 3] = cnt + 4;
    par[cnt] = cnt + 4;
    cnt += 4;
    mn += 2;
}

void add1() {
    par[cnt] = cnt + 2;
    par[cnt + 1] = cnt + 2;
    val[cnt + 1] = 1;
    val[cnt + 2] = mn + 1;
    cnt += 2;
    mn += 1;
}

void solve() {
    cin >> k;
    if (k == 1) {
        cout << 2 << '\n' << 1 << '\n';
        cout << 2 << ' ' << 1 << '\n';
        return;
    }
    vector<int> ve;
    while (k) {
        ve.emplace_back(k);
        k >>= 1;
    }
    reverse(ve.begin(), ve.end());
    int sz = (int) ve.size();

    val[1] = 1;
    cnt = 1;
    mn = 1;
    for (int i = 0; i < sz - 1; i++) {
        if (ve[i + 1] == ve[i] * 2) {
            mul2();
        } else if (ve[i + 1] == (ve[i] * 2 + 1)) {
            mul2();
            add1();
        }
    }
    par[cnt] = par[1];
    swap(val[cnt], val[1]);

    cout << cnt << '\n';
    for (int i = 2; i <= cnt; i++) {
        if (par[i] == cnt) par[i] = 1;
        cout << par[i] << '\n';
    }
    for (int i = 1; i <= cnt; i++) {
        cout << val[i] << ' ';
    }
    cout << '\n';
    return;
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