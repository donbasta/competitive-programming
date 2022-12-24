#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    string C;
    cin >> n >> C;
    int dif = 0;
    for (int i = 0; i < n; i++) {
        if (C[i] == 'A')
            dif++;
        else
            dif--;
    }
    dif = abs(dif);
    cout << (dif == 1 ? 'Y' : 'N') << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}