#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<ll> ar(n);
    int mx = -INF, idx = -1;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    for (int i = 0; i + 1 < n; i++) {
        if (min(ar[i], ar[i + 1]) > 0) {
            cout << "NO" << '\n';
            return;
        }
    }
    if (mx <= 0) {
        cout << "YES" << '\n';
        return;
    }
    vector<ll> mmx(2);
    int j;
    for (int xx = 0; xx < 2; xx++) {
        for (int i = 0; i < n; i = j) {
            if (ar[i] > 0) {
                ll tmp = ar[i];
                j = i + 1;
                while (j < n && ar[j] <= 0) {
                    tmp += ar[j];
                    j++;
                }
                if (j < n) {
                    mmx[xx] = max(mmx[xx], tmp);
                }
            } else {
                j = i + 1;
            }
        }
        reverse(ar.begin(), ar.end());
    }
    cout << (mmx[0] + mmx[1] > 0 ? "NO" : "YES") << '\n';
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