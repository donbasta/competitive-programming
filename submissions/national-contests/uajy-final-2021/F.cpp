#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int x, y, z, x_1, y_1, x_2, y_2, j;

void solve() {
    cin >> x >> y >> z >> x_1 >> y_1 >> x_2 >> y_2 >> j;
    bool flag = (j >= z);
    cout << (flag ? "tembak" : "tahan") << '\n';
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