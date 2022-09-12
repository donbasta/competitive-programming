#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    vector<long long> ans;
    vector<bool> ve(n + 1);
    for (int i = 1; i <= n; i++) {
        if (ve[i]) continue;
        int j = i;
        while (j <= n) {
            ve[j] = true;
            ans.push_back(j);
            j *= 2;
        }
    }
    cout << 2 << '\n';
    for (auto e : ans) {
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