#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    vector<int> R, B, W;
    int r = 0, b = 0, w = 0;
    if (n <= 5) {
        cout << "No" << '\n';
        return;
    }
    if (n % 3 == 2) {
        cout << "No" << '\n';
        return;
    }
    int mx = n * (n - 1) / 6;
    for (int i = n - 1; i >= 1; i--) {
        if (r + i <= mx) {
            r += i, R.push_back(n - i);
        } else if (b + i <= mx) {
            b += i, B.push_back(n - i);
        } else if (w + i <= mx) {
            w += i, W.push_back(n - i);
        } else {
            cout << "No" << '\n';
            return;
        }
    }
    cout << "Yes" << '\n';
    vector<vector<char>> ve(n + 1, vector<char>(n + 1));
    for (auto e : R) {
        for (int i = e + 1; i <= n; i++) {
            ve[e][i] = 'R';
        }
    }
    for (auto e : W) {
        for (int i = e + 1; i <= n; i++) {
            ve[e][i] = 'W';
        }
    }
    for (auto e : B) {
        for (int i = e + 1; i <= n; i++) {
            ve[e][i] = 'B';
        }
    }
    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            cout << ve[i][j];
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