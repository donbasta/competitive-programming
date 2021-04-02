#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e5;

int n, start;
int a[N + 5];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int last = n;
    vector<int> ve = {n};
    vector<bool> udah(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        udah[a[i]] = 1;
        if (a[i] == last) {
            ve.push_back(i);
            while (last && udah[last]) last--;
        }
    }
    for (int i = 1; i < (int)ve.size(); i++) {
        for (int j = ve[i]; j < ve[i - 1]; j++) {
            cout << a[j] << ' ';
        }
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