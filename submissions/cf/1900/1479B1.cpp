#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, seg;

void solve() {
    cin >> n;
    int last1 = 0, last2 = 0;
    for (int i = 0; i < n; i++) {
        int now;
        cin >> now;
        if (now != last1) {
            seg++;
            last1 = now;
        } else if (now != last2) {
            seg++;
            last2 = now;
        }
    }
    cout << seg << '\n';
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