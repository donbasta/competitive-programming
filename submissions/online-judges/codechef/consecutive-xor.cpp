#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> ar(n);
    int ks = 0;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        ks ^= ar[i];
    }
    if ((n % 2 == 0) && (ks != 0)) {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
    int val = ks;
    for (int i = 0; i < n - 1; i++) {
        int need = val ^ ar[i];
        ar[i] ^= need;
        ar[i + 1] ^= need;
    }
    assert(ar[n - 1] == val);
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