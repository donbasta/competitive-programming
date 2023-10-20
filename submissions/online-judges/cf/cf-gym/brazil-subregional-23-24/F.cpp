#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int d, c, r;
    cin >> d >> c >> r;
    vector<int> C(c), R(r);
    for (int i = 0; i < c; i++) {
        cin >> C[i];
    }
    for (int i = 0; i < r; i++) {
        cin >> R[i];
    }
    int i = 0, j = 0;
    while (i < c || j < r) {
        if (i < c && C[i] <= d) {
            d -= C[i];
            i++;
        } else if (i >= c) {
            d += R[j];
            j++;
        } else if (C[i] > d) {
            if (j >= r) {
                break;
            } else {
                d += R[j];
                j++;
            }
        }
    }
    int ans = (i + j);
    cout << ans << '\n';
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