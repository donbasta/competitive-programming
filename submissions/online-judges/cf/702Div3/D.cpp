#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 100;
int d[N + 5];
int a[N + 5];
int n;

void go(int l, int r, int dep) {
    if (l > r) return;
    int mx = -1, idx = -1;
    for (int itr = l; itr <= r; itr++) {
        if (a[itr] > mx) {
            mx = a[itr];
            idx = itr;
        }
    }
    d[idx] = dep;
    go(l, idx - 1, dep + 1);
    go(idx + 1, r, dep + 1);
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    go(1, n, 0);
    for (int i = 1; i <= n; i++) {
        cout << d[i] << ' ';
    }
    cout << '\n';
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