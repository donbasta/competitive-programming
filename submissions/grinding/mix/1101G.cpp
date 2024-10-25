#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 69;
const int LOGN = 32;  // bit

int n, ans;
int ar[N], pre[N];
vector<int> basis;

void addBasis(int x) {
    for (int i = LOGN - 1; i >= 0; i--) {
        if (basis[i] != -1 && ((x >> i) & 1)) {
            x ^= basis[i];
        }
    }
    if (x == 0)
        return;
    for (int i = LOGN - 1; i >= 0; i--) {
        if (basis[i] == -1 && ((x >> i) & 1)) {
            basis[i] = x;
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    basis.assign(LOGN, -1);
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        pre[i] = ar[i] ^ pre[i - 1];
        addBasis(pre[i]);
    }
    if (pre[n] == 0) {
        cout << -1 << "\n";
        return 0;
    }
    for (auto i : basis) {
        if (i != -1) {
            ans++;
        }
    }
    cout << ans << "\n";
}
