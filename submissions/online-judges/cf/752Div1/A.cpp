#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

vector<ll> LCM;
const ll MX = 1e9;
int sz;

ll lcm(ll a, ll b) {
    return a * (b / __gcd(a, b));
}

void init() {
    ll now = 2;
    ll i = 3;
    while (now <= MX) {
        LCM.push_back(now);
        now = lcm(now, i++);
    }
    sz = (int) LCM.size();
}

void solve() {
    int n;
    cin >> n;
    vector<ll> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    for (int i = 0; i < min(sz, n); i++) {
        if (ar[i] % LCM[i] == 0) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    init();

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}