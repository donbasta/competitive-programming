#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int INF = 2e9;
 
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int id = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[0]) {
            id = i;
        }
    }
    assert(id != -1);
    bool ok = true;
    for (int i = 0; i < n; i++) {
        ok &= (b[i] == a[id]);
        id = (id + 1) % n;
    }
    bool ans = ok;
    if (n == 2) {
        if (k % 2 == 1) {
            ans &= (id == 1);
        } else {
            ans &= (id == 0);
        }
    } else if (k == 0) {
        ans &= (id == 0);
    } else if (k == 1) {
        ans &= (id != 0);
    }
    cout << (ans ? "YES" : "NO") << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
