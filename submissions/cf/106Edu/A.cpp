#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, k1, k2;
int w, b;

void solve() {
    cin >> n >> k1 >> k2;
    cin >> w >> b;
    int cek = abs(k1 - k2);
    int ww = min(k1, k2) + cek / 2;
    int bb = min(n - k1, n - k2) + cek / 2;
    bool flag = (w <= ww) && (b <= bb);
    cout << (flag ? "YES" : "NO") << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}