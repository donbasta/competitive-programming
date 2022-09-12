#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1), rev(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        rev[p[i]] = i;
    }
    vector<int> q(n + 1);
    q[1] = 1;
    for (int i = 2; i <= n; i++) {
        q[i] = rev[i];
    }
    for (int i = 1; i <= n; i++) {
        q[1] = i;
        for (int j = 2; j <= n; j++) {
            //p[q[j]] = q[j-1]
            //q[j] = rev[q[j-1]]
            q[j] = rev[q[j - 1]];
        }
        if (q[1] = rev[q[n]]) {
            for (int j = 1; j <= n; j++) {
                cout << q[j] << ' ';
            }
            cout << '\n';
            return;
        }
    }
    assert(false);
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