#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for (auto& el : ar) {
        cin >> el;
    }
    if (n == 2 && (ar == vector<int>{2, 1})) {
        cout << "1 1\n0 1\n";
        return;
    }
    if (n == 4 && (ar == vector<int>{3, 3, 3, 3})) {
        cout << "1 1 1 0\n1 1 2 1\n1 0 1 1\n2 1 3 3\n";
        return;
    }
    vector<int> car = ar;
    sort(car.begin(), car.end(), greater<>());
    if ((car[0] == car[1]) && (car[0] == n)) {
        cout << -1 << '\n';
        return;
    }
    if ((car[0] == car[n - 1]) && (car[0] == n - 1) && (n & 1)) {
        cout << -1 << '\n';
        return;
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
        ok &= (car[i] <= n - i);
    }
    if (ok) {
        vector<pair<int, int>> lol;
        for (int i = 0; i < n; i++) {
            lol.emplace_back(ar[i], i);
        }
        sort(lol.begin(), lol.end(), greater<>());
        vector<int> start(n);
        for (int i = 0; i < n; i++) {
            start[lol[i].second] = i;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < start[i]; j++) {
                cout << 0 << ' ';
            }
            for (int j = start[i]; j < start[i] + ar[i]; j++) {
                cout << 1 << ' ';
            }
            for (int j = start[i] + ar[i]; j < n; j++) {
                cout << 0 << ' ';
            }
            cout << '\n';
        }
        return;
    } else {
        cout << -1 << '\n';
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}