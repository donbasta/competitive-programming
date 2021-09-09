#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
    cin >> n;
    vector<ll> ar(n), atas, bawah;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    sort (ar.begin(), ar.end());
    for (int i = 0; i < (n + 1) / 2; i++) {
        bawah.emplace_back(ar[i]);
    }
    reverse (bawah.begin(), bawah.end());
    for (int i = (n + 1) / 2; i < n; i++) {
        atas.emplace_back(ar[i]);
    }
    reverse (atas.begin(), atas.end());
    vector<ll> ans;
    for (int i = 0; i < n / 2; i++) {
        ans.emplace_back(bawah[i]);
        ans.emplace_back(atas[i]);
    }
    if (bawah.size() > atas.size()) ans.emplace_back(bawah.back());
    bool ok = true;
    for (int i = 1; i < n; i++) {
        if (i & 1) ok &= (ans[i] > ans[i - 1]);
        else ok &= (ans[i] < ans[i - 1]);
    }
    if (!ok) {
        cout << -1 << '\n';
    } else {
        for (auto& e : ans) {
            cout << e << ' ';
        }
        cout << '\n';
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