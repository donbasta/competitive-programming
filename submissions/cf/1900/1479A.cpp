#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 1e9;
const int N = 1e5;

int ar[N + 5];
int n, l, r;

int ask(int q) {
    if (q == 0 || q == n + 1) {
        return INF;
    }
    if (ar[q] != -1) {
        return ar[q];
    }
    int ret;
    cout << "? " << q << endl;
    cin >> ret;
    ar[q] = ret;
    return ret;
}

array<int, 3> query(int q1, int q2, int q3) {
    array<int, 3> ret;
    ret[0] = ask(q1);
    ret[1] = ask(q2);
    ret[2] = ask(q3);
    return ret;
}

void solve() {
    memset(ar, -1, sizeof(ar));
    cin >> n;
    l = 0, r = n + 1;
    while (r - l > 2) {
        int q1, q2, q3;
        q1 = (3 * l + r) / 4;
        q2 = (l + r) / 2;
        q3 = (l + 3 * r) / 4;
        array<int, 3> ar = query(q1, q2, q3);
        if (ar[1] < ar[0] && ar[2] > ar[1]) {
            l = q1, r = q3;
        } else if (ar[1] < ar[0] && ar[2] < ar[1]) {
            l = q2;
        } else {
            r = q2;
        }
    }
    int ans = (l + r) / 2;
    cout << "! " << ans << '\n';
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