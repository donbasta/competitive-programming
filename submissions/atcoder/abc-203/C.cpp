#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;
ll k;

void solve() {
    cin >> n >> k;
    vector<pair<ll, ll>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    sort (p.begin(), p.end());
    ll sisa = k;
    ll last = 0;
    for (int i = 0; i < n; i++) {
        if (sisa < p[i].first - last) {
            cout << last + sisa << '\n';
            return;
        }
        sisa -= (p[i].first - last);
        sisa += (p[i].second);
        last = p[i].first;
    }
    cout << last + sisa << '\n';
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