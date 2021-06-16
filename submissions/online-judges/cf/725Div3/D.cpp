#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int a, b, k;

int cnt(int x) {
    int cx = x;
    int ans = 0;
    for (int i = 2; i * i <= cx; i++) {
        while (cx % i == 0) {
            cx /= i, ans++;
        }    
    }
    if (cx > 1) ans++;
    return ans;
}

void solve() {
    cin >> a >> b >> k;
    int mn;
    int af = cnt(a), bf = cnt(b);

    if (a == b) {
        bool flag = (k != 1 && k <= af + bf);
        cout << (flag ? "Yes" : "No") << '\n';
        return;
    }
    if (a < b) swap(a, b);
    if (a % b == 0) mn = 1;
    else mn = 2;
    
    bool flag = (k >= mn && k <= af + bf);
    cout << (flag ? "Yes" : "No") << '\n';
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