#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    if (n & 1) {
        cout << "NO" << '\n';
        return;
    }
    sort (ar.begin(), ar.end());
    vector<int> br;
    for (int i = 0; i < (n / 2); i++) {
        br.emplace_back(ar[i]);
        br.emplace_back(ar[i + (n / 2)]);
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
        int nx = (i + 1) % n, prv = (i + n - 1) % n;
        if (i % 2 == 0) {
            ok &= ((br[i] < br[prv]) && (br[i] < br[nx]));
        } else {
            ok &= ((br[i] > br[prv]) && (br[i] > br[nx]));
        }
    }
    if (!ok) {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
    for (auto e : br) {
        cout << e << ' ';
    }
    cout << '\n';
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