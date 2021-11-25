#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for (auto& e : ar) {
        cin >> e;
    }
    int a = 1, b = 2, c = 3;
    for (int i = 0; i < n; i++) {
        int winner = ar[i];
        if (winner != a && winner != b) {
            cout << "NO" << '\n';
            return;
        }
        int loser = (a == winner ? b : a);
        a = winner, b = c, c = loser;
    }
    cout << "YES" << '\n';
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