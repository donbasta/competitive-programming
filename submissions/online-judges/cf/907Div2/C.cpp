#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<ll> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    sort(ar.begin(), ar.end());
    int i = 0, j = n - 1;
    ll cur = 0;
    ll T = 0;
    while (i < j && cur < ar[j]) {
        if (cur + ar[i] >= ar[j]) {
            T += (ar[j] - cur);
            ar[i] -= (ar[j] - cur);
            T++;
            j--;
            if (ar[i] == 0) {
                i++;
            }
            cur = 0;
        } else {
            T += ar[i];
            cur += ar[i];
            i++;
        }
        // cerr << i << ' ' << j << ' ' << cur << ' ' << T << '\n';
    }
    if (i == j) {
        int sisa = (ar[j] % 2 != cur % 2);
        T += min((ar[j] - cur) / 2 + 1 + (sisa), ar[j]);
    }
    cout << T << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}