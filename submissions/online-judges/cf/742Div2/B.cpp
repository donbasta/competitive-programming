#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int M = 3e5;
int pre[M + 5];

void solve() {
    int a, b;
    cin >> a >> b;
    if (pre[a - 1] == b) {
        cout << a << '\n';
    } else if ((b ^ pre[a - 1]) == a) {
        cout << a + 2 << '\n';
    } else {
        cout << a + 1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int i = 1; i <= M; i++) {
        pre[i] = pre[i - 1] ^ i;
    }

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}