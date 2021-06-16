#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 100;

int n, m;
int ar[N + 5][N + 5];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ar[i][j];
            if ((ar[i][j] % 2) != ((i + j) % 2)) {
                ar[i][j]++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ar[i][j] << ' ';
        }
        cout << '\n';
    }
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