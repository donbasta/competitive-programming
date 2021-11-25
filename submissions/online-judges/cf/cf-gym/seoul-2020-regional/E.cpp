#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    vector<int> ar(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    if (ar[1] > 1) {
        cout << "NO" << '\n';
        return;
    }  
    vector<int> r1, r2;
    if (ar[1] == 0) {
        r1.push_back(1), r2.push_back(1);
    } else {
        r1.push_back(1), r2.push_back(0);
    }
    for (int i = 2; i < n; i++) {
        int m1 = r1.back(), m2 = r2.back();
        int n1, n2;
        if (ar[i] == 0) {
            if (m1 == m2) {
                n1 = n2 = 1;
            } else if (m1 == 1) {
                n1 = 0, n2 = 1;
            } else if (m2 == 1) {
                n1 = 1, n2 = 0;
            }
        } else if (ar[i] == 1) {
            if (m1 == m2) {
                n1 = 1, n2 = 0;
            } else {
                n1 = n2 = 1;
            }
        } else if (ar[i] == 2) {
            if (m1 == m2) {
                cout << "NO" << '\n';
                return;
            } else if (m1 == 1) {
                n1 = 1, n2 = 0;
            } else if (m2 == 1) {
                n1 = 0, n2 = 1;
            }
        } else {
            cout << "NO" << '\n';
            return;
        }
        r1.push_back(n1), r2.push_back(n2);
    }
    if (r1.back() == r2.back() && ar[n] != 0) {
        cout << "NO" << '\n';
        return;
    }
    if (r1.back() != r2.back() && ar[n] != 1) {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
    return;
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