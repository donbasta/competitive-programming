#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    sort(ar.begin(), ar.end());
    if (n == 2) {
        cout << ar[0] << ' ' << ar[1] << '\n';
        return;
    }
    int mn = 2e9;
    int loc = -1;
    for (int i = 0; i < n - 1; i++) {
        if (ar[i + 1] - ar[i] < mn) {
            mn = ar[i + 1] - ar[i];
            loc = i;
        }
    }
    int cnt = 0;
    for (int j = loc + 1; cnt < n; j = (j + 1) % n) {
        cout << ar[j] << ' ';
        cnt++;
    }
    cout << '\n';
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