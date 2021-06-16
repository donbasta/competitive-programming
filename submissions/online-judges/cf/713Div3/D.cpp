#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
    cin >> n;
    vector<ll> b(n + 2);
    map<ll, int> ada;
    for (int i = 0; i < n + 2; i++) {
        cin >> b[i];
        ada[b[i]]++;
    } 
    sort(b.begin(), b.end());
    ll tmp = 0;
    for (int i = 0; i < n; i++) {
        tmp += b[i];
    }
    if (tmp == b[n]) {
        for (int i = 0; i < n; i++) {
            cout << b[i] << ' ';
        }
        cout << '\n';
        return;
    }
    tmp += b[n];
    ll r = tmp - b[n + 1];
    if (ada.find(r) == ada.end()) {
        cout << -1 << '\n';
        return;
    }
    if (r == b[n + 1] && ada[r] == 1) {
        cout << -1 << '\n';
        return;
    }
    bool blm = true;
    for (int i = 0; i < n + 1; i++) {
        if (blm && b[i] == r) {
            blm = false;
            continue;
        }
        cout << b[i] << ' ';
    }
    cout << '\n';
    return;
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