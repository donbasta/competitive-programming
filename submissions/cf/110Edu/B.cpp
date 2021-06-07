#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
    cin >> n;
    vector<int> odd, even;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x & 1) { odd.emplace_back(x); }
        else { even.emplace_back(x); }
    }
    int a = (int) odd.size();
    int b = (int) even.size();
    ll ans = (1LL * b * (b - 1 + (a * 2))) / 2;
    for (int i = 0; i < a; i++) {
        for (int j = i + 1; j < a; j++) {
            if (__gcd(odd[i], odd[j]) > 1) ans++;
        }
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