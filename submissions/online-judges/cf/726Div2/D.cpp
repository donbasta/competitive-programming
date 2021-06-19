#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
    cin >> n;
    int lose = 0;
    if (n & 1) {
        lose = 1;
    } else {
        int pw = 0;
        while (n % 2 == 0) {
            n /= 2, pw++;
        }
        if (n == 1 && (pw & 1)) {
            lose = 1;
        }
    }
    cout << (lose ? "Bob" : "Alice") << '\n';
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