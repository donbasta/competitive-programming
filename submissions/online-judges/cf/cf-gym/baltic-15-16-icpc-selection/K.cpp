#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int ar[] = {13, 14, 15, 17, 18, 19};
const int br[] = {11, 7, 5, 3, 2};
const int M = 20;
ll fc[M + 5];

void init() {
    fc[2] = 2;
    for (int i = 3; i <= M; i++) {
        fc[i] = fc[i - 1] * i;
    }
}

void solve () {
    ll n;
    cin >> n;
    for (int i = 0; i < 6; i++) {
        ll m = n;
        if (n % fc[ar[i]] == 0) {
            m /= fc[ar[i]];
        }
        for (int j = 0; j < 5; j++) {
            while (m % fc[br[j]] == 0) {
                m /= fc[br[j]];
            }
        }
        if (m == 1LL) {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
    return;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    init();

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve ();
    }

    return 0;
}