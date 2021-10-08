#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    vector<int> a(6), b(6);
    for (int i = 0; i < 6; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 6; i++) {
        cin >> b[i];
    }
    int ans = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            ans += (a[i] > b[j]);
        }
    }
    int fpb = __gcd(ans, 36);
    int num = ans / fpb;
    int den = 36 / fpb;
    cout << num << '/' << den << '\n';
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