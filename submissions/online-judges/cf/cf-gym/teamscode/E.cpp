#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int M = 1000;
int n;

void solve() {
    cin >> n;
    vector<int> occ(M + 1), ve;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        ve.emplace_back(k);
        occ[k]++;
        sum += k;
    }
    sort(ve.begin(), ve.end());
    int mean = sum / n;
    int median = (ve[n / 2] + ve[(n - 1) / 2]) / 2;
    int mode = 0;
    int mx = 0;
    for (int i = 1; i <= M; i++) {
        if (occ[i] >= mx) {
            mode = i, mx = occ[i];
        }
    }
    cout << mean << '\n';
    cout << median << '\n';
    cout << mode << '\n';
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