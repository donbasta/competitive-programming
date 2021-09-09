#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, q;
string s;

void solve() {
    cin >> n >> q;
    cin >> s;
    vector<vector<int>> sum(n + 1, vector<int>(2));
    for (int i = 1; i <= n; i++) {
        sum[i][0] = sum[i - 1][0];
        sum[i][1] = sum[i - 1][1];
        int cur = (s[i - 1] == '+' ? 1 : -1);
        sum[i][i & 1] += cur;
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int cnt = r - l + 1;
        if (cnt & 1) {
            cout << 1;
        } else {
            int A = sum[r][0] - sum[l - 1][0];
            int B = sum[r][1] - sum[l - 1][1];
            if (A == B) {
                cout << 0;
            } else {
                cout << 2;
            }
        }
        cout << '\n';
    }
    return;
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