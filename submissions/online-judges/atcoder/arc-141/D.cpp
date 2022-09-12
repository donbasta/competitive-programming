#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int M = 3e5;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<bool> ve(M + 5);
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ar[i] = x;
        ve[x] = true;
    }
    vector<vector<int>> buc(m);
    bool imp = false;
    for (int i = 1; i < 2 * m; i += 2) {
        int a = i;
        while (a <= 2 * m) {
            if (ve[a]) {
                buc[i / 2].push_back(a);
            }
            a >>= 1;
        }
        if (buc[i / 2].empty()) {
            imp = true;
        }
    }
    if (imp) {
        for (int i = 0; i < n; i++) {
            cout << "No" << '\n';
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        
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