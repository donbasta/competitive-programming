#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int INF = 2e9;
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> ar(n), le(n + 1), re(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    for (int i = 1; i < n; i++) {
        le[i] = le[i - 1] + max(0LL, ar[i - 1] - ar[i]);
    }
    for (int i = n - 1; i > 0; i--) {
        re[i] = re[i + 1] + max(0LL, ar[i] - ar[i - 1]);
    }
    while (m--) {
        int s, t;
        cin >> s >> t;
        --s, --t;
        ll damage;
        if (s < t) {
            damage = le[t] - le[s];
        } else if (s > t) {
            damage = re[t + 1] - re[s + 1];
        }
        cout << damage << '\n';
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
