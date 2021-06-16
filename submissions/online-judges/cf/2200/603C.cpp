#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e5;

int n, k;
int ar[N + 5];

int g(int x) {
    if (x == 1) return 1;
    if (k & 1) {
        if(x == 2) return 0;
        if(x == 3) return 1;
        if(x == 4) return 2;
        if(x & 1) return 0;
        int c = g(x / 2);
        return (c == 1 ? 2 : 1);
    }
    if (x == 2) return 2;
    if (x & 1) return 0;
    return 1;
}

void solve() {
    cin >> n >> k;
    int cek = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        cek ^= g(a);
    }
    cout << (cek ? "Kevin" : "Nicky");
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