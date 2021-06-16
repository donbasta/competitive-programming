#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2005;
int ar[N + 5];

int n;

void solve() {
    cin >> n;
    int xr = 0;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        xr ^= ar[i];
    }
    if (xr == 0) {
        cout << "YES\n";
        return;
    }
    int cxr = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cxr ^= ar[i];
        if (cxr == xr) {
            cnt++;
            cxr = 0;
        }
    }
    bool ans = (cnt > 1);
    cout << (ans ? "YES" : "NO") << '\n';
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