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
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    auto check = [&]() -> bool {
        if (n == 1) return false;
        bool ok = n % 2 == 0;
        int x = ar[0], y = ar[1];
        for (int i = 2; i < n; i += 2) {
            ok &= (ar[i] == x);
        }
        for (int i = 3; i < n; i += 2) {
            ok &= (ar[i] == y);
        }
        return ok;
    };
    if (check()) {
        cout << (n / 2) + 1 << '\n';
    } else {
        cout << n << '\n';
    }
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