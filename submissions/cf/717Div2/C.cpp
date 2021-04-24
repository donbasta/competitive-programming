#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 100;
const int MX = 2e3;

int ar[N + 5];
int n;
bool bisa[N * MX + 5];

int v2(int x) {
    int ret = 0;
    while (x % 2 == 0) { ret++; x >>= 1; }
    return ret;
}

void solve() {
    cin >> n;
    int mx = 2000;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        mx = min(mx, v2(ar[i]));
    }
    int pw = (1 << mx);
    int sum = 0;
    int idx_odd = -1;
    int idx_even = -1;
    for (int i = 1; i <= n; i++) {
        ar[i] /= pw;
        if (ar[i] % 2 == 0) idx_even = i;
        else idx_odd = i;
        sum += ar[i];
    }
    if (sum % 2 == 0) {
        bisa[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = i * MX; j >= 0; j--) {
                if (bisa[j]) bisa[j + ar[i]] = true;
            }
        }
        if (!bisa[sum / 2]) {
            cout << 0 << '\n';
            return;
        }
        cout << 1 << '\n';
        cout << idx_odd << '\n';
        return;
    }
    if (sum % 2 == 1) {
        cout << 0 << '\n';
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