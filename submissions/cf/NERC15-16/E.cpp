#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n, k;
    cin >> n >> k;
    int mx = 0;
    vector<int> p(n);
    vector<vector<int>> ve(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        mx = max (mx, p[i]);
        for (int j = 0; j < p[i]; j++) {
            int x;
            cin >> x;
            ve[i].push_back(x); 
        }
    }
    int tot = 0;
    int soal = 0;
    int ke = 0;
    int orang = 0;
    while (soal < k && ke < mx) {
        if (ke >= (int)ve[orang].size()) {
            tot += 50;
        } else if (ve[orang][ke] < tot){
            orang = (orang + 1) % n;
            if (orang == 0) ke++;
            continue;
        } else {
            tot += ve[orang][ke];
        }
        soal++;
        cerr << soal << '\n';
        orang = (orang + 1) % n;
        if (orang == 0) ke++;
    }
    if (soal < k) {
        tot += 50 * (k -  soal);
    }
    cout << tot << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("easy.in", "r", stdin);
    freopen("easy.out", "w", stdout);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}