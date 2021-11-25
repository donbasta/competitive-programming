#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;

    int id = 1;
    const int MX = 1e5;
    vector<bool> beau(MX + 1);
    while (true) {
        int u = (1 << (id)) - 1;
        u <<= (id - 1);
        if (u > MX) {
            break;
        }
        id++;
        beau[u] = true;
    }
 
    int ret = 1;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (beau[i]) ret = max(ret, i);
            if (beau[n / i]) ret = max(ret, n / i);
        }
    }
    cout << ret << '\n';
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