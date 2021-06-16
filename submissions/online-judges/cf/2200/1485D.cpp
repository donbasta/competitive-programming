#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, m;

void solve() {
    cin >> n >> m;
    vector<vector<int>> ar(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ar[i][j];
        }
    }   
    int lcm = 16 * 9 * 5 * 7 * 11 * 13;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int cek = (i + j) & 1;
            if (cek) {
                cout << lcm;
            } else {
                cout << lcm + (ar[i][j] * ar[i][j] * ar[i][j] * ar[i][j]); 
            }
            cout << ' ';
        }
        cout << '\n';
    }
    return;
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