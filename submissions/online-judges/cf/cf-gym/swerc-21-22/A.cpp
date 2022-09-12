#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    vector<int> ve(10, -1);
    for (int i = 0; i < n; i++) {
        int b, d;
        cin >> b >> d;
        --d;
        ve[d] = max(ve[d], b);
    }
    int tot = 0;
    for (int i = 0; i < 10; i++) {
        if (ve[i] == -1) {
            cout << "MOREPROBLEMS" << '\n';
            return;
        }
        tot += ve[i];
    }
    cout << tot << '\n';
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