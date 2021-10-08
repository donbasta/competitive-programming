#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, x;

void solve() {
    cin >> n >> x;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    vector<int> car = ar;
    sort(car.begin(), car.end());
    bool sorted = (car == ar);
    if (sorted) {
        cout << "YES" << '\n';
        return;
    }
    if (n == x && !sorted) {
        cout << "NO" << '\n';
        return;
    }
    if (n >= 2 * x) {
        cout << "YES" << '\n';
        return;
    }
    int a = n - x + 1, b = x;
    bool ok = true;
    for (int i = a; i <= b; i++) {
        ok &= (ar[i - 1] == car[i - 1]);
    }
    cout << (ok ? "YES" : "NO") << '\n';
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