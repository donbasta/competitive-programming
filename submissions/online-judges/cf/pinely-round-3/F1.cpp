#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;
const ll MOD = 998244353;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> ar(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    for (int i = 1; i <= n; i++) {
        if (ar[i] > i) {
            cout << 0 << '\n';
            return;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (ar[i] < ar[i - 1] || ar[i] > ar[i - 1] + 2) {
            cout << 0 << '\n';
            return;
        }
    }
    if (ar[n] != n) {
        cout << 0 << '\n';
        return;
    }
    ll ans = 1;
    int oth = 0, emp = 0;
    if (ar[1] == 0) {
        oth++, emp++;
    }
    for (int i = 2; i <= n; i++) {
        int dif = ar[i] - ar[i - 1];
        if (dif == 0) {
            oth++;
            emp++;
        } else if (dif == 1) {
            ans = (ans * (oth + emp + 1)) % MOD;
        } else if (dif == 2) {
            ans = (ans * emp) % MOD;
            emp--;
            ans = (ans * oth) % MOD;
            oth--;
        }
    }
    cout << ans << '\n';
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