#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

using mat = array<array<int, 2>, 2>;

void el_psy_congroo() {
    mat X;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << i << ' ' << j << ' ' << X[i][69] << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}