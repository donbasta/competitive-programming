#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
    cin >> n;
    vector<int> ar(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    if (ar[1] == 1) {
        cout << n + 1 << ' ';
        for (int i = 1; i <= n; i++) {
            cout << i << ' ';
        }
    } else if (ar[n] == 0) {
        for (int i = 1; i <= n; i++) {
            cout << i << ' ';
        }
        cout << n + 1 << ' ';
    } else {
        int cut = -1;
        for (int i = 1; i < n; i++) {
            if (ar[i] == 0 && ar[i + 1] == 1) {
                cut = i;
                break;
            }
        }
        assert(cut != -1);
        for (int i = 1; i <= cut; i++) {
            cout << i << ' ';
        }
        cout << n + 1 << ' ';
        for (int i = cut + 1; i <= n; i++) {
            cout << i << ' ';
        }
    }
    cout << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}