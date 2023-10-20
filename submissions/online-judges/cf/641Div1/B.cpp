#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> ar(n);
    bool ada = false;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        if (ar[i] == k) ada = true;
    }
    if (n == 1) {
        if (ar[0] != k) {
            cout << "no" << '\n';
        } else {
            cout << "yes" << '\n';
        }
        return;
    }
    if (n == 2) {
        if (min(ar[0], ar[1]) != k) {
            cout << "no" << '\n';
        } else {
            cout << "yes" << '\n';
        }
        return;
    }
    if (!ada) {
        cout << "no" << '\n';
        return;
    }
    int last = -1;
    for (int i = 0; i < n; i++) {
        if (ar[i] < k) continue;
        if (last == -1)
            last = i;
        else {
            if (i - last <= 2) {
                cout << "yes" << '\n';
                return;
            }
            last = i;
        }
    }
    cout << "no" << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}