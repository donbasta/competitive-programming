#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
    cin >> n;
    vector<int> ar(n);
    map<int, int> pa, pb;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i & 1) pa[x]++;
        else pb[x]++;
        ar[i] = x;
    }
    sort(ar.begin(), ar.end());
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            pa[ar[i]]--;
        } else {
            pb[ar[i]]--;
        }
    }
    for (int i = 0; i < n; i++) {
        if ((pa[ar[i]] != 0) || (pb[ar[i]] != 0)) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
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