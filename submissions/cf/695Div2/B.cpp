#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

vector<int> ar;

bool tot(int p, int q, int r) {
    return ((ar[p] < ar[q]) && (ar[r] < ar[q])) || ((ar[p] > ar[q]) && (ar[r] > ar[q]));
}

void solve() {
    int n;
    cin >> n;
    ar.resize(n);
    vector<bool> p(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    if (n <= 3) {
        cout << 0 << '\n';
        return;
    }
    int h = 0, v = 0;
    for (int i = 1; i < n - 1; i++) {
        if (ar[i] > ar[i - 1] && ar[i] > ar[i + 1]) { h++; p[i] = 1; }
        if (ar[i] < ar[i - 1] && ar[i] < ar[i + 1]) { v++; p[i] = 1; }
    }
    int ans = h + v;
    for (int i = 0; i < n; i++) {
        int cek = p[i];
        if (i > 0) cek += p[i - 1];
        if (i < n - 1) cek += p[i + 1];
        int fix;
        if (i <= 1 || i >= n - 2) fix = 0;
        else {
            fix = (tot(i - 2, i - 1, i + 1) && tot(i - 1, i + 1, i + 2));
        }
        ans = min(ans, h + v - cek + fix);
    }
    cout << ans << '\n';
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