#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int B = 450;

void solve() {
    int n;
    cin >> n;
    string b;
    cin >> b;
    int q;
    cin >> q;
    vector<vector<int>> ar(B + 1);
    for (int i = 1; i <= B; i++) {
        ar[i].resize(i);
        for (int j = 0; j < n; j++) {
            ar[i][j % i] += (b[j] == '0');
        }
    }
    for (int i = 0; i < q; i++) {
        int type, x, k;
        cin >> type >> x;
        --x;
        if (type == 1) {
            b[x] = '1';
            for (int i = 1; i <= B; i++) {
                ar[i][x % i]--;
            }
        } else if (type == 2) {
            b[x] = '0';
            for (int i = 1; i <= B; i++) {
                ar[i][x % i]++;
            }
        } else if (type == 3) {
            cin >> k;
            int ans = 0;
            if (k <= B) {
                ans = ar[k][x];
            } else {
                for (int i = x; i < n; i += k) {
                    ans += (b[i] == '0');
                }
            }
            cout << ans << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}